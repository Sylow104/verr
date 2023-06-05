#pragma once
#include <stdint.h>
#include <stddef.h>
#include "network/buffer.hpp"

class packet_u
{
	public:
	packet_u();
	~packet_u();

	protected:
	int next();
	buff_u *buffer;
	buff_element_u *cur;
	size_t body_position;

	private:
	
};