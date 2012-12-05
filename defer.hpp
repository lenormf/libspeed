/*
 * defer.hpp for libspeed
 * by lenormf
 */

#pragma once

#include "function.hpp"
#include "macro_utils.hpp"

#define FUNCTOR_CONSTNESS
namespace speed {
class deferObject {
        public:
        typedef Function<void()> deferFunctionType;
        typedef deferObject deferObjectType;

        private:
        deferFunctionType FUNCTOR_CONSTNESS &_func;

        explicit deferObject(deferFunctionType FUNCTOR_CONSTNESS &f) :
                _func(f) {}

        public:
        ~deferObject() {
                _func();
        }

        friend deferObjectType Defer(deferFunctionType FUNCTOR_CONSTNESS &);
};

deferObject::deferObjectType Defer(deferObject::deferFunctionType FUNCTOR_CONSTNESS &f) {
        return deferObject::deferObjectType(f);
}
}

#define ANONYMOUS_VARIABLE_PREFIX $_DEFER_
#define ANONYMOUS_VARIABLE_NAME CONCAT(ANONYMOUS_VARIABLE_PREFIX, __COUNTER__)

#if __cplusplus > 201100L
#define defer(scope) speed::deferObject::deferObjectType ANONYMOUS_VARIABLE_NAME = speed::Defer([]()scope)
#else
#define defer(func_addr) speed::deferObject::deferObjectType ANONYMOUS_VARIABLE_NAME = speed::Defer(func_addr)
#endif
