
# libspeed

## Description

This library implements a few boost objects, such as functors, lexical_cast, or
types_lists. Although some tests might happen to be using the C++11 standard,
libspeed is supposedly fully C++03 compatible.

## Use

Do __not__ use this library in your project. libspeed is just a learning
project I spend time on when I want to practice my meta-programming skills, it
is definitely not stable and will break your code.

If you still intend to use it (for the same purposes I do), be aware that it
was only compiled with the _gcc_ compiler, and that certain features are
OS-dependant (such as the Atomic methods).
