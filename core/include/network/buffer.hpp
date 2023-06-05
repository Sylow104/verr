#pragma once
#include <stdint.h>
#include <stdlib.h>

// make this part modularable so that it can be reused in other instances
// make it so it is an interface, so other applications can use this same 
// library for elsewhere

enum buff_element_e
{
	NONE,
	BYTE,
	SHORT,
	INT,
	LONG,
	FLOAT,
	STRING,
	BIN
};

class buff_element_u
{
	public:
	size_t mod(buff_element_e type, void *src, size_t len);
	size_t size();
	buff_element_e type();

	private:
	uint8_t _type;
	union
	{
		struct
		{
			uint32_t len;
			uint8_t b;
		} binstr;
		uint8_t b;
	};
};

struct buff_u
{
	uint32_t op;
	uint64_t id;
	uint32_t body_len;
	uint32_t num_ele;
	uint8_t payload;
};