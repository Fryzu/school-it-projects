CC=g++
CCFLAGS=-Wall -g -c

#all: main.o multiply.o addition.o
#	$(CC) multiply.o addition.o main.o -g -o simpleProgram
#main.o: main.cpp
#	$(CC) $(CCFLAGS) main.cpp -o main.o
#multiply.o: multiply.cpp multiply.h
#	$(CC) $(CCFLAGS) multiply.cpp -o multiply.o
#addition.o: addition.cpp addition.h
#	$(CC) $(CCFLAGS) addition.cpp -o addition.o
#clean: 
#	rm -f *.o

all: .main.o .matrix.o .vector.o
	$(CC) .main.o .matrix.o .vector.o -g -o MatrixOperations
.main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp -o .main.o
.vector.o: vector.h vector.cpp
	$(CC) $(CCFLAGS) vector.cpp -o .vector.o
.matrix.o: matrix.h matrix.cpp
	$(CC) $(CCFLAGS) matrix.cpp -o .matrix.o
clean:
	rm -f *.o

