#pragma once
#include <stdint.h>
#include <vector>

class account_u;
class creature_u;
class character_playable_u;
class item_u;
class channel_client_u;
enum incident_security_level_e
{
	ISL_0
};
class variable_m;

class channel_db
{
	public:
	channel_db();
	~channel_db();

	account_u *get_account(const char *account_id);
	creature_u *get_character(account_u *account, uint64_t entity_id, 
		const char *table);
	int log_security_incident(channel_client_u *client, incident_security_level_e level, const char *report, const char *stacktrace);

	int save_quests(character_playable_u *character);
	int save_account(account_u *account);
	int save_character(character_playable_u *character, account_u account);
	int save_character_keywords(character_playable_u *character);
	int save_character_titles(character_playable_u *character);
	int save_character_items(character_playable_u *character);
	int save_character_skills(character_playable_u *character);
	variable_m *load_vars(const char *account_id, uint64_t creature_id);
	int save_vars(const char *account_id, uint64_t creature_id, variable_m vars);
	bool tmp_items_exist();

	const char *get_coupon_script(const char *code);
	bool use_coupon(const char *code);
	
	
	private:
	int get_character_items(character_playable_u *character);

	int add_bank_tab_for_character(account_u *account, 
		character_playable_u *character, int width, int height);
	std::vector<item_u *> get_items(uint64_t creature_id, bool bank = false);
	int get_character_keywords(character_playable_u *character);
	int get_character_titles(character_playable_u *character);
	int get_character_skills(character_playable_u *character);
	int get_character_quests(character_playable_u *character);
	
};