/*
 * static_assert.hpp for libspeed
 * by lenorm_f
 */

#pragma once

namespace speed {
template <bool V>
struct StaticAssert;

template <>
struct StaticAssert<true> {
};
}
