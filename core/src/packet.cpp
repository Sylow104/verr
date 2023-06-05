#include "network/packet.hpp"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BASE_SIZE 1024

struct packet_element_u
{
	uint8_t type;
	union
	{
		struct
		{
			uint32_t len;
			uint8_t b;
		} binstr;
		uint8_t b;
	};

	size_t size()
	{
		size_t to_ret = sizeof(uint8_t);
		switch(type) {
		case BYTE:
			to_ret += sizeof(uint8_t);
			break;
		case SHORT:
			to_ret += sizeof(uint16_t);
			break;
		case INT:
			to_ret += sizeof(uint32_t);
			break;
		case LONG:
			to_ret += sizeof(uint64_t);
			break;
		case FLOAT:
			to_ret += sizeof(float);
			break;
		case STRING:
		case BIN:
			to_ret += sizeof(uint32_t);
			to_ret += binstr.len;
			break;
		default:
			return NONE;
		}
		return to_ret;
	};
};

struct packet_buffer_u
{
	uint32_t op;
	uint64_t id;
	uint32_t body_len;
	uint32_t num_ele;
	uint8_t start;
};

packet_c::packet_c(uint32_t op, uint64_t id, size_t block_n)
{
	size_t packet_size;
	if (!op || !id || (block_n < 0)) {
		throw -1;
	}

	packet_size = DEFAULT_BASE_SIZE * block_n;

	buffer = (packet_buffer_u *) malloc(packet_size);
	if (!buffer) {
		throw -2;
	}

	buffer->op = op;
	buffer->id = id;
	buffer->body_len = 0;
	buffer->num_ele = 0;

	cur = (struct packet_element_u *) &buffer->start;
	cur->type = NONE;

}

packet_c::packet_c(uint32_t op, uint64_t id) :
	packet_c(op, id, 1)
{
	;
}

packet_c::~packet_c()
{
	free(buffer);
}

int packet_c::add_leb128(enum packet_element_e type, void *to_add, size_t len)
{
	// TODO unsure of the implementation
	return 0;
}

int packet_c::add(enum packet_element_e type, void *addr, size_t len)
{
	void *target;
	if (!type || !addr || !len) {
		return -1;
	}

	cur->type = type;
	switch (type) {
		case BIN:
		case STRING:
			cur->binstr.len = len;
			target = &cur->binstr.b;
			break;
		case NONE:
			return -2;
		default:
			target = &cur->b;
			break;
	}
	memcpy(target, addr, len);

	next();
	return 0;
}

enum packet_element_e packet_c::type()
{
	return (enum packet_element_e) cur->type;
}

enum packet_element_e packet_c::next()
{
	size_t jump_size = cur->size();
	cur = (struct packet_element_u *)
		((char *) cur + jump_size);
	return type();
}

template<typename T> T val_simple(