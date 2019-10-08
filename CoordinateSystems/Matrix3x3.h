#pragma once
//Make adjoint and inverse
//Figure out a way to multiply with a vector
//Create special matrices too, like the identity matrix. 

class Matrix3x3
{
public:

	float elements[9] = { };
	Matrix3x3();
	Matrix3x3(float _elements[9]);

	Matrix3x3 operator+(const Matrix3x3& other);
	void operator+=(const Matrix3x3& other);

	Matrix3x3 operator-(const Matrix3x3& other);
	void operator-=(const Matrix3x3& other);


	float Determinant();

	~Matrix3x3();


private:
	const int numOfColums = 3;
	const int numOfRows = 3;
	const int numOfCells = 9;

	void Add(const Matrix3x3& other);
	void Subtract(const Matrix3x3& other);
};

