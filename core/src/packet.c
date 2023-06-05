#include "network/packet.h"
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
		union
		{
			uint8_t b;
		} num;
	};
};

// int id + 4
// long op + 8
// int body_len + 4
// int num + 4

struct _packet_u
{
	uint32_t op;
	uint64_t id;
	uint32_t body_len;
	uint32_t num_ele;
	uint8_t start;
};

struct packet_u
{
	struct _packet_u *m;
	struct packet_element_u *cur;
};

struct packet_u *packet_new(uint32_t op, uint64_t id, size_t block_n)
{
	size_t packet_size;
	struct packet_u *to_ret;

	if (!op || !id || (block_n < 0)) {
		return 0x0;
	}

	if (block_n) {
		packet_size = block_n * DEFAULT_BASE_SIZE;
	}
	else {
		packet_size = 1 * DEFAULT_BASE_SIZE;
	}

	to_ret =
	    (struct packet_u *)malloc(sizeof(struct packet_u));
	if (!to_ret) {
		return 0x0;
	}

	to_ret->m =
	    (struct _packet_u *)malloc(packet_size);

	to_ret->m->op = op;
	to_ret->m->id = id;
	to_ret->m->body_len = 0;
	to_ret->m->num_ele = 0;

	to_ret->cur = (struct packet_element_u *)&to_ret->m->start;
	to_ret->cur->type = NONE;

	return to_ret;
}

int packet_destroy(struct packet_u *to_destroy)
{
	if (!to_destroy) {
		return -1;
	}

	free(to_destroy->m);
	free(to_destroy);
	return 0;
}

enum packet_element_e packet_cur_type(struct packet_u *cur)
{
	return cur->cur->type;
}

size_t packet_cur_size(struct packet_u *cur)
{
	size_t to_ret = sizeof(uint8_t);
	switch (packet_cur_type(cur)) {
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
			to_ret += cur->cur->binstr.len;
			break;
		default:
			return NONE;
	}
	return to_ret;
}

enum packet_element_e packet_next(struct packet_u *to_mod)
{
	if (!to_mod) {
		return NONE;
	}

	size_t jump_size = packet_cur_size(to_mod);
	to_mod->cur = (struct packet_element_u *)
		((char *)to_mod->cur + jump_size);
	
	return (packet_cur_type(to_mod));
}

int packet_add(struct packet_u *to_mod, 
	enum packet_element_e type, void *val, size_t len)
{
	void *target;
	if (!type || !val || !len) {
		return -1;
	}

	to_mod->cur->type = type;
	switch (type) {
		case BIN:
		case STRING:
			to_mod->cur->binstr.len = len;
			target = &to_mod->cur->binstr.b;
			break;
		case NONE:
			return -2;
		default:
			target = &to_mod->cur->num.b;
			break;
	}
	memcpy(target, val, len);

	packet_next(to_mod);
	to_mod->cur->type = NONE;
	return 0;
}

