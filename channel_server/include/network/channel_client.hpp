#pragma once
#include <map>
#include <stdint.h>

class account_u;
class creature_u;
class npc_session_u;

class channel_client_u
{
	public:
	channel_client_u();
	~channel_client_u();

	account_u *account;
	creature_u *controlling;
	std::map<uint64_t, creature_u *> creatures;
	npc_session_u *npc_session;

	protected:

	private:

};