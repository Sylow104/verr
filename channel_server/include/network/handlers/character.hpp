#include "network/handlers/handler.hpp"

class character_h : public handler_u
{
	public:
	character_h();
	~character_h();

	void change_title(channel_client_u *client, packet_u packet);
	void dead_menu(channel_client_u *client, packet_u packet);
	void revive(channel_client_u *client, packet_u packet);

	protected:

	private:

};