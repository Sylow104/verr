#include "world/region.hpp"

region_u::region_u(uint32_t id)
{
	this->id = id;
	name = "EXAMPLE";
	is_dynamic = false;
	is_dungeon = false;
	is_temp = false;
}

region_u::~region_u()
{
	;
}