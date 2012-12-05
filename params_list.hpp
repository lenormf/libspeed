/*
 * params_list.hpp for libspeed
 * by lenorm_f
 */

#pragma once

namespace speed {
template <typename _1>
class ParamsList_ops {
	_1 _it;

	protected:
	ParamsList_ops();

	ParamsList_ops(_1 const &it) :
		_it(it) {}

	public:
	_1 const &operator*() const {
		return _it;
	}

	_1 const &get() const {
		return _it;
	}
};

struct ParamsList0 {
	unsigned int const size;

	ParamsList0() :
		size(0) {}
};

template <typename _1>
struct ParamsList1 : public ParamsList_ops<_1> {
	ParamsList0 next;
	unsigned int const size;

	ParamsList1(_1 const &__1) :
		ParamsList_ops<_1>(__1),
       		size(1)	{}
};

template <typename _1, typename _2>
struct ParamsList2 : public ParamsList_ops<_1> {
	ParamsList1<_2> next;
	unsigned int const size;

	ParamsList2(_1 const &__1,
		    _2 const &__2) :
		ParamsList_ops<_1>(__1),
		next(__2),
       		size(2)	{}
};

template <typename _1, typename _2, typename _3>
struct ParamsList3 : public ParamsList_ops<_1> {
	ParamsList2<_2, _3> next;
	unsigned int const size;

	ParamsList3(_1 const &__1,
		    _2 const &__2,
		    _3 const &__3) :
		ParamsList_ops<_1>(__1),
		next(__2, __3),
       		size(3)	{}
};

template <typename _1, typename _2, typename _3, typename _4>
struct ParamsList4 : public ParamsList_ops<_1> {
	ParamsList3<_2, _3, _4> next;
	unsigned int const size;

	ParamsList4(_1 const &__1,
		    _2 const &__2,
		    _3 const &__3,
		    _4 const &__4) :
		ParamsList_ops<_1>(__1),
		next(__2, __3, __4),
       		size(4)	{}
};

template <typename _1, typename _2, typename _3, typename _4, typename _5>
struct ParamsList5 : public ParamsList_ops<_1> {
	ParamsList4<_2, _3, _4, _5> next;
	unsigned int const size;

	ParamsList5(_1 const &__1,
		    _2 const &__2,
		    _3 const &__3,
		    _4 const &__4,
		    _5 const &__5) :
		ParamsList_ops<_1>(__1),
		next(__2, __3, __4, __5),
       		size(5) {}
};
}
