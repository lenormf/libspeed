/*
 * function_signature.hpp for libspeed
 * by lenorm_f
 */

#if defined(TEMPLATE_ARGUMENTS) \
	&& defined(FUNCTION_TYPES) \
	&& defined(FUNCTION_TYPESLIST)

template<>
template<TEMPLATE_ARGUMENTS>
struct FunctionSignature<R(FUNCTION_TYPES)> {
	typedef R (*type)(FUNCTION_TYPES);

	typedef R ret;
	typedef FUNCTION_TYPESLIST params;
};

#undef TEMPLATE_ARGUMENTS
#undef FUNCTION_TYPES
#undef FUNCTION_TYPESLIST
#endif

#ifndef __FUNCTION_SIGNATURE_H__
#define __FUNCTION_SIGNATURE_H__

#include "types_list.hpp"

namespace speed {
template<typename T>
struct FunctionSignature;

#define TEMPLATE_ARGUMENTS typename R
#define FUNCTION_TYPES
#define FUNCTION_TYPESLIST TYPESLIST_0
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1
#define FUNCTION_TYPES T1
#define FUNCTION_TYPESLIST TYPESLIST_1(T1)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2
#define FUNCTION_TYPES T1, T2
#define FUNCTION_TYPESLIST TYPESLIST_2(T1, T2)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2, typename T3
#define FUNCTION_TYPES T1, T2, T3
#define FUNCTION_TYPESLIST TYPESLIST_3(T1, T2, T3)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2, typename T3, typename T4
#define FUNCTION_TYPES T1, T2, T3, T4
#define FUNCTION_TYPESLIST TYPESLIST_4(T1, T2, T3, T4)
#include "function_signature.hpp"
}

#endif
