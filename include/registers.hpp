#ifndef MINI_DEBUGGER_REGISTERS_HPP
#define MINI_DEBUGGER_REGISTERS_HPP

#include <sys/user.h>
#include <algorithm>
#include <iostream>
#include <sys/ptrace.h>
#include <sys/uio.h>

namespace minidebugger {
	enum class reg {
		rbp, rsp
	};

	struct reg_descriptor {
		reg r;
		int dwarf_r;
		std::string name;
	};

	void get_register_value(pid_t pid) {
		user_regs_struct regs;

		ptrace(PTRACE_GETREGS, pid, nullptr, &regs);

		std::cout << "sp:" << std::hex <<  regs.sp << "; pc: " << std::hex << regs.pc << std::endl;
	}
}
#endif
