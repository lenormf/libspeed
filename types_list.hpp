/*
 * types_list.hpp for tsoob
 * by lenorm_f
 */

#pragma once

namespace tsoob {
template<typename H, typename T>
struct TypesList {
	typedef H head;
	typedef T tail;

	static int const size = tail::size + 1;
};

struct EmptyList {
	static int const size = 0;
};
}

#define TYPESLIST_0 tsoob::EmptyList
#define TYPESLIST_1(_1) tsoob::TypesList<_1, tsoob::EmptyList>
#define TYPESLIST_2(_1, _2) tsoob::TypesList<_1, TYPESLIST_1(_2)>
#define TYPESLIST_3(_1, _2, _3) tsoob::TypesList<_1, TYPESLIST_2(_2, _3)>
#define TYPESLIST_4(_1, _2, _3, _4) tsoob::TypesList<_1, TYPESLIST_3(_2, _3, _4)>
