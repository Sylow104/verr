#pragma once
#include "network/handlers/handler.hpp"

class gmcp_h : public handler_u
{
	public:
	gmcp_h();
	~gmcp_h();

	void gmcp_close(channel_client_u *client, packet_u *packet);
	void gmcp_summon(channel_client_u *client, packet_u *packet);
	void gmcp_move_to_char(channel_client_u *client, packet_u *packet);
	void gmcp_warp(channel_client_u *client, packet_u *packet);
	void gmcp_revive(channel_client_u *client, packet_u *packet);
	void gmcp_invisibility(channel_client_u *client, packet_u *packet);
	void gmcp_expel(channel_client_u *client, packet_u *packet);
	void gmcp_ban(channel_client_u *client, packet_u *packet);
	void gmcp_npc_list(channel_client_u *client, packet_u *packet);
	void gmcp_boost(channel_client_u *client, packet_u *packet);

	protected:

	private:
	void ensure_gmcp_authority(channel_client_u *client);
};