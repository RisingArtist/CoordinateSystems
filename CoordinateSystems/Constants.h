#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
namespace Constant {

	float ConvertToDegrees(float radian)
	{
		return radian * (180 / M_PI);
	}

	float ConvertToRadians(float degree)
	{
		return degree * (M_PI / 180);
	}
};