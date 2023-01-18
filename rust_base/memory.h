#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <vector>

uintptr_t get_base_address(const char* base_address)
{
	return true;
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