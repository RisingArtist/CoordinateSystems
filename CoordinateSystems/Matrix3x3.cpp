#include "Matrix3x3.h"

Matrix3x3::Matrix3x3()
{
}

Matrix3x3::Matrix3x3(float _elements[9])
{
	for (int cell = 0; cell < numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		elements[row][col] = _elements[cell];
	}
	UpdateRows();
	Determinant();
	Adjoint();
	Inverse();
}

void Matrix3x3::UpdateRows()
{
	firstRow = Vector3(elements[0][0], elements[0][1], elements[0][2]);
	secondRow = Vector3(elements[1][0], elements[1][1], elements[1][2]);
	thirdRow = Vector3(elements[2][0], elements[2][1], elements[2][2]);
}

Matrix3x3::Matrix3x3(Vector3 firstRow, Vector3 secondRow, Vector3 thirdRow)
	: Matrix3x3(new float[9] {firstRow.x, firstRow.y, firstRow.z, secondRow.x, secondRow.y, secondRow.z, 
		thirdRow.x, thirdRow.y, thirdRow.z})
{
	//float _elements[9];
	//_elements[0] = firstRow.x;
	//_elements[1] = firstRow.y;
	//_elements[2] = firstRow.z;
	//_elements[3] = secondRow.x;
	//_elements[4] = secondRow.y;
	//_elements[5] = secondRow.z;
	//_elements[6] = thirdRow.x;
	//_elements[7] = thirdRow.y;
	//_elements[8] = thirdRow.z;
	//Matrix3x3(_elements);
}

void Matrix3x3::operator=(const Matrix3x3& other)
{
	for (int row = 0; row < other.numOfRows; row++)
	{
		for (int col = 0; col < other.numOfColums; col++)
			elements[row][col] = other.elements[row][col];
	}
	UpdateRows();
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other)
{
	Matrix3x3 temp;
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		temp.elements[row][col] = elements[row][col] + other.elements[row][col];
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
		int row = cell / 3;
		int col = cell % 3;
		elements[row][col] = elements[row][col] - other.elements[row][col];
	}
	return temp;
}

void Matrix3x3::operator-=(const Matrix3x3& other)
{
	Subtract(other);
}

Vector3 Matrix3x3::operator*(const Vector3& vec)
{
	Vector3 temp;

	temp.x = (elements[0][0] * vec.x) + (elements[0][1] * vec.y) + (elements[0][2] * vec.z);
	temp.y = (elements[1][0] * vec.x) + (elements[1][1] * vec.y) + (elements[1][2] * vec.z);
	temp.z = (elements[2][0] * vec.x) + (elements[2][1] * vec.y) + (elements[2][2] * vec.z); 
		
	return temp;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other)
{
	Matrix3x3 temp;

	Vector3 firstRow(elements[0][0], elements[0][1], elements[0][2]);	
	Vector3 secondRow(elements[1][0], elements[1][1], elements[1][2]);	
	Vector3 thirdRow(elements[2][0], elements[2][1], elements[2][2]);

	Vector3 other_firstCol(other.elements[0][0], other.elements[1][0], other.elements[2][0]);
	Vector3 other_secondCol(other.elements[0][1], other.elements[1][1], other.elements[2][1]);
	Vector3 other_thirdCol(other.elements[0][2], other.elements[1][2], other.elements[2][2]);

	temp.elements[0][0] = firstRow.Dot(other_firstCol);
	temp.elements[0][1] = firstRow.Dot(other_secondCol);
	temp.elements[0][2] = firstRow.Dot(other_thirdCol);
	temp.elements[1][0] = secondRow.Dot(other_firstCol);
	temp.elements[1][1] = secondRow.Dot(other_secondCol);
	temp.elements[1][2] = secondRow.Dot(other_thirdCol);
	temp.elements[2][0] = thirdRow.Dot(other_firstCol);
	temp.elements[2][1] = thirdRow.Dot(other_secondCol);
	temp.elements[2][2] = thirdRow.Dot(other_thirdCol);

	return temp;
}

Matrix3x3 Matrix3x3::operator/(const float& other)
{
	Matrix3x3 temp;
	for (int cell = 0; cell < this->numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		temp.elements[row][col] = elements[row][col] / other;
	}
	return temp;
}

void Matrix3x3::Tranpose()
{
	//Deep copy
	float temp[3][3] = { };
	for (int cell = 0; cell < numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		temp[row][col] = elements[row][col];
	}

	Vector3 t_firstRow(temp[0][0], temp[1][0], temp[2][0]);
	Vector3 t_secondRow(temp[0][1], temp[1][1], temp[2][1]);
	Vector3 t_thirdRow(temp[0][2], temp[1][2], temp[2][2]);

	elements[0][0] = t_firstRow.x;
	elements[0][1] = t_firstRow.y;
	elements[0][2] = t_firstRow.z;
	elements[1][0] = t_secondRow.x;
	elements[1][1] = t_secondRow.y;
	elements[1][2] = t_secondRow.z;
	elements[2][0] = t_thirdRow.x;
	elements[2][1] = t_thirdRow.y;
	elements[2][2] = t_thirdRow.z;
}

float* Matrix3x3::GetAdjoint()
{
	//Adjoint();
	return adj;
}

float* Matrix3x3::GetInverse()
{
	//Inverse();
	return inverse;
}

