#ifndef VECTOR
#define VECTOR

#pragma once

#include <iostream>

class Vector
{
	private:
		int size;
		int *numberTable;

	public:
		Vector(int size = 2);
		~Vector();
		void numberInsert(void);
		void zeroInsert(void);

		int *getNumberTable()
		{
			return this->numberTable;
		}

		void setNumberTable(int x, int y)
		{
			this->numberTable[x] = y;
		}

		//overload operators +, -, =, <<, ==, != , +=, -=; >>

		friend Vector operator+(const Vector&, const Vector&);
		friend Vector operator-(const Vector&, const Vector&);
		Vector& operator=(const Vector&);
		friend bool operator==(const Vector&, const Vector&);
		friend bool operator!=(const Vector&, const Vector&);
		friend Vector& operator+=(Vector&, const Vector&);
		friend Vector& operator-=(Vector&, const Vector&);
		friend std::ostream& operator<<(std::ostream&, const Vector&);
		friend std::istream& operator>>(std::istream&, Vector&);
};

#endif

