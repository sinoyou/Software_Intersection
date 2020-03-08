#include "Line.h"

Line::Line(Point* p1, Point* p2) {
	this->a = Rational::sub(p1->get_y(), p2->get_y());
	this->b = Rational::sub(p2->get_x(), p1->get_x());
	this->c = Rational::sub(
		Rational::multiply(p1->get_x(), p2->get_y()),
		Rational::multiply(p1->get_y(), p2->get_x()));

	if (*(p1->get_y()) < *(p2->get_y())) {
		this->upper_point = p2;
	}
	else {
		this->upper_point = p1;
	}
}

/*
 Give two Lines, return their intersection expressed as Point.
 HINT: if 2 lines are parallel or stacked, return NULL
*/
Point* Line::get_intersection(Line* l1, Line* l2) {
	// a1 * b2 - a2 * b1
	auto dom = Rational::sub(Rational::multiply(l1->a, l2->b), Rational::multiply(l1->b, l2->a));
	// paralle check
	auto zero = Rational(0);
	if (*dom == zero) {
		return NULL;
	}

	// b1 * c2 - b2 * c1
	auto num1 = Rational::sub(Rational::multiply(l1->b, l2->c), Rational::multiply(l1->c, l2->b));
	// a2 * c1 - a1 * c2
	auto num2 = Rational::sub(Rational::multiply(l1->c, l2->a), Rational::multiply(l1->a, l2->c));

	auto p = new Point(Rational::div(num1, dom), Rational::div(num2, dom));
	return p;
}

void Line::register_point(Point* p) {
	this->have_points.insert(p);
}

Point* Line::get_upper_point() {
	return this->upper_point;
}