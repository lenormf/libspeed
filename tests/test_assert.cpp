
#include <string>
#include <assert.hpp>

int main() {
	speed::Assert(1 == 1, std::string("test"));

	try {
		speed::Assert(1 == 0);
	}
	catch (speed::Assert::Error const &e) {
	}

	return 0;
}
