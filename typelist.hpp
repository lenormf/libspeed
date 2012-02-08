/*
 * typelist.hpp for rtype
 * by lenorm_f
 */

#ifndef __TYPELIST_H__
#define __TYPELIST_H__

namespace tsoob {
template<typename H, typename T>
struct TypeList {
	typedef H head;
	typedef T tail;

	static int const size = tail::size + 1;
};

struct EmptyList {
	static int const size = 0;
};
}

#define TYPELIST_0 tsoob::EmptyList
#define TYPELIST_1(_1) tsoob::TypeList<_1, tsoob::EmptyList>
#define TYPELIST_2(_1, _2) tsoob::TypeList<_1, TYPELIST_1(_2)>
#define TYPELIST_3(_1, _2, _3) tsoob::TypeList<_1, TYPELIST_2(_2, _3)>
#define TYPELIST_4(_1, _2, _3, _4) tsoob::TypeList<_1, TYPELIST_3(_2, _3, _4)>

#endif
