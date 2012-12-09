/*
 * test_defer.cpp for libspeed
 * by lenorm_f
 */

#include <iostream>
#include <defer.hpp>

void empty() {}

void p1() {
	std::cout << 1;
}

int main() {
	defer(&empty);

	{
		defer(&p1);
	}
}
