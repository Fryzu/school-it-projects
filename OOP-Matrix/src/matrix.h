#ifndef MATRIX
#define MATRIX

#pragma once

#include "vector.h"

class Matrix
{
	private:
		int rows;
		int columns;
		Vector ** vectorTable;

	public:
		Matrix(int rows = 2, int columns = 2);
		~Matrix();

		//overload operators: =, +, -, *, ==, !=, +=, -=, *=, <<, >>, [];

		Matrix& operator=(const Matrix&);
};

#endif

