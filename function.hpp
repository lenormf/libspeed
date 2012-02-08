/*
 * function.hpp for tsoob
 * by lenorm_f
 */

#if defined(TEMPLATE_ARGUMENTS) \
	&& defined(FUNCTION_TYPES) \
	&& defined(FUNCTOR_TYPES_VARS) \
	&& defined(FUNCTOR_VARS)

template<>
template<TEMPLATE_ARGUMENTS>
class Function<R(FUNCTION_TYPES)> {
	struct ICallable {
		virtual ~ICallable() {}

		virtual ICallable *clone() = 0;
		virtual R call(FUNCTION_TYPES) = 0;
	};

	template<typename U>
	class Callable : public ICallable {
		U _obj;

		public:
			Callable(U obj) : _obj(obj) {}
			~Callable() {}

			ICallable *clone() {
				return new Callable<U>(_obj);
			}

			R call(FUNCTOR_TYPES_VARS) {
				return _obj(FUNCTOR_VARS);
			}
	};

	ICallable *_caller;

	public:
		Function() {
			_caller = 0;
		}
		Function(Function const &func) {
			if (func._caller)
				_caller = func._caller->clone();
		}
		template<typename U>
		Function(U func) {
			_caller = new Callable<U>(func);
		}
		~Function() {
			if (_caller)
				delete _caller;
		}

		Function &operator=(Function const &func) {
			if (this != &func) {
				if (_caller && func._caller) {
					delete _caller;
					_caller = func._caller->clone();
				}
			}

			return *this;
		}
		template<typename U>
		Function &operator=(U func) {
			if (_caller)
				delete _caller;
			_caller = new Callable<U>(func);

			return *this;
		}

		R operator()(FUNCTOR_TYPES_VARS) {
			if (_caller)
				return _caller->call(FUNCTOR_VARS);

			return R();
		}
};

#undef TEMPLATE_ARGUMENTS
#undef FUNCTION_TYPES
#undef FUNCTOR_TYPES_VARS
#undef FUNCTOR_VARS
#endif

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

namespace tsoob {
template<typename T>
class Function;

#define TEMPLATE_ARGUMENTS typename R
#define FUNCTION_TYPES
#define FUNCTOR_TYPES_VARS
#define FUNCTOR_VARS
#include "function.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1
#define FUNCTION_TYPES T1
#define FUNCTOR_TYPES_VARS T1 _1
#define FUNCTOR_VARS _1
#include "function.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1,typename T2
#define FUNCTION_TYPES T1, T2
#define FUNCTOR_TYPES_VARS T1 _1, T2 _2
#define FUNCTOR_VARS _1, _2
#include "function.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1,typename T2, typename T3
#define FUNCTION_TYPES T1, T2, T3
#define FUNCTOR_TYPES_VARS T1 _1, T2 _2, T3 _3
#define FUNCTOR_VARS _1, _2, _3
#include "function.hpp"

#define TEMPLATE_ARGUMENTS typename R, typename T1,typename T2, typename T3, typename T4
#define FUNCTION_TYPES T1, T2, T3, T4
#define FUNCTOR_TYPES_VARS T1 _1, T2 _2, T3 _3, T4 _4
#define FUNCTOR_VARS _1, _2, _3, _4
#include "function.hpp"
}

#endif
