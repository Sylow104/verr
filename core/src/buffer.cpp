#include "network/buffer.hpp"
#include <string.h>

size_t buff_element_u::mod(buff_element_e type, const void *src, size_t len)
{
	void *target;
	this->_type = type;
	switch(this->_type) {
		case BIN:
		case STRING:
			binstr.len = len;
			target = &binstr.b;
			break;
		case NONE:
			return 0;
		default:
			target = &b;
			break;
	}
	memcpy(target, src, len);
	return len;
}

size_t buff_element_u::size()
{
	// UB if there was no data whatsoever
	size_t to_ret = sizeof(uint8_t);
	switch(_type) {
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

buff_element_e buff_element_u::type()
{
	return (buff_element_e) _type;
}

const void *buff_element_u::val(size_t *len)
{
	if (len) {
		*len = size();
	} else {
		;
	}

	void *target;

	switch (type()) {
		case BIN:
		case STRING:
			target = &binstr.b;
			break;
		case NONE:
			target = 0x0;
			break;
		default:
			target = &b;
			break;
	}

	return (const void *) target;
}