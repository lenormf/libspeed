##
## Makefile for tsoob
## by lenorm_f
##

NAME = tsoob

CXX = g++
CXXFLAGS = -Wall -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(NAME)

re: distclean all

tests:
	@make -C tests tests
