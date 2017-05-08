#include "vector.h"
#include <iostream>
#include <limits>

Vector::Vector(int new_size)
{
	size = new_size;
	numberTable = new int[size];

	//creating a zero vector
	zeroInsert();
}

Vector::~Vector()
{
	delete numberTable;
}

void Vector::numberInsert(void)
{
	std::cout << "Podaj wspolrzedne wektora (rozmiar = " << size << "):" << std::endl;

	for(int k = 0; k < size; k++)
	{
		while(true)
		{
			std::cin >> numberTable[k];

			//wrong data input handling
			if(std::cin.fail() == 1)
			{
				std::cout << "error - wrong data input, please insert number" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
			}
			else
				break;
		}
	}
}

void Vector::zeroInsert(void)
{
	for(int k = 0; k < size; k++)
	{
		numberTable[k] = 0;
	}
}

//Overloading functions

Vector & Vector::operator=(const Vector &vector)
{
	if(this->size != vector.size)
	{
		std::cout << "error - cannot assign different size vectors" << std::endl;
		return *this;
	}

	for(int k = 0; k < this->size; k++)
	{
		this->numberTable[k] = vector.numberTable[k];
	}

	return *this;
}

Vector operator+(const Vector &v1, const Vector &v2)
{
	Vector result(v1.size);

	if(v1.size != v2.size)
	{
		std::cout << "error - cannot add different size vectors" << std::endl;
		return result;
	}
	
	for(int k = 0; k < v1.size; k++)
	{
		result.numberTable[k] = v1.numberTable[k] + v2.numberTable[k];
	}

	return result;
}

Vector operator-(const Vector &v1, const Vector &v2)
{
	Vector result(v1.size);

	if(v1.size != v2.size)
	{
		std::cout << "error - cannot add different size vectors" << std::endl;
		return result;
	}

	for(int k = 0; k < v1.size; k++)
	{
		result.numberTable[k] = v1.numberTable[k] - v2.numberTable[k];
	}

	return result;
}

std::ostream & operator<<(std::ostream &outstream, const Vector &vector)
{
	for(int k = 0; k < vector.size; k++)
	{
		outstream << vector.numberTable[k] << std::endl;
	}

	return outstream;
}

bool operator==(const Vector &v1, const Vector &v2)
{
	if(v1.size != v2.size)
	{
		std::cout << "error - cannot compare different size vectors" << std::endl;
		return false;
	}

	for(int k = 0; k < v1.size; k++)
	{
		if(v1.numberTable[k] != v2.numberTable[k])
			return false;
	}

	return true;
}

bool operator!=(const Vector &v1, const Vector &v2)
{
	if(v1.size != v2.size)
	{
		std::cout << "error - cannot compare different size vectors" << std::endl;
		return false;
	}

	for(int k = 0; k < v1.size; k++)
	{
		if(v1.numberTable[k] != v2.numberTable[k])
			return true;
	}

	return false;
}

Vector & operator+=(Vector &v1, const Vector &v2)
{
	v1 = v1 + v2;

	return v1;
}

Vector & operator-=(Vector &v1, const Vector &v2)
{
	v1 = v1 - v2;

	return v1;
}
