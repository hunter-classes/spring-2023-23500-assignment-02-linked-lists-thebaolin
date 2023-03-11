OBJECTS=OList.o main.o Node.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

OList.o: OList.cpp Node.h OList.h

main.o: main.cpp OList.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS) main