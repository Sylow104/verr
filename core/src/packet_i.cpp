#include "network/packet_i.hpp"

packet_i_u::packet_i_u(uint32_t op, uint64_t id)
{
	buffer->op = op;
	buffer->id = id;
	buffer->body_len = 0;
	buffer->num_ele = 0;
}

packet_i_u::~packet_i_u()
{
	;
}