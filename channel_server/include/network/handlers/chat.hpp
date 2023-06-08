#include "network/handlers/handler.hpp"

class chat_h : public handler_u
{
	public:
	chat_h();
	~chat_h();

	void chat(channel_client_u *client, packet_u *packet);
	void visual_chat(channel_client_u *client, packet_u *packet);

	protected:

	private:

};