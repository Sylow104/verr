#include "network/packet.h"

struct packet_element_u
{
	enum packet_element_e type;
	union
	{
		struct
		{
			size_t len;
			char b;
		} binstr;
		union
		{
			char c;
			short s;
			int i;
			double d;
		} num;
	};
};

// int id + 4
// long op + 8
// int body_len + 4
// int num + 4

struct
{
	size_t length;
	size_t num;
} packet_body_u;

struct
{
	int op;
	long id;

} packet_header_u;

struct
{
	char *_buffer;
	struct packet_header_u *header;
} packet_u;

struct packet_u *packet_new(int op, long id, int block_n)
{
	return 0x0;
}

int packet_destroy(struct packet_u *to_destroy)
{
	return 0;
}