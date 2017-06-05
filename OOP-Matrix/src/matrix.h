#ifndef MATRIX
#define MATRIX

#pragma once

#include "vector.h"
#include <iostream>

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
		int GetRows()
		{
			return this->rows;
		}
		Matrix& operator=(const Matrix&);
		friend Matrix operator-(const Matrix&, const Matrix&);
		friend Matrix operator+(const Matrix&, const Matrix&);
		friend Matrix operator*(const Matrix&, const Matrix&);
		friend bool operator==(const Matrix&, const Matrix&);
		friend bool operator!=(const Matrix&, const Matrix&);
		friend Matrix& operator+=(Matrix&, const Matrix&);
		friend Matrix& operator-=(Matrix&, const Matrix&);
		friend Matrix& operator*=(Matrix&, const Matrix&);
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		friend std::istream& operator>>(std::istream&, Matrix&);
		Vector& operator[](const int) const;
};

#endif

