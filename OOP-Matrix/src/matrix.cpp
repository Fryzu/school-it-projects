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

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2)
{
	Matrix result(matrix1.rows, matrix1.columns);
	if((matrix1.columns != matrix2.columns) || (matrix1.rows != matrix2.rows))
	{
		std::cout << "error - cant add different size matricies" << std::endl;
		return result;
	}

	for(int k = 0; k < matrix1.columns; k++)
	{
		*(result.vectorTable[k]) = *(matrix1.vectorTable[k]) + *(matrix2.vectorTable[k]); 
	}

	return result;
}

Matrix operator-(const Matrix &matrix1, const Matrix &matrix2)
{
	Matrix result(matrix1.rows, matrix1.columns);
	if((matrix1.columns != matrix2.columns) || (matrix1.rows != matrix2.rows))
	{
		std::cout << "error - cant add different size matricies" << std::endl;
		return result;
	}

	for(int k = 0; k < matrix1.columns; k++)
	{
		*(result.vectorTable[k]) = *(matrix1.vectorTable[k]) - *(matrix2.vectorTable[k]); 
	}

	return result;	
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2)
{
	Matrix result(matrix1.columns, matrix2.rows);
	if(matrix1.columns != matrix2.rows)
	{
		std::cout << "error - cant multiply different size matricies" << std::endl;
		return result;
	}
	
	for(int y1 = 0; y1 < matrix1.rows; y1++)
	{
		for(int x2 = 0; x2 < matrix2.columns; x2++)
		{
		      int add = 0;
		      
		      for(int k = 0; k < matrix1.columns; k++)
		      {
			  add = add + matrix1.vectorTable[k]->numberTable[y1] * matrix2.vectorTable[x2]->numberTable[k];   
		      }
		}
	}
	
	return result;
}

std::ostream& operator<<(std::ostream &outstream, const Matrix& matrix)
{
	for(int k = 0; k < matrix.columns; k++)
	{
		outstream << *(matrix.vectorTable[k]) << std::endl;
	}

	return outstream;
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2)
{
	if((matrix1.columns != matrix2.columns) || (matrix1.rows != matrix2.rows))
	{
		std::cout << "error - cant compare different size matricies" << std::endl;
		return false;
	}

	bool result = true;
	for(int k = 0; k < matrix1.columns; k++)
	{
		if(matrix1.vectorTable[k] != matrix2.vectorTable[k]) result = false;
	}

	return result;
}

bool operator!=(const Matrix& matrix1, const Matrix& matrix2)
{
	if(matrix1 == matrix2) return false;
	else return true;
}

Matrix& operator+=(Matrix& matrix1, const Matrix& matrix2)
{
	matrix1 = matrix1 + matrix2;

	return matrix1;
}

Matrix& operator-=(Matrix& matrix1, const Matrix& matrix2)
{
	matrix1 = matrix1 - matrix2;

	return matrix1;
}


