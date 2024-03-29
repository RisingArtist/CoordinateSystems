#include "Vector4.h"



Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}


float Vector4::Dot(const Vector4& other)
{
	return (x * other.x + y * other.y + z * other.z + w * other.w);
}

Vector4::~Vector4()
{
}
