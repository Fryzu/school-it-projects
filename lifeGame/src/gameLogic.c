#include <stdio.h>
#include "gameLogic.h"
#include "array.h"

void showBoard(int **tablica, int y, int x)
{
    int k, i;

    for(k=0; k<y; k++)
    {
        for(i=0; i<x; i++)
        {
            if(arrayAt(tablica, k, i) == 1)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int checkForFriends(int y, int x, int **tablica, int ysize, int xsize)
{
    int friends = 0;

    //SPRWADZAMY ILOSC SASIADOW
    int xi = x-1;
    int yi = y-1;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    xi++;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    xi++;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    yi++;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    yi++;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    xi--;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    xi--;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }
    yi--;
    if((xi>=0)&&(xi<xsize)&&(yi>=0)&&(yi<ysize))
    {
        if(tablica[yi][xi] == 1) ++friends;
    }

    //SPRAWDZAMY WARUNKI GRY
    if(friends == 3)
    {
        return 1;
    }
    else if((tablica[y][x]==1)&&(friends == 2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
