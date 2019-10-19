#pragma once
class Vector4
{
public:
	Vector4();
	Vector4(float _x, float _y, float _z, float _w);

	Vector4 operator*(const float& other);
	void operator*=(const float& other);

	float Dot(const Vector4& other);

	~Vector4();
private:
	float x;
	float y;
	float z;
	float w;
};

