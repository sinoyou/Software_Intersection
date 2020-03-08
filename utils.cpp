#include "utils.h"


int64_t gcd(int64_t a, int64_t b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}