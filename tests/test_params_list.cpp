/*
 * test_params_list.cpp for libspeed
 * by lenorm_f
 */

#include <iostream>
#include <params_list.hpp>

int main() {
	speed::ParamsList2<int, float> pl(0x2A, 1.2);

	std::cout << "size: " << pl.size << std::endl
		<< *pl << std::endl
		<< *pl.next << std::endl;
}
