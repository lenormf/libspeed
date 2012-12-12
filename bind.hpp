/*
 * bind.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#define SPEED_PRIVATE_INCLUDE
#include "placeholder.hpp"
#include "bindobject.hpp"
#undef SPEED_PRIVATE_INCLUDE

namespace speed {

// Static function, no argument
template <typename R>
bindObject<R()> Bind(R (*func)()) {
	return bindObject<R()>(func);
}

// Member function, no argument
template <typename R, typename CT>
bindObject<R(CT::*)()> Bind(R (CT::*func)(), CT *inst) {
	return bindObject<R(CT::*)()>(func, inst);
}

// Static function, 1 argument
template <typename R, typename T1>
bindObject<R(T1)> Bind(R (*func)(T1), T1 _1) {
	return bindObject<R(T1)>(func, _1);
}

// Static function, 1 placeholder
template <typename R, typename T1>
bindObject<R(T1)> Bind(R (*func)(T1), PlaceHolder::_placeholder _1) {
	return bindObject<R(T1)>(func, _1);
}

// Member function, 1 argument
template <typename R, typename CT, typename T1>
bindObject<R(CT::*)(T1)> Bind(R (CT::*func)(T1), CT *inst, T1 _1) {
	return bindObject<R(CT::*)(T1)>(func, inst, _1);
}

// Member function, 1 placeholder
template <typename R, typename CT, typename T1>
bindObject<R(CT::*)(T1)> Bind(R (CT::*func)(T1), CT *inst, PlaceHolder::_placeholder _1) {
	return bindObject<R(CT::*)(T1)>(func, inst, _1);
}
}
