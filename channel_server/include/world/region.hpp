#pragma once
#include "world/entity_manager.hpp"

class client_event_u;

class variable_m;
class collision_m;
class region_info_u;

class region_u
{
	public:
	region_u(uint32_t id);
	~region_u();

	// integrate a limbo region 
	// const static region_u *limbo = new region_u;

	client_event_u *get_client_event(uint64_t id);
	client_event_u *get_client_event(const char *event_name);
	client_event_u *get_client_event(); // this one is unusual TODO
	std::vector<client_event_u *> get_matching_event(const char *event_path);
	void remove_scripted_entities();
	int get_area_id(int x, int y);
	void update_entities();

	creature_m creature_mgr;
	npc_m npc_mgr{&creature_mgr};
	player_m player_mgr{&creature_mgr};
	item_m item_mgr;
	prop_m prop_mgr;

	const char *name;
	uint32_t id;
	region_info_u *info;
	bool is_dynamic;
	bool is_dungeon;
	bool is_temp;
	variable_m *variable_mgr;
	collision_m *collision_mgr;

	protected:
	std::vector<client_event_u *> events;
	rw_lock *event_lock;

	void initialize_from_data();
	void load_props();
	void load_client_events();

	private:
	void add_client_event(client_event_u *event);
	void remove_overdue_entities();
	void update_visibility();

};