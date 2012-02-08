/*
 * test_function.cpp foir tsoob
 * by lenorm_f
 */

#include <cstdio>
#include <iostream>
#include <functional>
#include <function.hpp>

void empty() {}

int main() {
	tsoob::Function<void()> ref = &empty;
	tsoob::Function<void()> f = ref;

	f();
	f = std::bind(&empty);
	f();

	tsoob::Function<int(char const*)> ff = &::puts;

	ff("oui");
}
