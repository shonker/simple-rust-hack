#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <TlHelp32.h>
#include <memory>
#include <string_view>
#include <chrono>
#include <vector>

std::uint32_t get_process_id(const std::string& name)
{
	const auto snp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snp == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 entry{};
	entry.dwSize = sizeof entry;

	auto found_process = false;
	if (!!Process32First(snp, &entry)) {
		do {
			if (name == entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!Process32Next(snp, &entry));
	}

	CloseHandle(snp);
	return found_process ? entry.th32ProcessID: 0;
}

uintptr_t get_base_address(const char* base_address)
{
	// your base_addr function 
	return NULL;
}

namespace memory {

	template <typename T>
	T read(const uintptr_t address)
	{
		T buffer{ };
		// your reading function
		return buffer;
	}

	template <typename t>
	t read_chain(uintptr_t address, std::vector<uintptr_t> chain)
	{
		uintptr_t cur_read = address;

		for (int i = 0; i < chain.size() - 1; ++i)
			cur_read = read<uintptr_t>(cur_read + chain[i]);

		return read<t>(cur_read + chain[chain.size() - 1]);
	}

	template <typename T>
	void write(const uintptr_t address, const T& buffer)
	{
		// your write function 
	}

}
