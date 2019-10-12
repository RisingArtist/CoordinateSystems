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
	Determinant();
	Adjoint();
	Inverse();
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

Matrix3x3 Matrix3x3::operator/(const float& other)
{
	Matrix3x3 temp;
	for (int cell = 0; cell < this->numOfCells; cell++)
	{
		temp.elements[cell] = this->elements[cell] / other;
	}
	return temp;
}


void Matrix3x3::Determinant()
{
	//return 
	determinant = (
		elements[0] * elements[4] * elements[8] +
		elements[1] * elements[5] * elements[6] + 
		elements[2] * elements[3] * elements[7] -
		elements[6] * elements[4] * elements[2] -
		elements[7] * elements[5] * elements[0] -
		elements[8] * elements[3] * elements[1]  
		);
}

void Matrix3x3::Tranpose()
{
	//Deep copy
	float temp[9] = { };
	for (int cell = 0; cell < numOfCells; cell++)
	{
		temp[cell] = elements[cell];
	}

	for (int i = 0; i < numOfCells; i++)
	{
		this->elements[i] = temp[(i * 3) % 8];
	}
	this->elements[8] = temp[8];
}

void Matrix3x3::Adjoint()
{
	adj[0] = (elements[4] * elements[8]) - (elements[5] * elements[7]);
	adj[1] = ((elements[3] * elements[8]) - (elements[5] * elements[6])) * -1;
	adj[2] = (elements[3] * elements[7]) - (elements[6] * elements[4]);
	adj[3] = ((elements[1] * elements[8]) - (elements[2] * elements[7])) * -1;
	adj[4] = (elements[0] * elements[8]) - (elements[6] * elements[2]);
	adj[5] = ((elements[0] * elements[7]) - (elements[6] * elements[1])) * -1;
	adj[6] = (elements[1] * elements[5]) - (elements[4] * elements[2]);
	adj[7] = ((elements[0] * elements[5]) - (elements[3] * elements[2])) * -1;
	adj[8] = (elements[0] * elements[4]) - (elements[3] * elements[1]);
	Tranpose(adj);
}

float* Matrix3x3::GetAdjoint()
{
	Adjoint();
	return adj;
}

float* Matrix3x3::GetInverse()
{
	return inverse;
}

float Matrix3x3::GetDeterminant()
{
	Determinant();
	return determinant;
}

Matrix3x3::~Matrix3x3()
{
}

void Matrix3x3::Tranpose(float matrix[])
{
	//Deep copy
	float temp[9] = { };
	for (int cell = 0; cell < numOfCells; cell++)
	{
		temp[cell] = matrix[cell];
	}

	for (int i = 0; i < numOfCells; i++)
	{
		matrix[i] = temp[(i * 3) % 8];
	}
	matrix[8] = temp[8];
}

void Matrix3x3::Inverse()
{
	if (determinant == 0) return;

	for (int i = 0; i < numOfCells; i++)
	{
		inverse[i] = adj[i] / determinant;
	}
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
