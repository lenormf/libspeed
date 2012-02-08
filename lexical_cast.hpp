/*
 * lexical_cast.hpp for tsoob
 * by lenorm_f
 */

#ifndef __LEXICAL_CAST_H__
#define __LEXICAL_CAST_H__

#include <stringstream>

namespace tsoob {
template<typename T>
T lexical_cast(std::string const &s) {
	T _v;
	std::sstream ss(s, std::ios_base::in);

	_v << ss;

	return _v;
}
}

#endif
