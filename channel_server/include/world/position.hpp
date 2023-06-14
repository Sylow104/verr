#pragma once

class random_u;
class point_u;

class position_u
{
	public:
	position_u(int x, int y);
	position_u(position_u *other);
	position_u(long location_id);
	~position_u();

	int x;
	int y;

	int get_distance(position_u* other);
	bool in_range(position_u *other, int range);
	bool in_range(int x, int y, int range);
	position_u *get_random_in_range(int dist_min, int dist_max, random_u *rnd);
	position_u *get_random_in_range(int radius, random_u *rnd);
	position_u *get_random_in_rect(int width, int height, random_u *rnd);
	position_u *get_relative(position_u *other, int dist);
	bool in_polygon(point_u *points[]);

	int get_hash_code();
	bool operator==(position_u *other);
	bool operator!=(position_u *other);
	const char *to_string();

	protected:

	private:
	position_u *get_random(int distance, random_u *rnd);

};