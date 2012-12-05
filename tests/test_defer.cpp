/*
 * test_defer.cpp for libspeed
 * by lenorm_f
 */

#include <defer.hpp>

int main() {
	int n = 0;

	defer({
	      //n = 0x2A;
	});

	return n;
}
