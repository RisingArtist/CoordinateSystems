#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(float _elements[16])
{
	for (int cell = 0; cell < numOfCells; cell++)
	{
		int row = cell / numOfRows;
		int col = cell % numOfColumns;
		elements[row][col] = _elements[cell];
	}

	firstRow = Vector4(elements[0][0], elements[0][1], elements[0][2], elements[0][3]);
	secondRow = Vector4(elements[1][0], elements[1][1], elements[1][2], elements[1][3]);
	thirdRow = Vector4(elements[2][0], elements[2][1], elements[2][2], elements[2][3]);
	fourthRow = Vector4(elements[3][0], elements[3][1], elements[3][2], elements[3][3]);
}

Matrix4x4::Matrix4x4(Vector3 firstRow, Vector3 secondRow, Vector3 thirdRow) :
	Matrix4x4(new float[16]{
	firstRow.x, firstRow.y, firstRow.z, 0,
	secondRow.x, secondRow.y, secondRow.z, 0,
	thirdRow.x, thirdRow.y, thirdRow.z, 0,
	0, 0, 0, 1 })
{}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 & other)
{
	Matrix4x4 temp;

	Vector4 other_firstColumn = Vector4(other.elements[0][0], other.elements[1][0], other.elements[2][0], other.elements[3][0]);
	Vector4 other_secondColumn = Vector4(other.elements[0][1], other.elements[1][1], other.elements[2][1], other.elements[3][1]);
	Vector4 other_thirdColumn = Vector4(other.elements[0][2], other.elements[1][2], other.elements[2][2], other.elements[3][2]);
	Vector4 other_fourthColumn = Vector4(other.elements[0][3], other.elements[1][3], other.elements[2][3], other.elements[3][3]);

	temp.elements[0][0] = firstRow.Dot(other_firstColumn);
	temp.elements[0][1] = firstRow.Dot(other_secondColumn);
	temp.elements[0][2] = firstRow.Dot(other_thirdColumn);
	temp.elements[0][3] = firstRow.Dot(other_fourthColumn);

	temp.elements[1][0] = secondRow.Dot(other_firstColumn);
	temp.elements[1][1] = secondRow.Dot(other_secondColumn);
	temp.elements[1][2] = secondRow.Dot(other_thirdColumn);
	temp.elements[1][3] = secondRow.Dot(other_fourthColumn);

	temp.elements[2][0] = thirdRow.Dot(other_firstColumn);
	temp.elements[2][1] = thirdRow.Dot(other_secondColumn);
	temp.elements[2][2] = thirdRow.Dot(other_thirdColumn);
	temp.elements[2][3] = thirdRow.Dot(other_fourthColumn);

	temp.elements[3][0] = fourthRow.Dot(other_firstColumn);
	temp.elements[3][1] = fourthRow.Dot(other_secondColumn);
	temp.elements[3][2] = fourthRow.Dot(other_thirdColumn);
	temp.elements[3][3] = fourthRow.Dot(other_fourthColumn);

	return temp;
}

Vector4 Matrix4x4::operator*(const Vector4& other)
{
	return Vector4(firstRow.Dot(other), secondRow.Dot(other), thirdRow.Dot(other), fourthRow.Dot(other));
}


void Matrix4x4::Translate(const Vector3& _translate)
{
	Vector4 translate(_translate.x, _translate.y, _translate.z);

	elements[0][3] = firstRow.Dot(translate);
	elements[1][3] = secondRow.Dot(translate);
	elements[2][3] = thirdRow.Dot(translate);
}

Matrix4x4::~Matrix4x4()
{
}
