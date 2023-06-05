#pragma once
#include "network/packet.hpp"

class packet_i_u : protected packet_u
{
	public:
	packet_i_u(uint32_t op, uint64_t id);
	~packet_i_u();

	protected:

	private:

};