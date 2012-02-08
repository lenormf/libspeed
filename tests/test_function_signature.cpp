/*
 * test_function_signature.cpp for tsoob
 * by lenorm_f
 */

#include <iostream>
#include <function_signature.hpp>

struct Foo {
	int n;
};

struct Empty {};

int main() {
	tsoob::FunctionSignature<void(int)>::type f = [](int){};
	tsoob::FunctionSignature<int(void*, double)>::type ff = [](void*, double){
		return 0;
	};
	tsoob::FunctionSignature<Foo(int, char, Empty)>::type fff = [](int, char, Empty){
		return Foo{};
	};
}
