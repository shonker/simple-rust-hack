#include "misc.h"
// // // // // // // //
bool adminmode = false;
// // // // // // // //

int main() 
{
	auto process = get_process_id("RustClient.exe");
	if (process) {
		auto assembly_base_address = get_base_address("GameAssembly.dll");
		auto assembly_base_offsets = memory::read<uintptr_t>(assembly_base_address + 56564432);
		auto assembly_main_offsets = memory::read_chain<uintptr_t>(assembly_base_offsets, { 0xb8, 0x0, 0x10, 0x28 });
		while (true)
		{
			if (adminmode) {
				int flag = memory::read<int>(assembly_main_offsets + 0x690);
				memory::write<int>(0x690, (flag |= 4));
			}
		}
	}
}
