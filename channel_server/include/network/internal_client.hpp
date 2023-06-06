#pragma once
#include "network/channel_client.hpp"

class internal_client_u : public channel_client_u
{
	public:
	internal_client_u();
	~internal_client_u();

	int decode_buffer(const char *buffer, size_t len);

	protected:
	int encode_buffer(const char *buffer, size_t len);

	private:

};