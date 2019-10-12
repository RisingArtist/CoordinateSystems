#include <iostream>
#include "Vector3.h"
#include "Matrix3x3.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Vector3& obj);
std::ostream& operator<<(std::ostream& os, const Matrix3x3& obj);
void MatrixTest();
int main()
{
	MatrixTest();
}

std::ostream& operator<<(std::ostream& os, const Vector3& obj)
{
	os << "( " << obj.x << ", " << obj.y << ", " << obj.z << " )";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Matrix3x3& obj)
{
	os << obj.elements[0] << " " << obj.elements[1] << " " << obj.elements[2] << "\n"
		<< obj.elements[3] << " " << obj.elements[4] << " " << obj.elements[5] << "\n"
		<< obj.elements[6] << " " << obj.elements[7] << " " << obj.elements[8] << endl;
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

void MatrixTest()
{
	float vals[9] = { 1, 1, 2, 3, 4, 5, 6, 7, 8 };
	Matrix3x3 mat1(vals);

	cout << "The given matrix is: " << endl;
	cout << mat1;

	cout << "The inverse of the matrix is: " << endl;
	float* inverse = mat1.GetInverse();
	cout << inverse[0] << ", " << inverse[1] << ", " << inverse[2] << endl;
	cout << inverse[3] << ", " << inverse[4] << ", " << inverse[5] << endl;
	cout << inverse[6] << ", " << inverse[7] << ", " << inverse[8] << endl;
}
