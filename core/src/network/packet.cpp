#include "network/packet.hpp"
#include <stdlib.h>
#include <string.h>



packet_u::packet_u()
{
	buffer = (buff_u *) malloc(DEFAULT_BUFFER_SIZE);
	cur = (buff_element_u *) &buffer->payload;
	cur->mod(NONE, 0x0, 0);
	body_position = sizeof(buff_u) 
		- sizeof(uint8_t);
};

packet_u::~packet_u()
{
	free(buffer);
};

size_t packet_u::next()
{
	size_t jump_size = cur->size();
	cur = (buff_element_u *) ((char *) cur + jump_size);
	return jump_size;
}
