/*
 * unique_pointer.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#include "atomic.hpp"

namespace speed {
template <typename T>
class UniquePointer {
	T *_ptr;
	int *_counter;

	void _assign_pointer(UniquePointer const &shp) {
		_ptr = shp._ptr;
		++(*shp._counter);
	}

	public:
	UniquePointer() {
		_ptr = 0;
		_counter = 0;
	}
	UniquePointer(T *ptr) {
		_ptr = ptr;
		_counter = new int(1);
	}
	UniquePointer(UniquePointer const &shp) {
		_assign_pointer(shp);
	}
	~UniquePointer() {
		--*_counter;
		if (!*_counter) {
			delete _ptr;
			delete _counter;
		}
	}

	UniquePointer &operator=(UniquePointer const &shp) {
		_assign_pointer(shp);
	}

	T *operator*() {
		return _ptr;
	}

	T *get() const {
		return _ptr;
	}
};
}
