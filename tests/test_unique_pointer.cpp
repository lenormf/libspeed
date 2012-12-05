/*
 * test_unique_pointer.cpp for libspeed
 * by lenorm_f
 */

#include <assert.hpp>
#include <unique_pointer.hpp>

int main() {
	int *pn = new int(20);
	{
		speed::UniquePointer<int> shp(pn);
		{
			speed::UniquePointer<int> shp2(shp);
		}
		speed::Assert(*pn != 0);
	}

	speed::UniquePointer<int> shp1(new int(0x2A));
	speed::UniquePointer<int> shp2(shp1);

	speed::Assert(shp1.get() == shp2.get());
	speed::Assert(**shp2 == 0x2A);
}
