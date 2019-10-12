#pragma once
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

	Matrix3x3 operator/(const float& other);

	//Matrix Specific Operations
	void Tranpose();
	float* GetAdjoint();
	float* GetInverse();
	float GetDeterminant();
	~Matrix3x3();

private:
	const int numOfColums = 3;
	const int numOfRows = 3;
	const int numOfCells = 9;

	float determinant = 0;
	float adj[9] = { };
	float inverse[9] = { };

	void Adjoint();
	void Determinant();
	void Inverse();
	void Tranpose(float matrix[]);
	
	void Add(const Matrix3x3& other);
	void Subtract(const Matrix3x3& other);
};

