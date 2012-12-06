/*
 * defer.hpp for libspeed
 * by lenormf
 */

#pragma once

#include "function.hpp"
#include "macro_utils.hpp"

namespace speed {
class deferObject {
        public:
	typedef Function<void()> deferFunctionType;
        typedef deferFunctionType::Signature::Type deferFunctionSignatureType;

        private:
        deferFunctionType _func;

        explicit deferObject(deferFunctionType &f) :
                _func(f) {}

        explicit deferObject(deferFunctionSignatureType f) :
                _func(f) {}

        public:
        ~deferObject() {
                _func();
        }

        static deferObject Defer(deferFunctionType &f) {
 	       return deferObject(f);
	}

        static deferObject Defer(deferFunctionSignatureType f) {
        	return deferObject(f);
	}
};
}

#define ANONYMOUS_VARIABLE_PREFIX $_DEFER_
#define ANONYMOUS_VARIABLE_NAME CONCAT(ANONYMOUS_VARIABLE_PREFIX, __COUNTER__)

#if 0
#if __cplusplus > 201100L
#define defer(scope) speed::deferObject ANONYMOUS_VARIABLE_NAME = speed::Defer([]()scope)

#define defer(func_addr, args...) speed::deferObject ANONYMOUS_VARIABLE_NAME = speed::deferObject::Defer(speed::Bind(func_addr, ##args))

#endif

#endif

#define defer(func_addr) speed::deferObject ANONYMOUS_VARIABLE_NAME = speed::deferObject::Defer(func_addr)
