#include "network/packet_o.hpp"

packet_o_u::packet_o_u(uint32_t op, uint64_t id)
{
	buffer->op = op;
	buffer->id = id;
	buffer->body_len = 0;
	buffer->num_ele = 0;
}

packet_o_u::~packet_o_u()
{
	;
}