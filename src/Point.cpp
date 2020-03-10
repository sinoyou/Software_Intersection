#include "Point.h"

Point::Point(Rational* x, Rational* y) : x(x), y(y){}

Point::Point(int64_t x, int64_t y) : x(new Rational(x)), y(new Rational(y)) {}

void Point::register_line(Line* l) {
	this->on_lines.push_back(l);
}

Rational* Point::get_x() const {
	return x;
}

Rational* Point::get_y() const {
	return y;
}

std::list<Line*>* Point::get_lines() {
	return &this->on_lines;
}

