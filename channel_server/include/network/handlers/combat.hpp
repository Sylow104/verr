#pragma once
#include "network/handlers/handler.hpp"

class combat_h : public handler_u
{
	public:
	combat_h();
	~combat_h();

	void change_stance(channel_client_u *client, packet_u *packet);
	void set_combat_target(channel_client_u *client, packet_u *packet);
	void combat_attack(channel_client_u *client, packet_u *packet);
	void subscribe_stability_meter(channel_client_u *client, packet_u *packet);
	void touch_mimic(channel_client_u *client, packet_u *packet);
	void unk_combat(channel_client_u *client, packet_u *packet);

	protected:

	private:

};