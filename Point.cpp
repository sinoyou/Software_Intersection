#include "Point.h"

Point::Point(Rational* x, Rational* y) : x(x), y(y){}

void Point::register_line(Line* l) {
	this->on_lines.push_back(l);
}

Rational* Point::get_x() const {
	return x;
}

Rational* Point::get_y() const {
	return y;
}

