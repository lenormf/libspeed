/*
 * atomic.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#include "static_assert.hpp"

namespace speed {
struct Atomic {
	template <typename T>
	static T increment(T *p) {
		StaticAssert<(sizeof(T) % sizeof(int)) == 0
			      || sizeof(T) == sizeof(char)>();

		return ::__sync_add_and_fetch(p, 1);
	}

	template <typename T>
	static T decrement(T *p) {
		StaticAssert<(sizeof(T) % sizeof(int)) == 0
			      || sizeof(T) == sizeof(char)>();

		return __sync_add_and_fetch(p, -1);
	}
};
}
