#include "Vector3.h"
#include "Constants.h"


Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

void inline Vector3::Add(float _x, float _y, float _z)
{
	this->x += _x;
	this->y += _y;
	this->z += _z;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

void Vector3::operator+=(const Vector3& other)
{
	Add(other.x, other.y, other.z);
}

void Vector3::Subtract(float _x, float _y, float _z)
{
	this->x -= _x;
	this->y -= _y;
	this->z -= _z;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

void Vector3::operator-=(const Vector3& other)
{
	Subtract(other.x, other.y, other.z);
}

void Vector3::operator*=(const float& other)
{
	Scale(other);
}

Vector3 Vector3::operator*(const float& other)
{
	return Vector3(x * other, y * other, z * other);
}

void Vector3::Scale(float modifier)
{
	this->x *= modifier;
	this->y *= modifier;
	this->z *= modifier;
}

float Vector3::Length()
{
	return std::sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

float Vector3::Dot(const Vector3& other)
{
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector3 Vector3::Cross(const Vector3& other)
{
	return Vector3(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

Vector3::~Vector3()
{
}
