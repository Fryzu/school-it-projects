#include "array.h"
#include <stdlib.h>
#include <stdio.h>

int arrayCreate(int ***tablica, int y, int x)
{
    *tablica = malloc(y*sizeof(int*));
    if(*tablica==NULL) return -1;

    int k;
    for(k=0; k<y; k++)
    {
        (*tablica)[k] = malloc(x*sizeof(int));
        if((*tablica)[k]==NULL)
        {
            arrayDelete(tablica, y, k-1);
            return -1;
        }
    }

    return 0;
}

int arrayDelete(int ***tablica, int x, int y)
{
    x--;
    y--;

    for(x; x>=0; x--)
    {
        free((*tablica)[x]);
    }

    free((*tablica));

    return 0;
}

int arrayResize(int ***tablica, int a, int b, int x, int y)
{
    int **newTab = NULL;
    if(arrayCreate(&newTab, x, y)==-1) return -1;

    int k, i;
    for(k=0; (k<x)&&(k<a); k++)
    {
        for(i=0; (i<y)&&(i<b); i++)
        {
            newTab[k][i] = (*tablica)[k][i];
        }
    }

    arrayDelete(tablica, a, b);
    *tablica = newTab;

    return 0;
}

int arrayAt(int **tablica, int y, int x)
{
    return tablica[y][x];
}

void arrayInsert(int **tablica, int y, int x, int inputValue)
{
    tablica[y][x] = inputValue;
}

void arrayToZero(int **tablica, int y, int x)
{
    int i, k;

    for(k=0; k<y; k++)
    {
        for(i=0; i<x; i++)
        {
            arrayInsert(tablica, k, i, 0);
        }
    }
}