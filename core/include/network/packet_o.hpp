#pragma once
#include "network/packet.hpp"

class packet_o_u : protected packet_u
{
	public:
	packet_o_u(uint32_t op, uint64_t id);
	~packet_o_u();

	protected:

	private:

};