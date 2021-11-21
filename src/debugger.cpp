#include <vector>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>
#include <iostream>

#include "linenoise.h"
#include "debugger.hpp"

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
	} else {
		std::cerr << "Unknown command\n";
	}
}

void debugger::run() {
	int wait_status;
	auto options = 0;

	// 等待子进程执行完成，即被追踪的程序启动完成，会发送 SIGTRAP 信号
	waitpid(m_pid, &wait_status, options);

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

	// 等待 ptrace 发送信号
	waitpid(m_pid, &wait_status, options);
}

void execute_debugee(const std::string& prog_name) {
	// 允许父进程可对其 trace
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
		// child，执行被 debug 的程序
		execute_debugee(prog);
	} else if (pid > 0) {
		// parent
		std::cout << "Started debugging process " << pid << "\n";
		debugger dbg{prog, pid};
		dbg.run();
	}
}
