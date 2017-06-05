#include <iostream>
#include "vector.h"
#include "matrix.h"

/*Bartlomiej Fryz*/

int main(int argc, char *argv[])
{
	Matrix haba(3, 3);
	std::cin >> haba;

	std::cout << haba[2];

	return 0;
}
