#pragma once
#include "world/position.hpp"

class location_u
{
	public:
	location_u(int region_id, int x, int y);
	location_u(int region_id, position_u *pos);
	location_u(long location_id);
	location_u(const char *location);
	~location_u();

	long to_location_id();
	const char *to_string();

	int region_id;
	int x;
	int y;

	position_u *position;

	protected:

	private:

};