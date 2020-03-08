#include <iostream>
#include <list>

#ifndef __POINT_H__
#define __POINT_H__

#include "Rational.h"
class Line;
class Point
{
private:
	Rational* x;
	Rational* y;
	std::list<Line*> on_lines;

public:
	Point(Rational* x, Rational* y);
	void register_line(Line* l);
	Rational* get_x() const;
	Rational* get_y() const;

	bool operator==(const Point& p) {
		return this->x == p.x && this->y == p.y;
	}

	int64_t hash() const {
		return x->hash() + y->hash();
	}
};

// hash function for point (generally for hash of RationalX and RationalY)
struct point_hash {
	int64_t operator() (const Point* p) const {
		return p->hash();
	}
};

// compare function for set
struct point_set_cmp {
	bool operator() (const Point* a, const Point* b) const {
		auto ax = a->get_x();
		auto ay = a->get_y();
		auto bx = b->get_x();
		auto by = b->get_y();

		if (*by < *ay) {
			return true;
		}
		else if (*ay < *by) {
			return false;
		}
		else {
			return *ax < *bx;
		}
	}
};

#endif // !__POINT_H__