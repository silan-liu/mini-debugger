#include <vector>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <sys/personality.h>

#include "linenoise.h"
#include "debugger.hpp"
#include "registers.hpp"

using namespace minidebugger;

std::vector<std::string> split(const std::string &s, char delimiter) {
	std::vector<std::string> out{};
	std::stringstream ss {s};
	std::string item;

	while (std::getline(ss, item, delimiter)) {
		out.push_back(item);
	}

	return out;
}

// of 以 s 为前缀
bool is_prefix(const std::string& s, const std::string& of) {
	if (s.size() > of.size())  {
		return false;
	}

	return std::equal(s.begin(), s.end(), of.begin());
}

void debugger::handle_command(const std::string& line) {
	auto args = split(line, ' ');
	auto command = args[0];

	if (is_prefix(command, "cont")) {
		continue_execution();
	} else if (is_prefix(command, "breakpoint")) {
		std::string addr {args[1], 2};
		set_breakpoint_at_address(std::stol(addr, 0, 16));
	} else if (is_prefix(command, "registers")) {
		if (is_prefix(args[1], "dump")) {
			dump_registers();
		}
	} else {
		std::cerr << "Unknown command\n";
	}
}

void debugger::run() {
	int wait_status;
	auto options = 0;

	// 等待子进程状态变化，这里也就是暂停。被追踪的程序启动完成，会收到 SIGTRAP 信号，暂停
	waitpid(m_pid, &wait_status, options);
	
        std::cout << "debugger waitpid status: " << wait_status << "; if stopped:" << WIFSTOPPED(wait_status) << "\n";

	char *line = nullptr;
	while((line = linenoise("minidebugger> ")) != nullptr) {
		handle_command(line);
		linenoiseHistoryAdd(line);
		linenoiseFree(line);
	}
}

void debugger::continue_execution() {

	ptrace(PTRACE_CONT, m_pid, nullptr, nullptr);
	
	int wait_status;
	auto options = 0;

	// 等待子进程状态变化，这里是退出
	waitpid(m_pid, &wait_status, options);

        std::cout << "continue_execution  waitpid status: " << wait_status << "; if exited:" << WIFEXITED(wait_status) << "\n";

}

void debugger::set_breakpoint_at_address(std::intptr_t addr) {
	std::cout << "set breakpoint at address 0x" << std::hex << addr << std::endl;
	breakpoint bp {m_pid, addr};
	bp.enable();
	m_breakpoints[addr] = bp;
}

void debugger::dump_registers() {
	get_register_value(m_pid);	
}

void execute_debugee(const std::string& prog_name) {
	// 允许父进程可对其进行跟踪
	if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
		std::cerr << "Error in patrace\n";
		return;
	}

	execl(prog_name.c_str(), prog_name.c_str(), nullptr);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cerr << "Program name not specified";
		return -1;
	}

	auto prog = argv[1];

	auto pid = fork();
	if (pid == 0) {
		personality(ADDR_NO_RANDOMIZE);

		// child，执行被 debug 的程序
		execute_debugee(prog);
	} else if (pid > 0) {
		// parent
		std::cout << "Started debugging process " << pid << "\n";
		debugger dbg{prog, pid};
		dbg.run();
	}
}
