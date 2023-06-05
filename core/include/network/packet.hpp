#pragma once
#include <stdint.h>
#include <stddef.h>
#include "network/buffer.hpp"

#define DEFAULT_BUFFER_SIZE 4096

class packet_u
{
	public:
	packet_u();
	~packet_u();

	protected:
	size_t next();
	buff_u *buffer;
	buff_element_u *cur;
	size_t body_position;

	private:
	
};