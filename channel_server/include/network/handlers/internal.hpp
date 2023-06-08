#pragma once
#include "network/handlers/handler.hpp"

class internal_h : public handler_u
{
	public:
	internal_h();
	~internal_h();

	void internal_server_identify_r(channel_client_u *client, packet_u *packet);
	void internal_channel_status(channel_client_u *client, packet_u
	*packet);
	void broadcast(channel_client_u *client, packet_u *packet);

	protected:

	private:
};