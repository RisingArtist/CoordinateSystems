#pragma once
#include "Vector3.h"
#include "Vector4.h"

//Note: Did this very quickly. Just implemented stuff that I thought it was necessary to 
//get translation to work. This code can be expanded upon for 4x4 matrix operations like the 3x3
class Matrix4x4
{
public:
	float elements[4][4] = { { } };
	Matrix4x4();
	Matrix4x4(float _elements[16]);
	Matrix4x4(Vector3 firstRow, Vector3 secondRow, Vector3 thirdRow);

	Matrix4x4 operator*(const Matrix4x4& other);
	Vector4 operator*(const Vector4& other);
	void Translate(const Vector3& _translate);

	~Matrix4x4();

private:
	const int numOfRows = 4;
	const int numOfColumns = 4;
	const int numOfCells = 16;

	Vector4 firstRow;
	Vector4 secondRow;
	Vector4 thirdRow;
	Vector4 fourthRow;

};

namespace Matrix4_Constants {
	const Matrix4x4 Identity(new float[16]{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
}

