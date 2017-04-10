#include <iostream>
#include <string>
#include <cmath>

#define CNUMBER 128 //NUMBER OF CHARACTERS IN DICTIONARY

using namespace std;

/*Twoim zadaniem jest zaimplementowanie prostej mapy z użyciem drzewa BST. Mapa ma obsługiwać następujące operacje: 1. SET klucz wartosc - ustawia wartosc dla klucza klucz na odpowiednią. Jeżeli klucza nie ma w mapie, to go dodaje. 2. UNSET klucz - usuwa podany klucz z mapy o ile ten istnieje. 3. GET klucz - wypisuje wartość spod klucza lub “EMPTY” jeśli klucza nie ma.

Input Format

Pierwsza linia standardowego wejścia zawiera jedną liczbę naturalną z - liczbę operacji na mapie (1 ≤ z ≤ 1000000). W kolejnych z liniach znajdują się po jednej operacji GET, SET lub UNSET. Kluczami są ciągi znaków alfanumerycznych o długości nie większej niż 8, wartościami liczby całkowite typu int.

Output Format

Dla każdego zapytania GET program powinien wypisać w osobnej linii wartość spod zadanego klucza bądź napis “EMPTY” jeżeli klucz nie występuje w mapie.*/

struct Node {
    Node *parent;
    Node *leftChild;
    Node *rightChild;

    int data;
    long long int key;
};

//GENERATES INDIVIDUAL KEYS FOR INPUT STRING
long long int hashFunction(string keyWord)
{
    long long int key = 0;
    int k;

    for(int k = 0; k < keyWord.length(); k++)
    {
        key =key+keyWord[k]*pow(CNUMBER, k);
    }

    //cout << "klucz: " << key << endl;
    return key;
}

//TREE NODE CONSTRUCTOR
Node* nodeConstruct(Node *parent, string keyWord, int inputValue)
{
    Node *newNode = new Node;

    newNode->parent = parent;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    newNode->data = inputValue;
    newNode->key = hashFunction(keyWord);

    return newNode;
}

//FUNCTION FOR "SET"
int set(Node **treeRoot, string keyWord, int inputValue)
{
    if(*treeRoot == NULL)
    {
        *treeRoot = nodeConstruct(*treeRoot, keyWord, inputValue);
        if(treeRoot == NULL) return -1;

        return 0;
    }
    
    Node *position = *treeRoot;
    Node *prevPosition;

    while(position != NULL)
    {
        prevPosition = position;
        if(position->key > hashFunction(keyWord))
        {
            position = position->leftChild;
        }
        else if(position->key < hashFunction(keyWord))
        {
            position = position->rightChild;
        }
        else
        {
            position->data = inputValue;
            return 0;
        }
    }

    if(prevPosition->key > hashFunction(keyWord))
    {
        prevPosition->leftChild = nodeConstruct(prevPosition, keyWord, inputValue);
    }
    else
    {
        prevPosition->rightChild = nodeConstruct(prevPosition, keyWord, inputValue);
    }

    return 0;
}

int get(Node *position, string keyWord)
{
    long long int key = hashFunction(keyWord);

    while((position != NULL)&&(position->key != key))
    {
        if(position->key > key)
        {
            position = position->leftChild;
        }
        else
        {
            position = position->rightChild;
        }
    }

    if(position != NULL)
    {
        cout << position->data << endl;

        return 0;
    }

    cout << "EMPTY" << endl;

    return -1;
}

int unset(Node **position, string keyWord)
{
    if(*position == NULL) return -1;
    if((*position)->key == hashFunction(keyWord))
    {
        delete(*position);
        *position = NULL;

        return 0;
    }

    Node *prev;

    while(((*position)->key != hashFunction(keyWord)) && ((*position) != NULL))
    {
        prev = *position;
        if((*position)->key > hashFunction(keyWord))
        {
            (*position) = (*position)->leftChild;
        }
        else if((*position)->key < hashFunction(keyWord))
        {
            (*position) = (*position)->rightChild;
        }   
    }  

    //DELETING A NODE
    if((*position) != NULL)
    {
        //LEAF NODE
        if(((*position)->rightChild == NULL) && ((*position)->leftChild == NULL))
        {
            delete((*position));
            if(prev->key > hashFunction(keyWord))
            {
                prev->leftChild = NULL;
            }
            else
            {
                prev->rightChild = NULL;
            }

            cout << "haba 1" << endl; 
            return 0;
        }

        //ONE CHILD NODE
        if(((*position)->rightChild == NULL) || ((*position)->leftChild == NULL))
        {
            Node *temp;
            if((*position)->rightChild == NULL) temp = (*position)->leftChild;
            else temp = (*position)->rightChild;

            delete(*position);
            if(prev->key > hashFunction(keyWord))
            {
                prev->leftChild = temp;
            }
            else
            {
                prev->rightChild = temp;
            }

            cout << "haba 2" << endl;
            return 0;
        }

        //TWO CHILDS
        Node *toDelete = (*position);
        Node *minimum;

        while((*position)->leftChild == NULL)
        {
            minimum = (*position);
            (*position) = (*position)->leftChild;
        }

        minimum->leftChild = NULL;

        Node *rightChild = toDelete->rightChild;
        Node *leftChild = toDelete->leftChild;

        delete(toDelete);
        toDelete = (*position);

        toDelete->leftChild = leftChild;
        toDelete->rightChild = rightChild;

        cout << "haba 3" << endl;
        return 0;
    }

    return -1;
}

int main()
{
    int z;
    cin >> z;

    Node *treeRoot = NULL;

    string operationType;
    string keyWord;
    int inputValue;

    for(int k=0; k<z; k++)
    {
        cin >> operationType;
        if(operationType == "SET")
        {
            cin >> keyWord;
            cin >> inputValue;
            set(&treeRoot, keyWord, inputValue);
        }
        if(operationType == "UNSET")
        {
            cin >> keyWord;
            cout << unset(&treeRoot, keyWord) << endl;
        }
        if(operationType == "GET")
        {
            cin >> keyWord;
            get(treeRoot, keyWord);
        }
    }

    return 0;
}