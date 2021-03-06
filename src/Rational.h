#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include<iostream>

class Rational
{
private:
	int64_t numerator;
	int64_t dominator;
public:
	Rational(int64_t value);
	Rational(int64_t num, int64_t dom);

	static Rational* add(Rational* a, Rational* b);
	static Rational* sub(Rational* a, Rational* b);
	static Rational* multiply(Rational* a, Rational* b);
	static Rational* div(Rational* divee, Rational* diver);

	bool operator==(const Rational& r) {
		return (this->numerator * r.dominator - this->dominator * r.numerator) == 0;
	}

	bool operator<(const Rational& r) {
		return (this->numerator * r.dominator - this->dominator * r.numerator) * (this->dominator * r.dominator) < 0;
	}

	size_t hash() const {
		return size_t(numerator * 31 + dominator * 17373321);
	}
};

// Hash algorithm for hash_map if needed.
struct rational_hash {
	size_t operator() (const Rational* r) const {
		return r->hash();
	}
};

#endif // !__RATIONAL_H__