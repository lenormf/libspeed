/*
 * test_types_list.cpp for libspeed
 * by lenorm_f
 */

#include <iostream>
#include <types_list.hpp>

int main() {
	typedef TYPESLIST_3(int, float, char) l;
	l::head n = 0x2A;
	l::tail::head f = 0.0f;
	l::tail::tail::head c = 0x2A;

	std::cout << "TypesList size: " << l::size << " types" << std::endl;
	std::cout << n << "; " << f << "; " << c << std::endl;
}
