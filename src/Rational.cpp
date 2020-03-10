#include <algorithm>
#include "Rational.h"
#include "utils.h"

inline int64_t abs_(int64_t x) {
	if (x < 0)
		return -x;
	return x;
}

inline int64_t max_(int64_t x, int64_t y) {
	return x < y ? y : x;
}

inline int64_t min_(int64_t x, int64_t y) {
	return x < y ? x : y;
}

Rational::Rational(int64_t value) {
	this->numerator = value;
	this->dominator = 1;
}

Rational::Rational(int64_t num, int64_t dom) {
	if (dom == 0) {
		std::cerr << "Detect zero division, auto turned to 1." << std::endl;dom = 1;
	}

	auto abs_num = abs_(num);
	auto abs_dom = abs_(dom);
	auto GCD = gcd(max_(abs_num, abs_dom), min_(abs_num, abs_dom));
	
	num = num / GCD;
	dom = dom / GCD;

	this->numerator = num;
	this->dominator = dom;
}

/*
 a   b   a*d + b*c
 - + - = ----------
 c   d     c * d
*/
Rational* Rational::add(Rational* a, Rational* b) {
	auto num = a->numerator * b->dominator + a->dominator * b->numerator;
	auto dom = a->dominator * b->dominator;
	Rational* p = new Rational(num, dom);
	return p;
}

/*
 a   b   a*d - b*c
 - - - = ----------
 c   d     c * d
*/
Rational* Rational::sub(Rational* a, Rational* b) {
	auto num = a->numerator * b->dominator - a->dominator * b->numerator;
	auto dom = a->dominator * b->dominator;
	Rational* p = new Rational(num, dom);
	return p;
}

/*
 a   b     a * b
 - * - = ----------
 c   d     c * d
*/
Rational* Rational::multiply(Rational* a, Rational* b) {
	auto num = a->numerator * b->numerator;
	auto dom = a->dominator * b->dominator;
	Rational* p = new Rational(num, dom);
	return p;
}

/*
 a   b     a * d
 - / - = ----------
 c   d     c * b
*/
Rational* Rational::div(Rational* divee, Rational* diver) {
	auto num = divee->numerator * diver->dominator;
	auto dom = divee->dominator * diver->numerator;
	Rational* p = new Rational(num, dom);
	return p;
}