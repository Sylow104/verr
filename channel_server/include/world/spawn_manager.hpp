#pragma once
#include <stdint.h>

class creature_spawner_u;
class npc_u;

class spawn_m
{
	public:
	spawn_m();
	~spawn_m();

	void add(creature_spawner_u *spawner);
	creature_spawner_u *get(int spawner_id);
	void clear();
	void spawn_all();
	npc_u spawn(int race_id, int region_id, int x, int y, bool active, bool effect);

	protected:

	private:
};
