#include "network/packet_o.hpp"

packet_o_u::packet_o_u(uint32_t op, uint64_t id)
{
	buffer->op = op;
	buffer->id = id;
}

packet_o_u::~packet_o_u()
{
	;
}

int packet_o_u::add(buff_element_e type, const void *src, size_t len)
{
	if (len + body_position > DEFAULT_BUFFER_SIZE) {
		return -1;
	}
	size_t ret_len = cur->mod(type, src, len);
	if (ret_len != len) {
		return -2;
	}
	buffer->num_ele += 1;
	buffer->body_len += ret_len;
	body_position += ret_len;
	next();
	return 0;
}

int packet_o_u::add_uc(uint8_t *in)
{
	return add(BYTE, in, sizeof(uint8_t));
}

int packet_o_u::add_us(uint16_t *in)
{
	return add(SHORT, in, sizeof(uint16_t));
}

int packet_o_u::add_ui(uint32_t *in)
{
	return add(INT, in, sizeof(uint32_t));
}

int packet_o_u::add_ud(uint64_t *in)
{
	return add(FLOAT, in, sizeof(uint64_t));
}

int packet_o_u::add_sc(int8_t *in)
{
	return add_uc((uint8_t *) in);
}

int packet_o_u::add_ss(int16_t *in)
{
	return add_us((uint16_t *) in);
}

int packet_o_u::add_si(int32_t *in)
{
	return add_ui((uint32_t *) in);
}

int packet_o_u::add_sd(int64_t *in)
{
	return add_ud((uint64_t *) in);
}

int packet_o_u::add_str(const char *in, size_t len)
{
	return add(STRING, in, len);
}

int packet_o_u::add_bin(const void *in, size_t len)
{
	return add(BIN, in, len);
}