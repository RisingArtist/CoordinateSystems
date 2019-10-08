#include "Matrix3x3.h"



Matrix3x3::Matrix3x3()
{
}

Matrix3x3::Matrix3x3(float _elements[9])
{
	for (int cell = 0; cell < this->numOfCells; cell++)
	{
		this->elements[cell] = _elements[cell];
	}
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other)
{
	Matrix3x3 temp;
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		temp.elements[cell] = this->elements[cell] + other.elements[cell];
	}
	return temp;
}

void Matrix3x3::operator+=(const Matrix3x3& other)
{
	Add(other);
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other)
{
	Matrix3x3 temp;
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		temp.elements[cell] = this->elements[cell] - other.elements[cell];
	}
	return temp;
}

void Matrix3x3::operator-=(const Matrix3x3& other)
{
	Subtract(other);
}


float Matrix3x3::Determinant()
{
	return (
		(elements[6] * elements[4] * elements[2] + 
		elements[7] * elements[5] * elements[0] +
		elements[8] * elements[3] * elements[1]) -
		(elements[0] * elements[4] * elements[8] +
		elements[1] * elements[5] * elements[6] +
		elements[2] * elements[3] * elements[7])
		);
}

Matrix3x3::~Matrix3x3()
{
}

void Matrix3x3::Add(const Matrix3x3& other)
{
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		this->elements[cell] += other.elements[cell];
	}
}

void Matrix3x3::Subtract(const Matrix3x3& other)
{
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		this->elements[cell] -= other.elements[cell];
	}
}
