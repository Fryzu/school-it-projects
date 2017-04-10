#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "gameLogic.h"

#define YSIZE 22
#define XSIZE 80

int main(int argc, char * argv[])
{
    int y, x;

    int **actualTable = NULL;
    int **nextTable = NULL;

    arrayCreate(&actualTable, YSIZE, XSIZE);
    arrayCreate(&nextTable, YSIZE, XSIZE);
    arrayToZero(actualTable, YSIZE, XSIZE);
    arrayToZero(nextTable, YSIZE, XSIZE);

    //POBIERNAIE DANYCH WSTĘPNYCH
    if(argc != 2)
    {
        printf("error - wrong input data\n");
        exit(-1);
    }

    //USTAWIANIE DANYCH WEJŚCIOWYCH

    FILE *inputData;
    if((inputData = fopen(argv[1], "r")) == NULL) 
    {
    	printf("error - cannot open file\n");
        exit(-1);
    }

    int a, b;
    while(fscanf(inputData, "%i %i", &a, &b) != EOF)
    {
        arrayInsert(actualTable, a, b, 1);
    }

    printf("Dane wczytane - nacisnij dowolny kalwisz aby kontynuować");
    getchar();
    fclose(inputData);

    while(1)
    {
        system("clear");

        showBoard(actualTable, YSIZE, XSIZE);

        for(y=0; y<YSIZE; y++)
        {
            for(x=0; x<XSIZE; x++)
            {
                arrayInsert(nextTable, y, x, checkForFriends(y, x, actualTable, YSIZE, XSIZE));
            }
        }

        for(y=0; y<YSIZE; y++)
        {
            for(x=0; x<XSIZE; x++)
            {
                actualTable[y][x] = nextTable[y][x];
            }
        }

        sleep(1);
    }

    return 0;
}

