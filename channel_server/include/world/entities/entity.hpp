#pragma once
#include <stdint.h>

class region_u;
class position_u;
class location_u;
class entity_u
{
	public:
	entity_u();
	~entity_u();

	uint64_t id;
	int region_id;

	region_u *region;
	position_u *position;
	location_u *get_location();


	// action<entity> disappears

	void disappears();


	const char *id_hex();




	protected:

	private:
};