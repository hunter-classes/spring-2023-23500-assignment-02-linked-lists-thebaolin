OBJECTS=OList.o main.o Node.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o OList.o Node.o 
	g++ -o tests tests.o OList.o Node.o

tests.o: tests.cpp doctest.h OList.h Node.h
	g++ -c -std=c++11 -Wall tests.cpp

OList.o: OList.cpp Node.h OList.h

List.o: List.cpp Node.h List.h

main.o: main.cpp OList.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS) main tests tests.o