##
## Makefile for libspeed
## by lenorm_f
##

TESTS = \
		test_function \
		test_function_signature \
		test_types_list \
		test_params_list \
		test_static_assert \
		test_assert \
		test_atomic \
		test_unique_pointer \
		test_defer

LOGFILE = out.log

TESTS_SRC = $(addsuffix .cpp,$(TESTS))
TESTS_OBJ = $(TESTS_SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -I.. -Wall -Wextra -std=c++11

LDFLAGS = -lpthread

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
		|| echo "[$$t] test failed, see $(LOGFILE) for more info" \
		&& echo [$$t] test passed; done
