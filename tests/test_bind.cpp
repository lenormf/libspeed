/*
 * test_bind.cpp for libspeed
 * by lenorm_f
 */

#include <string>
#include <iostream>
#include <bind.hpp>
//#include <function.hpp>

struct Foo {
	void sayHello(char const *name) {
		std::cout << "Hello " << name << std::endl;
	}

	void empty() {
		std::cout << "Foo::empty" << std::endl;
	}

	static void print(char const *s) {
		std::cout << std::string(s) << std::endl;
	}
};

static void empty() {
	std::cout << "empty" << std::endl;
}

int main() {
	Foo foo;

	//speed::Function<void()> f = speed::Bind(&empty);

	//f();

	speed::Bind(&empty)();
	speed::Bind(&Foo::empty, &foo)();

	speed::Bind(&Foo::print, "oui")();
	speed::Bind(&Foo::print, speed::PlaceHolder::_1)("oui");

	speed::Bind(&Foo::sayHello, &foo, "World!")();
	speed::Bind(&Foo::sayHello, &foo, speed::PlaceHolder::_1)("World!");
}
