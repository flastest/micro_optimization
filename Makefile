CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17 -O3
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  quick_converter naive_converter eitan_converter

quick_converter: quick_converter.o driver.o
	$(CXX) $(CXXFLAGS) -o $@ $^

eitan_converter: converter.o driver.o
	$(CXX) $(CXXFLAGS) -o $@ $^

naive_converter: naive_converter.o driver.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_cache_client cache_server

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./cache_server
	valgrind --leak-check=full --show-leak-kinds=all ./test_cache_client
