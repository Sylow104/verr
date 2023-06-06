#pragma once
#include <vector>
#include <stdint.h>
#include <time.h>

class character_u;
class pet_u;
class script_u;
class bank_inventory_u;

class account_u
{
	public:
	account_u();
	~account_u();

	char id[256];
	uint64_t session_id;
	uint32_t authority;
	time_t last_login = time(0x0);
	char ban_reason[256];
	time_t ban_expiration;

	std::vector<character_u *> characters;
	std::vector<pet_u *> pets;
	script_u *scripts;
	bank_inventory_u *bank;

	int32_t autoban_score;
	int32_t autoban_count;

	protected:

	private:
	
};