CC=gcc

all: main.o array.o gameLogic.o
	$(CC) main.o array.o gameLogic.o -Wall -o lifeGame
main.o: main.c array.h gameLogic.h
	$(CC) main.c -Wall -c -o main.o
array.o: array.c array.h
	$(CC) array.c -Wall -c -o array.o
gameLogic.o: gameLogic.c gameLogic.h array.h
	$(CC) gameLogic.c -Wall -c -o gameLogic.o
clean:
	rm -f *.o lifeGame
