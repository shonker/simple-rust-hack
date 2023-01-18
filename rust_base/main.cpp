#include "memory.h"


#define localplayer_c 0x2e8b200 // LocalPlayer_c*
#define playerflags 0x688 // public BasePlayer.PlayerFlags playerFlags
#define adminflag 4 

bool adminmode = false;

auto check_localplayer() -> int {
	auto assembly_base_address = get_base_address("GameAssembly.dll");
	if (assembly_base_address == 0) { 
		std::cout << "base address not found.\n";
		std::cin.get();
		return 0;
	}
	else {
		while (true) {
			auto assembly_base_offsets = memory::read<uintptr_t>(assembly_base_address + localplayer_c);
			auto assembly_main_offsets = memory::read_chain<uintptr_t>(assembly_base_offsets, { 0xb8, 0x0, 0x10, 0x28 }); // new chain 
			if (adminmode) {
				memory::read<int>(assembly_main_offsets + playerflags);
				memory::write<int>(assembly_main_offsets + playerflags, adminflag);
			}
		}
	}
}

auto main() -> int
{
	auto windowHandle = FindWindowA("UnityWNDClass", "Rust");
	DWORD process_id;
	GetWindowThreadProcessId(windowHandle, &process_id);
	if (process_id) {
		check_localplayer();
	}
	else {
		return 0;
	}
}


