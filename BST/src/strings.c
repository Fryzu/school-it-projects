#include <stdio.h>
#include "strings.h"

#define MAXLINE 20

void stringClean(char *word)
{
    int k;
    for(k=0; k<MAXLINE; k++)
    {
        word[k] = '\0';
    }
}

int stringRewrite(char *from, char *into)
{
    if((from == NULL)||(into == NULL))
    {
        printf("error - cannot rewrite strings\n");
        return -1;
    }

    int k = 0;
    while(k<MAXLINE)
    {
        into[k] = from[k];
        if(from[k++]=='\n') break;
    }
    into[k] = '\n';

    return 0;
}

int stringCompare(char *a, char *b)
{
    if((a == NULL)||(b == NULL))
    {
        printf("error - cannot compare strings\n");
        return -1;
    }

    int k = 0;
    while(k<MAXLINE)
    {
        if((a[k]=='\n')&&(b[k]=='\n'))  return 0;
        if(a[k]<b[k])   return 1;
        if(a[k]>b[k])   return -1;

        k++;
    }

    return 0;
}

void printString(char *word)
{
    int k = 0;
    while((k<MAXLINE)&&(word[k]!='\n'))
    {
        printf("%c", word[k]);
        k++;
    }
    printf("\n");
}