#include <iostream>
#include "Matrix3x3.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Vector3& obj);
std::ostream& operator<<(std::ostream& os, const Matrix3x3& obj);

void MultiplyMatrixTest();

int main()
{
	Matrix3x3 test = Matrix_Constants::identity;
	cout << "Starting Matrix..." << endl;
	cout << test;

	Vector3 scaleVector(2, 2, 2);
	cout << "Scaling by 2..." << endl;
	Matrix3x3 scaledMat(
		test.GetFirstRow() * scaleVector.x,
		test.GetSecondRow() * scaleVector.y,
		test.GetThirdRow() * scaleVector.z
	);
	cout << scaledMat;
	test = test * scaledMat;

	cout << "Rotating the matrix by 90 on the Z..." << endl;
	Vector3 rotateVector(0, 0, 90);
	test = test.Rotate(rotateVector);
	cout << test;

	Vector3 translateVector(1, 2, 1);
	cout << "Translate by ( 1, 2, 1)..." << endl;
	Matrix3x3 translatedMat(
		test.GetFirstRow() * translateVector.x,
		test.GetSecondRow() * translateVector.y,
		test.GetThirdRow() * translateVector.z
	);
	cout << translatedMat;
}

std::ostream& operator<<(std::ostream& os, const Vector3& obj)
{
	os << "( " << obj.x << ", " << obj.y << ", " << obj.z << " )";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Matrix3x3& obj)
{
	//cout.setf(ios::fixed);
	os  << obj.elements[0][0] << " " << obj.elements[0][1] << " " << obj.elements[0][2] << "\n"
		<< obj.elements[1][0] << " " << obj.elements[1][1] << " " << obj.elements[1][2] << "\n"
		<< obj.elements[2][0] << " " << obj.elements[2][1] << " " << obj.elements[2][2] << endl;
	return os;
}

void vectorTest()
{
	Vector3 vec1;
	Vector3 vec2(1, 2, 3);

	cout << "The two vectors are: " << endl;
	cout << vec1 << " and " << vec2 << endl;

	cout << "Add them together..." << endl;
	cout << vec1 + vec2 << endl;

	cout << "Scaling the second vector by 5..." << endl;
	vec2.Scale(5);
	cout << vec2 << endl;

	cout << "Multiplied second vector by 0.2 and giving the result to the first vector..." << endl;
	vec1 += vec2 * 0.2f;

	cout << "The vectors right now are: " << endl;
	cout << vec1 << " and " << vec2 << endl;

	cout << "First vector dots second vector..." << endl;
	cout << vec1.Dot(vec2) << endl;

	cout << "Setting the second vector to 0, 1, 0..." << endl;
	vec2 = Vector3(0, 1, 0);
	cout << vec2 << endl;

	cout << "Setting the first vector to 2, 0, 0..." << endl;
	vec1 = Vector3(2, 0, 0);
	cout << vec1 << endl;

	cout << "Get the Length of the first vector..." << endl;
	cout << vec1.Length() << endl;

	cout << "First vector crosses second vector..." << endl;
	cout << vec1.Cross(vec2) << endl;
}

void MultiplyMatrixTest()
{
	Matrix3x3 mat1(new float[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	float vals[9] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
	Matrix3x3 mat2(vals);

	std::cout << "Multiplying two matrices together..." << endl;
	std::cout << mat1 * mat2;
}


void MatrixTest()
{
	//float vals[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Matrix3x3 mat1;

	cout << "The given matrix is: " << endl;
	cout << mat1;

	cout << "Finding the determinant..." << endl;
	cout << mat1.GetDeterminant() << endl;

	cout << "The adjoint of the matrix..." << endl;
	float* adj = mat1.GetAdjoint();
	cout << adj[0] << ", " << adj[1] << ", " << adj[2] << endl;
	cout << adj[3] << ", " << adj[4] << ", " << adj[5] << endl;
	cout << adj[6] << ", " << adj[7] << ", " << adj[8] << endl;

	cout << "Getting the inverse of mat1..." << endl;
	float* inv = mat1.GetInverse();
	cout << inv[0] << ", " << inv[1] << ", " << inv[2] << endl;
	cout << inv[3] << ", " << inv[4] << ", " << inv[5] << endl;
	cout << inv[6] << ", " << inv[7] << ", " << inv[8] << endl;

	Vector3 scaleVector(1, 2, 3);
	cout << "Multiplying the matrix by 2..." << endl;
	cout << mat1 * scaleVector << endl;
}

void AddBackLater()
{
	float elements[9];
	cout << "Create a 3x3 matrix for an object: " << endl;

	float number;
	bool valid;
	for (int i = 0; i < 9; i++)
	{
		do
		{
			cout << "Enter for #" << i << ": ";
			cin >> number;
			valid = true;
			if (!cin)
			{
				cout << endl;
				cout << "Invalid Entry. Please enter a number!" << endl;
				valid = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (!valid);

		elements[i] = number;
	}

	Matrix3x3 mat1(elements);
	cout << "The result matrix: " << endl;
	cout << mat1;
}
