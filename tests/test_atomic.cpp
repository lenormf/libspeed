/*
 * test_atomic.cpp for libspeed
 * by lenorm_f
 */

#include <thread>
#include <iostream>
#include <atomic.hpp>
#include <assert.hpp>

static void worker(int *pn) {
	int n = 0;

	while (n < 10)
		n = speed::Atomic::increment(pn);
}

int main() {
	int n = 0;

	std::thread w1(&worker, &n);
	std::thread w2(&worker, &n);

	w1.join();
	w2.join();

	speed::Assert(n == 11, "n == 11");
}
