#include "utils.h"

int64_t temp;

int64_t gcd(int64_t a, int64_t b) {
	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}