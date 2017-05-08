#include "matrix.h"
#include <iostream>

Matrix::Matrix(int newRows, int newColumns)
{
	rows = newRows;
	columns = newColumns;

	//std::cout << "Tworze macierz " << rows << " na " << columns << ": " << std::endl;

	vectorTable = new Vector*[columns];
	for(int k = 0; k < columns; k++)
	{
		vectorTable[k] = new Vector(rows);
	}
}

Matrix::~Matrix()
{
	for(int k = 0; k < columns; k++)
	{
		delete vectorTable[k];
	}

	delete vectorTable;
}

//Operator overload

Matrix & Matrix::operator=(const Matrix &matrix)
{
	if((matrix.columns != this->columns) || (matrix.rows != this->rows))
	{
		std::cout << "error - cant assign different size matricies" << std::endl;
		return *this;
	}

	for(int k = 0; k < columns; k++)
	{
		*(this->vectorTable[k]) = *(matrix.vectorTable[k]);
	}

	return *this;
}

