#include "world/region.hpp"
#include "world/spawn_manager.hpp"
#include "world/dungeon_manager.hpp"
#include "world/dynamic_region_manager.hpp"
#include <map>
#include <time.h>

class npc_u;
class erinn_time_u;
class timer_u;

class region_m
{
	public:
	region_m();
	~region_m();

	void initialize();
	void add(int region_id);
	void add(region_u *region);
	void remove(int region_id);
	region_u *get(int region_id);
	region_u *get(const char *region_name);
	bool has(int region_id);
	prop_u *get_prop(uint64_t id);
	player_creature_u *get_player(const char *name);
	std::vector<creature_u *> get_all_players();
	int count_players();
	creature_u *get_creature(uint64_t id);
	creature_u *get_creature(const char *name);
	std::vector<creature_u *> get_all_creatures();
	npc_u *get_npc(uint64_t id);
	npc_u *get_npc(const char *name);
	std::vector<npc_u *> get_all_good_npc();
	void remove_scripted_entities();
	void broadcast(packet_u *packet);

	const int heartbeat_time = 500;
	const int second = 1000;
	const int minute = second * 60;
	const int hour = minute * 60;
	const int erinn_minute = 1500;
	const int erinn_hour = erinn_minute * 60;
	const int erinn_day = erinn_hour * 24;

	dungeon_m *dungeon_mgr;
	dynamic_region_m *dynamic_region_mgr;
	spawn_m *spawn_mgr;
	int count;


	protected:

	private:
	void add_regions_from_data();
	void setup_heartbeat();
	void heartbeat(void (*events)());
	void update_entities();
	void on_erinn_daytime_tick(erinn_time_u *now);

	std::map<int, region_u *> regions;
	bool intialzied;
	timer_u *heartbeat_timer;
	time_t last_heart_beat;
	double seconds_time;
	double minutes_time;
	double hours_time;
	double erinn_time;
	int mabi_tick_count;
	
};