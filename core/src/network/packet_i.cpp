#include "network/packet_i.hpp"

packet_i_u::packet_i_u()
{
	;
}

packet_i_u::~packet_i_u()
{
	;
}

const uint8_t *packet_i_u::val_uc(bool to_next)
{
	return val<uint8_t>(0x0, to_next);
}

const uint16_t *packet_i_u::val_us(bool to_next)
{
	return val<uint16_t>(0x0, to_next);
}

const uint32_t *packet_i_u::val_ui(bool to_next)
{
	return val<uint32_t>(0x0, to_next);
}

const uint64_t *packet_i_u::val_ud(bool to_next)
{
	return val<uint64_t>(0x0, to_next);
}

const int8_t *packet_i_u::val_sc(bool to_next)
{
	return val<int8_t>(0x0, to_next);
}

const int16_t *packet_i_u::val_ss(bool to_next)
{
	return val<int16_t>(0x0, to_next);
}

const int32_t *packet_i_u::val_si(bool to_next)
{
	return val<int32_t>(0x0, to_next);
}

const int64_t *packet_i_u::val_sd(bool to_next)
{
	return val<int64_t>(0x0, to_next);
}

const char *packet_i_u::val_str(size_t *len, bool to_next)
{
	return val<char>(len, to_next);
}

const char *packet_i_u::val_bin(size_t *len, bool to_next)
{
	return val<char>(len, to_next);
}

template<typename T> const T *packet_i_u::val(size_t *len, bool to_next)
{
	// first level type checking
	switch (cur->type()) {
		case BIN:
		case STRING:
			if (*len <= 0) {
				throw -2;
			}
			break;
		case NONE:
			break;
		default:
			if (cur->size() != sizeof(T)) {
				throw -1;
			}
			break;
	}
	const void *to_ret = cur->val(len);
	if (to_next) {
		next();
	}
	return (T*) to_ret;
}