#include <algorithm>
#include "Rational.h"
#include "utils.h"

Rational::Rational(int64_t value) {
	this->numerator = value;
	this->dominator = 1;
}

Rational::Rational(int64_t num, int64_t dom) {
	if (dom == 0) {
		std::cout << "Detect zero division, auto turned to 1." << std::endl;
		dom = 1;
	}

	auto GCD = gcd(std::max(std::abs(num), std::abs(dom)), std::min(std::abs(num), std::abs(dom)));
	
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
	auto dom = a->numerator * b->numerator;
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