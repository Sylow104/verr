#pragma once
#include "network/packet.hpp"

// packet for receiving

class packet_o_u : protected packet_u
{
	public:
	packet_o_u(uint32_t op, uint64_t id);
	~packet_o_u();

	int add_uc(uint8_t *in);
	int add_us(uint16_t *in);
	int add_ui(uint32_t *in);
	int add_ud(uint64_t *in);
	int add_sc(int8_t *in);
	int add_ss(int16_t *in);
	int add_si(int32_t *in);
	int add_sd(int64_t *in);
	int add_str(const char *in, size_t len);
	int add_bin(const void *in, size_t len);

	protected:

	private:
	int add(buff_element_e type, const void *src, size_t len);

};

