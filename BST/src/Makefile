CC=gcc
FLAGS=-Wall -c -g
PATHLINE=../obj/

all: $(PATHLINE)main.o $(PATHLINE)binaryTree.o $(PATHLINE)list.o $(PATHLINE)strings.o
	$(CC) $(PATHLINE)main.o $(PATHLINE)binaryTree.o $(PATHLINE)list.o $(PATHLINE)strings.o -Wall -g -o ../BST
$(PATHLINE)main.o: main.c binaryTree.h list.h strings.h
	$(CC) main.c $(FLAGS) -o $(PATHLINE)main.o
$(PATHLINE)binaryTree.o: binaryTree.c binaryTree.h list.h
	$(CC) binaryTree.c $(FLAGS) -o $(PATHLINE)binaryTree.o
$(PATHLINE)list.o: list.c list.h
	$(CC) list.c $(FLAGS) -o $(PATHLINE)list.o
$(PATHLINE)strings.o: strings.c strings.h
	$(CC) strings.c $(FLAGS) -o $(PATHLINE)strings.o
clean: 
	rm -f $(PATHLINE)*.o