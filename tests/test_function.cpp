/*
 * test_function.cpp for libspeed
 * by lenorm_f
 */

#include <cstdio>
#include <bind.hpp>
#include <function.hpp>

void empty() {}

int main() {
	speed::Function<void()> ref = &empty;
	speed::Function<void()> f = ref;

	f();
	f = speed::Bind(&empty);
	f();

	speed::Function<int(char const*)> ff = &::puts;

	ff("oui");
}
