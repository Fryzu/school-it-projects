#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "strings.h"
#include "list.h"

int addRecord(TreeNode *newNode, char *surname)
{
    char inputLine[MAXLINE];
    long long int inputNumber;
    
    if(surname == NULL)
    {
        printf("Surname: ");
        fgets(inputLine, MAXLINE, stdin);
        stringRewrite(inputLine, newNode->surname);
    }
    else
    {
        stringRewrite(surname, newNode->surname);
    }

    printf("Name: ");
    fgets(inputLine, MAXLINE, stdin);
    stringRewrite(inputLine, newNode->name);

    printf("Number: ");
    scanf("%lld", &inputNumber);
    getchar();
    newNode->numberList = NULL;
    pushBack(&(newNode->numberList), inputNumber);

    return 0;
}

int insert(TreeNode **root)
{
    system("clear");
    printf("Insert: \n");

    if((*root) == NULL)
    {
        (*root) = malloc(sizeof(TreeNode));
        if((*root) == NULL)
        {
            printf("error - allocation error\n");
            return -1;
        }

        addRecord(*root, NULL);
    }
    else 
    {
        TreeNode *position = *root;
        TreeNode *prev = *root;
        char surname[MAXLINE];
        long long int inputNumber;

        printf("Surname: ");
        fgets(surname, MAXLINE, stdin);

        while(position != NULL)
        {
            prev = position;

            if(stringCompare(position->surname, surname) < 0)   position = position->left;
            else if(stringCompare(position->surname, surname) > 0)  position = position->right;
            else
            {
                printf("Surname already on list \nAdd number: ");
                scanf("%lld", &inputNumber);
                getchar();
                pushBack(&(position->numberList), inputNumber); 

                return 0;
            }
        }

        if(stringCompare(prev->surname, surname) < 0)
        {
            prev->left = malloc(sizeof(TreeNode));
            if(prev->left == NULL)
            {
                printf("error - allocation error\n");
                return -1;
            }
            addRecord(prev->left, surname);
        }
        else if(stringCompare(prev->surname, surname) > 0)
        {
            prev->right = malloc(sizeof(TreeNode));
            if(prev->right == NULL)
            {
                printf("error - allocation error\n");
                return -1;
            }
            addRecord(prev->right, surname);
        }
    }

    printf("...............................\n");
    printf("Press enter to continue\n");
    getchar();

    return 0;
}

int delete()
{
    system("clear");
    printf("Delete: \n");
    printf("...............................\n");
    printf("Press enter to continue\n");
    getchar();

    return 0;
}

int findMax(TreeNode *position)
{
    system("clear");
    printf("Tree maximum: \n");

    if(position == NULL)
    {
        printf("error - empty tree\n");
    }

    while(position->right != NULL)
    {
        position = position->right;
    }

    printf("Maximum found: \n");
    printString(position->surname);
    printString(position->name); 
    listShow(position->numberList);

    printf("...............................\n");
    printf("Press enter to continue\n");
    getchar();

    return 0;
}

int findMin(TreeNode *position)
{
    system("clear");
    printf("Tree minimum: \n");

    if(position == NULL)
    {
        printf("error - empty tree\n");
    }

    while(position->left != NULL)
    {
        position = position->left;
    }

    printf("Minimum found: \n");
    printString(position->surname);
    printString(position->name); 
    listShow(position->numberList);

    printf("...............................\n");
    printf("Press enter to continue\n");
    getchar();

    return 0;
}

int search(TreeNode *position)
{
    system("clear");
    printf("Search: \n");
    printf("What name are you looking for?: "); 

    char inputLine[MAXLINE];
    fgets(inputLine, MAXLINE, stdin);

    while(position != NULL)
    {
        if(stringCompare(position->surname, inputLine) < 0)   position = position->left;
        else if(stringCompare(position->surname, inputLine) > 0)  position = position->right;
        else
        {
            printf("Surname found: \n");
            printString(position->surname);
            printString(position->name); 
            listShow(position->numberList);

            break;
        }
    }

    printf("...............................\n");
    printf("Press enter to continue\n");
    getchar();

    return 0;
}

void inOrder(TreeNode *position)
{
    if(position->left != NULL)  inOrder(position->left);
    printString(position->surname);
    printString(position->name);
    listShow(position->numberList);
    printf("\n");
    if(position->right != NULL) inOrder(position->right);
}

int nodeNumber(TreeNode *position)
{
    if(position == NULL)    return 0;

    return nodeNumber(position->left)+1+nodeNumber(position->right);
}

int height(TreeNode *position)
{
    if(position == NULL)    return 0;
    
    int left = height(position->left)+1;
    int right = height(position->right)+1;

    if(left>right) return left;
    else            return right;
}