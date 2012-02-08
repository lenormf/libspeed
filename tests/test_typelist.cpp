/*
 * test_typelist.cpp for tsoob
 * by lenorm_f
 */

#include <iostream>
#include <typelist.hpp>

int main() {
	typedef TYPELIST_3(int, float, char) l;
	l::head n = 0x2A;
	l::tail::head f = 0.0f;
	l::tail::tail::head c = 0x2A;

	std::cout << "TypeList size: " << l::size << " types" << std::endl;
	std::cout << n << "; " << f << "; " << c << std::endl;
}
