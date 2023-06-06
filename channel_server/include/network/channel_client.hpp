#pragma once
#include <map>
#include <stdint.h>
#include <stddef.h>

class account_u;
class creature_u;
class npc_session_u;
class packet_u;

// inherits default_client
class channel_client_u
{
	public:
	channel_client_u();
	~channel_client_u();

	account_u *account;
	creature_u *controlling;
	std::map<uint64_t, creature_u *> creatures;
	npc_session_u *npc_session;

	creature_u *get_creature(uint64_t id);
	creature_u *get_creature_safe(uint64_t id);
	creature_u *get_controlled_creature_safe();
	creature_u *get_summoned_pet_safe(uint64_t id);

	// override
	void cleanup();

	protected:

	private:

};

class dummy_client_u : public channel_client_u
{
	public:
	dummy_client_u();
	~dummy_client_u();

	// all overrides derived class
	void send(const char *buffer, size_t len);
	void send(packet_u *packet);
	void kill();
	void cleanup();

	protected:

	private:
};