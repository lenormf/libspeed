/*
 * lexical_cast.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#include <stringstream>

namespace speed {
template<typename T, typename U>
T LexicalCast(U const &s) {
	T _v;
	std::sstream ss(s, std::ios_base::in);

	_v << ss;

	return _v;
}
}
