#pragma once
class Vector3
{
public:
	//Create new vectors
	Vector3();
	Vector3(float _x, float _y = 0, float _z = 0);
	Vector3& operator=(const Vector3& other);

	//Add / Subtract / Scale
	void Add(float _x, float _y, float _z);
	Vector3 operator+(const Vector3& other);
	void operator+=(const Vector3& other);

	void Subtract(float _x, float _y, float _z);
	Vector3 operator-(const Vector3& other);
	void operator-=(const Vector3& other);

	Vector3 operator*(const float& other);
	void operator*=(const float& other);

	//Vector operations
	void Scale(float modifier);
	float Length();
	float Dot(const Vector3& other);
	Vector3 Cross(const Vector3& other);

	~Vector3();

public:
	float x;
	float y;
	float z;
};

