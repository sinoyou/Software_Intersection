#include <iostream>
#include <set>

#ifndef __LINE_H__
#define __LINE_H__
#include "Point.h"

class Line
{
private:
	Rational* a;
	Rational* b;
	Rational* c;
	std::set<Point*, point_set_cmp> have_points;
	Point* upper_point;
	Point* lower_point;

public:
	Line(Point* p1, Point* p2);
	void register_point(Point* point);
	Point* get_upper_point();

	static Point* get_intersection(Line* l1, Line* l2);
};

#endif // !__LINE_H__


