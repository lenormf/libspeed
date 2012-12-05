##
## Makefile for libspeed
## by lenorm_f
##

NAME = libspeed$(LIB_SUFFIX)
LIB_SUFFIX = .so

CXX = g++
CXXFLAGS = -Wall -Wextra
LDFLAGS =

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:
	$(CXX) $(LDFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(NAME)

re: distclean all

dotests:
	make -C tests tests

tests: dotests
