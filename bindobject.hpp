/*
 * bindobject.hpp for libspeed
 * by lenormf
 */

#pragma once

#ifndef SPEED_PRIVATE_INCLUDE
#error "Do not directly include this header file"
#endif

namespace speed {
template <typename R>
class bindObject;

// Static function, no argument
template <typename R>
bindObject<R()> Bind(R (*)());

// Member function, no argument
template <typename R, typename CT>
bindObject<R(CT::*)()> Bind(R (CT::*)(), CT*);

// Static function, 1 argument
template <typename R, typename T1>
bindObject<R(T1)> Bind(R (*)(T1), T1);

// Static function, 1 placeholder
template <typename R, typename T1>
bindObject<R(T1)> Bind(R (*)(T1), PlaceHolder::_placeholder);

// Member function, 1 argument
template <typename R, typename CT, typename T1>
bindObject<R(CT::*)(T1)> Bind(R (CT::*)(T1), CT*, T1);

// Member function, 1 placeholder
template <typename R, typename CT, typename T1>
bindObject<R(CT::*)(T1)> Bind(R (CT::*)(T1), CT*, PlaceHolder::_placeholder);

// Functor: static function, no argument
template <>
template <typename R>
class bindObject<R()> {
	R (*_func)();

	bindObject(R (*func)()) :
		_func(func) {}

	public:
	R operator()() const {
		return _func();
	}

	friend bindObject<R()> Bind<>(R (*)());
};

// Functor: member function, no argument
template <>
template <typename R, typename CT>
class bindObject<R(CT::*)()> {
	R (CT::*_func)();
	CT *_inst;

	bindObject(R (CT::*func)(), CT *inst) :
		_func(func), _inst(inst) {}

	public:
	R operator()() const {
		return (_inst->*_func)();
	}

	friend bindObject<R(CT::*)()> Bind<>(R (CT::*)(), CT*);
};

// Functor: static function, 1 argument
template <>
template <typename R, typename T1>
class bindObject<R(T1)> {
	R (*_func)(T1);
	T1 _1;

	bindObject(R (*func)(T1), T1 a1) :
		_func(func), _1(a1) {}
	bindObject(R (*func)(T1), PlaceHolder::_placeholder) :
		_func(func) {}

	public:
	R operator()() const {
		return _func(_1);
	}
	R operator()(T1 __1) const {
		return _func(__1);
	}

	friend bindObject<R(T1)> Bind<>(R (*)(T1), T1);
	friend bindObject<R(T1)> Bind<>(R (*)(T1), PlaceHolder::_placeholder);
};

// Functor: member function, 1 argument
template <>
template <typename R, typename CT, typename T1>
class bindObject<R(CT::*)(T1)> {
	R (CT::*_func)(T1);
	CT *_inst;
	T1 _1;

	bindObject(R (CT::*func)(T1), CT *inst, T1 a1) :
		_func(func), _inst(inst), _1(a1) {}
	bindObject(R (CT::*func)(T1), CT *inst, PlaceHolder::_placeholder) :
		_func(func), _inst(inst) {}

	public:
	R operator()() const {
		return (_inst->*_func)(_1);
	}
	R operator()(T1 __1) const {
		return (_inst->*_func)(__1);
	}

	friend bindObject<R(CT::*)(T1)> Bind<>(R (CT::*)(T1), CT*, T1);
	friend bindObject<R(CT::*)(T1)> Bind<>(R (CT::*)(T1), CT*, PlaceHolder::_placeholder);
};
}