float Matrix3x3::GetDeterminant()
{
	//Determinant();
	return determinant;
}

Matrix3x3::~Matrix3x3()
{
}

Matrix3x3 Matrix3x3::Rotate(const Vector3& rotation)
{ 
	Matrix3x3 x = Matrix_Constants::identity;
	Matrix3x3 y = Matrix_Constants::identity;
	Matrix3x3 z = Matrix_Constants::identity;

	if(rotation.x != 0)
		x = RotateX(rotation.x);
	if(rotation.y != 0)
		y = RotateY(rotation.y);
	if(rotation.z != 0)
		z = RotateZ(rotation.z);

	return x * y * z;
}

Vector3 Matrix3x3::GetFirstRow()
{
	return firstRow;
}

Vector3 Matrix3x3::GetSecondRow()
{
	return secondRow;
}

Vector3 Matrix3x3::GetThirdRow()
{
	return thirdRow;
}

Matrix3x3 Matrix3x3::RotateX(const float& theta)
{
	float rad = theta * PI / 180;
	float cosine = cosf(rad);
	float sine = sinf(rad);
	Matrix3x3 rotX(new float[9]{ 1, 0, 0, 0, (fabsf(cosine) < 0.01) ? 0 : cosine, (fabsf(sine) < 0.01) ? 0 : -1 * sinf(rad), 0, (fabsf(sine) < 0.01) ? 0 : sine, (fabsf(cosine) < 0.01) ? 0 : cosine });
	Matrix3x3 result = *this * rotX;
	return result;
}

Matrix3x3 Matrix3x3::RotateY(const float& theta)
{
	float rad = theta * PI / 180;
	float cosine = cosf(rad);
	float sine = sinf(rad);
	Matrix3x3 rotY(new float[9]{ (fabsf(cosine) < 0.01) ? 0 : cosine , 0, (fabsf(sine) < 0.01) ? 0 : sine, 0, 1, 0, (fabsf(sine) < 0.01) ? 0 : -1 * sinf(rad), 0, (fabsf(cosine) < 0.01) ? 0 : cosine });
	Matrix3x3 result = *this * rotY;
	return result;
}

Matrix3x3 Matrix3x3::RotateZ(const float& theta)
{
	float rad = theta * PI / 180;
	float cosine = cosf(rad);
	float sine = sinf(rad);
	Matrix3x3 rotZ(new float[9]{ (fabsf(cosine) < 0.01) ? 0 : cosine, (fabsf(sine) < 0.01) ? 0 : -1 * sinf(rad), 0, (fabsf(sine) < 0.01) ? 0 : sine, (fabsf(cosine) < 0.01) ? 0 : cosine, 0, 0, 0, 1});
	Matrix3x3 result = *this * rotZ;
	return result;
}

void Matrix3x3::Adjoint()
{
	adj[0] = (elements[1][1] * elements[2][2]) - (elements[1][2] * elements[2][1]);
	adj[1] = ((elements[1][0] * elements[2][2]) - (elements[1][2] * elements[2][0])) * -1;
	adj[2] = (elements[1][0] * elements[2][1]) - (elements[2][0] * elements[1][1]);
	adj[3] = ((elements[0][1] * elements[2][2]) - (elements[0][2] * elements[2][1])) * -1;
	adj[4] = (elements[0][0] * elements[2][2]) - (elements[2][0] * elements[0][2]);
	adj[5] = ((elements[0][0] * elements[2][1]) - (elements[2][0] * elements[0][1])) * -1;
	adj[6] = (elements[0][1] * elements[1][2]) - (elements[1][1] * elements[0][2]);
	adj[7] = ((elements[0][0] * elements[1][2]) - (elements[1][0] * elements[0][2])) * -1;
	adj[8] = (elements[0][0] * elements[1][1]) - (elements[1][0] * elements[0][1]);
	Tranpose(adj);
}

void Matrix3x3::Determinant()
{
	determinant = (
		elements[0][0] * elements[1][1] * elements[2][2] +
		elements[0][1] * elements[1][2] * elements[2][0] + 
		elements[0][2] * elements[1][0] * elements[2][1] -
		elements[2][0] * elements[1][1] * elements[0][2] -
		elements[2][1] * elements[1][2] * elements[0][0] -
		elements[2][2] * elements[1][0] * elements[0][1]
		);
}

void Matrix3x3::Inverse()
{
	if (determinant == 0) return;

	for (int i = 0; i < numOfCells; i++)
	{
		inverse[i] = adj[i] / determinant;
	}
}

void Matrix3x3::Tranpose(float adj[])
{
	//Deep copy
	float temp[9] = { };
	for (int cell = 0; cell < numOfCells; cell++)
	{
		temp[cell] = adj[cell];
	}

	for (int i = 0; i < numOfCells; i++)
	{
		adj[i] = temp[(i * 3) % 8];
	}
	adj[8] = temp[8];
}

void Matrix3x3::Add(const Matrix3x3& other)
{
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		elements[row][col] += other.elements[row][col];
	}

	UpdateRows();
}

void Matrix3x3::Subtract(const Matrix3x3& other)
{
	for (int cell = 0; cell < other.numOfCells; cell++)
	{
		int row = cell / 3;
		int col = cell % 3;
		elements[row][col] -= other.elements[row][col];
	}

	UpdateRows();
}
