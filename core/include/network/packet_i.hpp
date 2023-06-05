#pragma once
#include "network/packet.hpp"

// TODO add client to marshal packets received from sockets
class packet_i_u : public packet_u
{
	public:
	packet_i_u();
	~packet_i_u();

	const uint8_t *val_uc(bool to_next = true);
	const uint16_t *val_us(bool to_next = true);
	const uint32_t *val_ui(bool to_next = true);
	const uint64_t *val_ud(bool to_next = true);
	const int8_t *val_sc(bool to_next = true);
	const int16_t *val_ss(bool to_next = true);
	const int32_t *val_si(bool to_next = true);
	const int64_t *val_sd(bool to_next = true);
	const char *val_str(size_t *len, bool to_next = true);
	const char *val_bin(size_t *len, bool to_next = true);
	size_t val_len();

	protected:
	template<typename T> const T* val(size_t *len, bool to_next = true);
	private:

};