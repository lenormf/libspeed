/*
 * assert.hpp for libspeed
 * by lenorm_f
 */

#pragma once

#include <string>
#include <stdexcept>

namespace speed {
struct Assert {
	struct Error : std::exception {
		Error(std::string const &msg) :
			_msg(msg) {}
		~Error() throw() {}

		char const *what() const throw() {
			return _msg.c_str();
		}

		private:
		std::string const _msg;
	};

	Assert(bool expr, std::string const &msg = "anonymous assertion") :
		_msg(std::string("assertion failed: ")) {
		_msg += msg;
		if (!expr)
			throw Error(_msg);
	}

	private:
	std::string _msg;
};
}
