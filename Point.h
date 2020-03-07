#pragma once

#include <iostream>
#include <list>
#include "Rational.h"
#include "Line.h"

class Point
{
private:
	Rational* x;
	Rational* y;
	std::list<Line*> on_lines;

public:
	Point(Rational* x, Rational* y);
	void register_line(Line* l);
	Rational* get_x();
	Rational* get_y();

	bool operator==(const Point& p) {
		return this->x == p.x && this->y == p.y;
	}

	int64_t hash() const {
		return x->hash() + y->hash();
	}
};

// hash function for point (generally for hash of RationalX and RationalY)
struct point_hash {
	size_t operator() (const Point& p) const {
		return p.hash();
	}
};