#pragma once
#include <stdint.h>
#include <vector>
class position_u;
class entity_u;
class npc_u;
class player_creature_u;
class prop_u;
class item_u;
class creature_u;
class point_u;
class packet_u;
class rw_lock;

#define VISIBLE_RANGE 3000


template <typename T> class entity_m
{
	public:
	entity_m()
	{
		;
	};
	~entity_m()
	{
		;
	};


	void add(T *to_add)
	{
		set_v.insert(to_add);
		return;
	};

	void remove(T* to_remove)
	{
		return;
	};

	T *get(uint64_t entity_id)
	{
		return 0x0;
	};
	
	T* get(const char *name)
	{
		return 0x0;
	};

	T* get_safe(uint64_t entity_id)
	{
		return 0x0;
	};

	std::vector<T *> get_list()
	{
		std::vector<T *> to_ret;

		return to_ret;
	};

	std::vector<T *> get_list(bool (*search_func)(T *, bool))
	{
		std::vector<T *> to_ret;

		return to_ret;
	};

	std::vector<T *> get_visible(entity_u *from, int range = VISIBLE_RANGE)
	{
		std::vector<T *> to_ret;

		return to_ret;
	};

	virtual std::vector<entity_u *> get_entities_range(entity_u *source, int range = -1) final
	{
		std::vector<entity_u *> to_ret;

		return to_ret;
	};

	bool exists(uint64_t entity_id)
	{
		return false;
	};

	virtual void broadcast(packet_u *packet)
	{
		return;
	};

	virtual void broadcast(packet_u *packet, entity_u *src, bool send_to_source = true, int range = -1) 
	{
		return;
	};

	protected:
	std::vector<T *> set_v;
	rw_lock *lock;

	private:
	

};

class creature_m : public entity_m<creature_u>
{
	public:
	creature_m()
	{
		;
	};

	~creature_m()
	{
		;
	};

	std::vector<creature_u *> get_in_range(position_u *pos, int range)
	{
		std::vector<creature_u *> to_ret;

		return to_ret;
	};

	std::vector<creature_u *> get_in_polygon(point_u *points[])
	{
		std::vector<creature_u *> to_ret;

		return to_ret;
	};

	friend class npc_m;
	friend class player_m;

	protected:

	private:
	
};

class player_m
{
	public:
	player_m(creature_m *delegated_acs) 
	{
		del_acs = delegated_acs;
	};

	~player_m()
	{
		;
	};

	player_creature_u *get(const char *name)
	{
		return 0x0;
	};

	std::vector<creature_u *> get_in_range(position_u *pos, int range = VISIBLE_RANGE) {
		std::vector<creature_u *> to_ret;

		return to_ret;
	};

	std::vector<creature_u *> get_players()
	{
		std::vector<creature_u *> to_ret;

		return to_ret;
	};

	int count();

	protected:

	private:
	creature_m *del_acs;
};

class npc_m
{

	public:
	npc_m(creature_m *delegated_acs)
	{
		del_acs = delegated_acs;
	};

	~npc_m()
	{
		;
	};

	int count_aggro(creature_u *target, int race_id)
	{
		return 0;
	};

	int count_aggro(creature_u *target)
	{
		return 0;
	};

	void active_ai(creature_u *creature, position_u *pos, position_u *to)
	{
		return;
	};

	void add_good_npcs(std::vector<creature_u *> list)
	{
		return;
	};

	protected:

	private:
	creature_m *del_acs;
};

class item_m : public entity_m<item_u>
{
	public:
	item_m()
	{
		;
	};

	~item_m()
	{
		;
	};

	protected:

	private:
};

class prop_m : public entity_m<prop_u>
{
	public:
	prop_m()
	{
		;
	};

	~prop_m()
	{
		;
	};

	uint64_t get_new_entity_id(prop_u *prop)
	{
		return 0;
	};

	protected:

	private:
};