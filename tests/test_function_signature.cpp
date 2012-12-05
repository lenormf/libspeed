/*
 * test_function_signature.cpp for libspeed
 * by lenorm_f
 */

#include <iostream>
#include <function_signature.hpp>

struct Foo {
	int n;
};

struct Empty {};

int main() {
	speed::FunctionSignature<void(int)>::type f = [](int){};
	speed::FunctionSignature<int(void*, double)>::type ff = [](void*, double){
		return 0;
	};
	speed::FunctionSignature<Foo(int, char, Empty)>::type fff = [](int, char, Empty){
		return Foo{0};
	};
}
