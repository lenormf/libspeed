/*
 * function_signature.hpp for tsoob
 * by lenorm_f
 */

#if defined(TEMPLATE_ARGUMENTS) \
	&& defined(FUNCTION_TYPES) \
	&& defined(FUNCTION_TYPELIST)

template<>
template<TEMPLATE_ARGUMENTS>
struct FunctionSignature<R(FUNCTION_TYPES)> {
	typedef R (*type)(FUNCTION_TYPES);

	typedef R ret;
	typedef FUNCTION_TYPELIST params;
};

#undef TEMPLATE_ARGUMENTS
#undef FUNCTION_TYPES
#undef FUNCTION_TYPELIST
#endif

#ifndef __FUNCTION_SIGNATURE_H__
#define __FUNCTION_SIGNATURE_H__

#include "typelist.hpp"

namespace tsoob {
template<typename T>
struct FunctionSignature;

#define TEMPLATE_ARGUMENTS typename R
#define FUNCTION_TYPES
#define FUNCTION_TYPELIST TYPELIST_0
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1
#define FUNCTION_TYPES T1
#define FUNCTION_TYPELIST TYPELIST_1(T1)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2
#define FUNCTION_TYPES T1, T2
#define FUNCTION_TYPELIST TYPELIST_2(T1, T2)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2, typename T3
#define FUNCTION_TYPES T1, T2, T3
#define FUNCTION_TYPELIST TYPELIST_3(T1, T2, T3)
#include "function_signature.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1, typename T2, typename T3, typename T4
#define FUNCTION_TYPES T1, T2, T3, T4
#define FUNCTION_TYPELIST TYPELIST_4(T1, T2, T3, T4)
#include "function_signature.hpp"
}

#endif
