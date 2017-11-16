#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 20

/*Przy pomocy struktur zaimplementować prostą 'bazę danych', 
przechowywaną  w pamięci komputera w postaci tablicy struktur. '
Baza danych' ma stanowić prostą książkę telefoniczną 
(Imię, Nazwisko jako napisy, Numer telefonu jako liczba typu long). 
Program musi pozwalać (poprzez funkcje) na dodanie, usunięcie i przeglądanie wpisów. 
Dane powinny być przechowywane w tablicy dynamicznej. Należy napisać funkcje:
- dodającą do tablicy jeden rekord bazy (czyli powiększającą tablicę o jeden element można wzorować się na zadaniu 
	"Powiększanie tablicy" z tematu "Dynamiczna alokacja pamięci"),
- wyszukującą w bazie (tablicy) rekord o podanym polu Numer (zwracającą indeks znalezionego rekordu lub -1)
- wypisującą element tablicy - tu proszę, aby funkcja otrzymywała adres (wskaźnik) wypisywanego elementu.
- oraz funkcję usuwającą rekord o podanym indeksie tablicy (np. zwróconym przez funkcję wyszukującą) 
  poprzez realokację tablicy (przy przepisywaniu należy pominąć rekord o podanym indeksie).
W programie proszę nie używać zmiennych globalnych.
*/

typedef struct Record {
	char name[MAXLINE];
	char surname[MAXLINE];
	long int number;
} Record;	

int deleteRecord(Record **dataBase, int *dataBaseSize, long int x)
{
	int k;
	int i;

	if(*dataBaseSize==0)
	{
		printf("błąd - pusta tablica\n");
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
		return -1;
	}

	if(x>(*dataBaseSize))
	{
		printf("błąd - poza zakresem\n");
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
		return -1;
	}

	x--;
	(*dataBaseSize)--;

	Record *tempBase = malloc((*dataBaseSize)*sizeof(Record));
	if(tempBase==NULL)
	{
		printf("allocation error\n");
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
		return -1;
	}

	if(*dataBaseSize>0)
	{
		k = 0;
		for(k; k<(*dataBaseSize+1); k++)
		{
			if(k!=x)
			{
				tempBase[i] = (*dataBase)[k];
				i++;
			}
		}
	}
	else
	{
		tempBase=NULL;
	}

	free(*dataBase);
	
	*dataBase = tempBase;
	return 0;
}

void showRecord(Record *dataBase, long int x, int dataBaseSize)
{
	if(x>dataBaseSize)
	{
		printf("błąd - poza zakresem\n");
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
	}
	else
	{	
		printf("Element o numerze:  %ld\n", x);
		fputs((dataBase[x-1]).name, stdout);
		fputs((dataBase[x-1]).surname, stdout);
		printf("%ld\n", (dataBase[x-1]).number);
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
	}
}

int addRecord(Record **dataBase, int *dataBaseSize)
{
	int k;

	(*dataBaseSize)++;

	Record *tempBase = malloc((*dataBaseSize)*sizeof(Record));
	if(tempBase==NULL)
	{
		printf("allocation error\n");
		printf("---------------\n");
		printf("Naciśnij enter aby kontynuować...\n");
		getchar();
		return -1;
	}


	if(*dataBaseSize>1)
	{
		k = 0;
		for(k; k<(*dataBaseSize); k++)
		{
			tempBase[k] = (*dataBase)[k];
		}
	}
	free(*dataBase);

	/*DODAWANIE ELEMENTU*/
	printf("Dodawanie elementu o numerze %i\n", *dataBaseSize);
	printf("Imię:\n");
	fgets((tempBase[*dataBaseSize-1]).name, MAXLINE, stdin);
	printf("Nazwisko:\n");
	fgets((tempBase[*dataBaseSize-1]).surname, MAXLINE, stdin);
	printf("Numer:\n");
	scanf("%ld", &((tempBase[*dataBaseSize-1]).number));
	getchar();
	printf("---------------\n");

	/*POTWIERDZENIE ZAPISANIA ELEMENTU*/
	printf("Dodano element:\n");
	fputs((tempBase[*dataBaseSize-1]).name, stdout);
	fputs((tempBase[*dataBaseSize-1]).surname, stdout);
	printf("%ld\n", (tempBase[*dataBaseSize-1]).number);

	*dataBase = tempBase;
	return 0;
}

void searchRecord(Record *dataBase, int dataBaseSize, long int x)
{
	int k = 0;
	for(k; k<dataBaseSize; k++)
	{
		if(dataBase[k].number==x)
		{
			printf("Szukany element to: %i\n", k+1);
			printf("---------------\n");
			printf("Naciśnij enter aby kontynuować...\n");
			getchar();
			return;
		}
	}
	printf("Nie znaleziono elementu.\n");
	printf("---------------\n");
	printf("Naciśnij enter aby kontynuować...\n");
	getchar();
}

int main()
{
	Record *dataBase = NULL;
	int dataBaseSize = 0;
	int choice = 0;
	long int choice2 = 0;

	//MENU
	while(1)
	{
		printf("Rozmiar tablicy: %i\n", dataBaseSize);
		printf("Menu: --------------------------------------\n");
		printf("dodaj element ---------------------------- 1\n");
		printf("szukaj elementu o numerze telefonu ------- 2\n");
		printf("wypisz element --------------------------- 3\n");
		printf("usuń element ----------------------------- 4\n");
		printf("zakończ ---------------------------------- 5\n");

		scanf("%i", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				addRecord(&dataBase, &dataBaseSize);
				break;
			case 2:
				printf("Podaj numer:\n");
				scanf("%ld", &choice2);
				getchar();
				searchRecord(dataBase, dataBaseSize, choice2);
				break;
			case 3:
				printf("Który element?\n");
				scanf("%ld", &choice2);
				getchar();
				showRecord(dataBase, choice2, dataBaseSize);
				break;
			case 4:
				printf("Który element?\n");
				scanf("%ld", &choice2);
				getchar();
				deleteRecord(&dataBase, &dataBaseSize, choice2);
				break;
			case 5:
				system("clear");
				return 0;
		}

		system("clear");
	}

	return 0;
}