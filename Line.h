#pragma once

#include <iostream>
#include <list>
#include "Point.h"

class Line
{
private:
	Rational* a;
	Rational* b;
	Rational* c;
	std::list<Point*> have_points;
	Point* upper_point;
	Point* lower_point;

public:
	Line(Rational* p1, Rational* p2);
	void register_point(Point* point);
	Point* get_upper_point();

	static Point* get_intersection(Line* l1, Line* l2);
};