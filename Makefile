.PHONY: clean test all

all: data/array_stack

data/array_stack: data/stack.o data/array_stack.o
	g++ -W -Wall -Wextra -pedantic -std=c++0x data/array_stack.o test/array_stack.cpp -o test/bin/arraystack -lboost_unit_test_framework

data/stack.o: data/stack.hpp
	g++ -W -Wall -Wextra -pedantic -std=c++0x -c data/stack.hpp -o data/stack.o

data/array_stack.o: data/array_stack.cpp
	g++ -W -Wall -Wextra -pedantic -std=c++0x -c data/array_stack.cpp -o data/array_stack.o

clean:
	rm -f *.o
	rm -f test/*.o
	rm -f data/*.o
	rm -f build/*.o
	rm -f algo/*.o

test:
	./test/bin/*
