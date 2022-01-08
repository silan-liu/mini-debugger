#ifndef MINI_DEBUGGER_BREAKPOINT_HPP
#define MINI_DEBUGGER_BREAKPOINT_HPP

#include <cstdint>
#include <sys/ptrace.h>
#include <iostream>

namespace minidebugger {
	class breakpoint {
		public:
			breakpoint() = default;
			breakpoint(pid_t pid, std::intptr_t addr) : m_pid{pid}, m_addr{addr}, m_enabled{false}, m_saved_data{} {}
			void enable() {
				std::cout << "enable breakpoint:" << m_addr << std::endl;

				// 获取当前地址的数据
				auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_addr, nullptr);

				std::cout << "orgin data:" << std::hex << data << std::endl;

				// 保存最低 8 字节数据，
				m_saved_data = data & 0xff;


				std::cout << "save data:" << m_saved_data << std::endl;
				
				uint64_t int3 = 0xcc;

				// 清除低 8 位数据
				uint64_t cleared_data = data & ~0xff;

				// 用 0xcc 替换低 8 位
				uint64_t replaced_data = cleared_data | int3;
				
				std::cout << "replaced_data:" << std::hex << replaced_data << std::endl;

				// 设置新数据
				ptrace(PTRACE_POKEDATA, m_pid, m_addr, replaced_data);

				m_enabled = true;
			}

			void disable() {
				std::cout << "disable breakpoint:" << m_addr << std::endl;

				// 将低 8 位数据还原
				auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_addr, nullptr);

				std::cout << "saved data:" << std::hex << m_saved_data << std::endl;

				// 待还原数据
				auto restored_data = (data & ~0xff) | m_saved_data;

				std::cout << "orgin data:" << std::hex << restored_data << std::endl;
				
				// 设置数据
				ptrace(PTRACE_POKEDATA, m_pid, m_addr, restored_data);

				m_enabled = false;
			}

			bool is_enabled() const {
				return m_enabled;
			}

			auto get_address() const -> std::intptr_t {
				return m_addr;
			}

		private:
			pid_t m_pid;
			std::intptr_t m_addr;
			bool m_enabled;
			uint8_t m_saved_data;
	};
}
#endif
