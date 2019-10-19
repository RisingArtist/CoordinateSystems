#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float _x, float _y, float _z, float _w = 1);

	Vector4 operator*(const float& other); //TODO: Implement
	void operator*=(const float& other); //TODO: Implement

	float Dot(const Vector4& other);

	~Vector4();
public:
	float x;
	float y;
	float z;
	float w;
};

