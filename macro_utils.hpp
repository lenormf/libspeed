/*
 * macro_utils.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)

#define ANONYMOUS_VARIABLE_PREFIX $_
#define GEN_ANONYMOUS_VARIABLE CONCAT(ANONYMOUS_VARIABLE_PREFIX, __COUNTER__)
