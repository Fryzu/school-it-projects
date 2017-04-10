#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"
#include "list.h"
#include "strings.h"

int main()
{
    int choice;
    TreeNode *adressBook = NULL;

    while(1)
    {
        system("clear");
        printf("BST adress book:\n");
        printf("...............................\n");
        printf("Menu: \n");
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. height\n");
        printf("3. Search\n");
        printf("4. Inorder\n");
        printf("5. FindMin\n");
        printf("6. FindMax\n");
        printf("7. Node number\n");
        printf("...............................\n");

        scanf("%i", &choice);
        getchar();

        switch(choice)
        {
            case 0: return 0;
            case 1: insert(&adressBook); break; 
            case 2: 
                system("clear");
                printf("Tree height: \n");
                printf("%i\n", height(adressBook));
                printf("...............................\n");
                printf("Press enter to continue\n");
                getchar();
                break;
            case 3: search(adressBook); break;
            case 4: 
                system("clear");
                printf("Inorder: \n");
                inOrder(adressBook); 
                printf("...............................\n");
                printf("Press enter to continue\n");
                getchar();
                break;
            case 5: findMin(adressBook); break; 
            case 6: findMax(adressBook); break;
            case 7: 
                system("clear");
                printf("Node number: \n");
                printf("%i\n", nodeNumber(adressBook)); 
                printf("...............................\n");
                printf("Press enter to continue\n");
                getchar();
                break;
        }
    }

    return 0;
}