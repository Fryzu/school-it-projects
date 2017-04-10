/*biblioteka zarządzania alokacją tablic*/

int arrayCreate(int***, int, int);  //alokuje tablice rozmairu 2. na 3. pod adres 1.
int arrayDelete(int***, int, int); //usuwa tablice dynamiczna
int arrayResize(int***, int, int, int, int);   //przeskalowuje tablice o adresie 1. z rozmairu 2. na 3. w tablice 4. na 5.
int arrayAt(int**, int, int);   //zwraca wartość spod miejsca o współrzednych 2. 3. w tablicy 1.
void arrayInsert(int**,int, int, int);   //wkłada wartość 4. pod miejsce o współrzednych 2, 3 tablicy 1.
void arrayToZero(int**, int, int); //zeruje dana tablice 1. o wymiarach 2. 3.


