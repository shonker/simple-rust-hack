#include "misc.h"
#include "offsets.h"

int main() {
	auto process = get_process_id("RustClient.exe");
	if (process) {
		        auto assembly_base_addr = get_base_address("GameAssembly.dll"); 
			auto localplayer1 = memory::read<uintptr_t>(assembly_base_addr + basenetworkable);
			auto localplayer2 = memory::read<uintptr_t>(localplayer1 + 0xB8);
			auto localplayer3 = memory::read<uintptr_t>(localplayer2 + 0x0);
			auto localplayer4 = memory::read<uintptr_t>(localplayer3 + 0x10);
			auto localplayer5 = memory::read<uintptr_t>(localplayer4 + 0x28);
			auto localplayer6 = memory::read<uintptr_t>(localplayer5 + 0x18);
			auto localplayer7 = memory::read<uintptr_t>(localplayer6 + 0x20);
		        while (true) {
			int flag = memory::read<int>(localplayer7 + playerflags);
			memory::write<int>(playerflags, (flag |= admin));
		}
	}
}
