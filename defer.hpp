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
        deferFunctionType const _func;

        explicit deferObject(deferFunctionType const &f) :
                _func(f) {}

        explicit deferObject(deferFunctionSignatureType const f) :
                _func(f) {}

        public:
        ~deferObject() {
                _func();
        }

        static deferObject Defer(deferFunctionType const &f) {
 	       return deferObject(f);
	}

        static deferObject Defer(deferFunctionSignatureType const f) {
        	return deferObject(f);
	}
};
}

#if 0
#if __cplusplus > 201100L
#define defer(scope) speed::deferObject GEN_ANONYMOUS_VARIABLE = speed::Defer([]()scope)

#define defer(func_addr, args...) speed::deferObject GEN_ANONYMOUS_VARIABLE = speed::deferObject::Defer(speed::Bind(func_addr, ##args))

#endif

#endif

#define defer(func_addr) speed::deferObject GEN_ANONYMOUS_VARIABLE = speed::deferObject::Defer(func_addr)
