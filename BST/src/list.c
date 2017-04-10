#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int pushBack(ListNode **position, long long int value)
{
    if((*position)==NULL)
    {
        *position = malloc(sizeof(ListNode));
        if((*position) == NULL)
        {
            printf("list allocation error\n");
            return -1;
        }

        (*position)->next = NULL;
        (*position)->value = value;

        return 0;
    }

    while((*position)->next != NULL) (*position) = (*position)->next;

    (*position)->next = malloc(sizeof(ListNode));
    if((*position)->next == NULL)
    {
        printf("list allocation error\n");            
        return -1;
    }

    (*position)->next->next = NULL;
    (*position)->next->value = value;

    return 0;
}

ListNode *listSearch(ListNode *position, long long int value)
{
    if(position->value == value) return position;

    while(position->next!=NULL)
    {
        position = position->next;
        if(position->value == value) return position;
    }

    return NULL;
}

int listDelete(ListNode **position, long long int value)
{
    if((*position)->value == value)
    {
        free(*position);
        position = NULL;

        return 0;
    }

    *position = listSearch(*position, value);
    if((*position)->value == value)
    {
        free(*position);
        position = NULL;

        return 0;
    }

    return -1;
}

void listShow(ListNode *list)
{
    while(list != NULL)
    {
        printf("%lld\n", list->value);
        list = list->next;
    }
}