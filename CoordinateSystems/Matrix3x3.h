#pragma once
#include "Vector3.h"

class Matrix3x3
{
public:

	float elements[3][3] = { { } };
	Matrix3x3();
	Matrix3x3(float _elements[9]);
	Matrix3x3(Vector3 firstRow, Vector3 secondRow, Vector3 thirdRow);

	void operator=(const Matrix3x3 & other);


	Matrix3x3 operator+(const Matrix3x3& other);
	void operator+=(const Matrix3x3& other);

	Matrix3x3 operator-(const Matrix3x3& other);
	void operator-=(const Matrix3x3& other);

	Vector3 operator*(const Vector3& vec);
	Matrix3x3 operator*(const Matrix3x3& other);

	Matrix3x3 operator/(const float& other);

	//Matrix Specific Operations
	void Tranpose();
	float* GetAdjoint();
	float* GetInverse();
	float GetDeterminant();
	~Matrix3x3();

	Matrix3x3 Rotate(const Vector3& rotation);

	Vector3 GetFirstRow();
	Vector3 GetSecondRow();
	Vector3 GetThirdRow();

private:
	const int numOfColums = 3;
	const int numOfRows = 3;
	const int numOfCells = 9;

	float determinant = 0;
	float adj[9] = { };
	float inverse[9] = { };

	Vector3 firstRow;
	Vector3 secondRow;
	Vector3 thirdRow;

	void Adjoint();
	void Determinant();
	void Inverse();
	void Tranpose(float adj[]);

	Matrix3x3 RotateX(const float& theta = 0);
	Matrix3x3 RotateY(const float& theta = 0);
	Matrix3x3 RotateZ(const float& theta = 0);
	
	void Add(const Matrix3x3& other);
	void Subtract(const Matrix3x3& other);

	void UpdateRows();

};

namespace Matrix_Constants {
	const Matrix3x3 identity(new float[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
	const Matrix3x3 one(new float[9]{ 1, 1, 1, 1, 1, 1, 1, 1, 1 });
};

