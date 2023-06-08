#pragma once
#include <vector>
#include <map>

class shaped_entity_i;
class position_u;
template<typename T> class quadtree_u
{
	public:
	quadtree_u()
	{
		;
	};
	~quadtree_u()
	{
		;
	};
};

class linepath_u;

class collision_m
{
	public:
	collision_m();
	~collision_m();

	void add(shaped_entity_i *shaped_entity);
	void remove(long entity_id);
	bool any(position_u *from, position_u *to);
	bool find(position_u *from, position_u *to, position_u *intersection_out);

	protected:

	private:
	bool find_intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, position_u *intersection_out);

	quadtree_u<linepath_u *> *_tree;
	std::map<long, linepath_u *> _reference;
	
};