#pragma once
#include "network/handlers/handler.hpp"
// treat this case as multiple partials over a class to handle events coming
// from sockets TODO

class base_h : protected handler_u
{
	public:
	base_h();
	~base_h();

	void unknown_packet(channel_client_u *client, packet_u *packet);
	void handle(channel_client_u *client, packet_u *packet);

	protected:

	private:
	bool check_inner_security_exception(channel_client_u *client, 
		std::exception *except);

};