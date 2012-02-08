##
## Makefile for tsoob
## by lenorm_f
##

TESTS = \
		test_function \
		test_function_signature \
		test_typelist
LOGFILE = out.log

TESTS_SRC = $(addsuffix .cpp,$(TESTS))
TESTS_OBJ = $(TESTS_SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -I.. -Wall -Wextra -std=c++0x

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test_%: test_%.o
	$(CXX) $(LDFLAGS) -o $@ $<

all: $(TESTS)

clean:
	rm -f $(TESTS_OBJ)

distclean: clean
	rm -f $(TESTS)

re: distclean all

tests: $(TESTS)
	@echo -n > $(LOGFILE)
	@for t in $(TESTS); do ./$$t >> $(LOGFILE) \
		|| (echo "[$$t] test failed, see $(LOGFILE) for more info" && exit 1) \
		&& echo [$$t] test passed; done
