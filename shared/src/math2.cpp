#include "math2.h"

template<typename T> T clamp(T min, T max, T val)
{
	if (val < min) {
		return min;
	} else if (val > max) {
		return max;
	} else {
		return val;
	}
}

template<typename T> bool between(T min, T max, T val)
{
	return (val >= min && val <= max);
}

int clamp_i(int min, int max, int val)
{
	return clamp<int>(min, max, val);
}

float clamp_f(float min, float max, float val)
{
	return clamp<float>(min, max, val);
}

double clamp_d(double min, double max, double val)
{
	return clamp<double>(min, max, val);
}

bool between_i(int min, int max, int val)
{
	return between<int>(min, max, val);
}

bool between_f(float min, float max, float val)
{
	return between<float>(min, max, val);
}

bool between_d(double min, double max, double val)
{
	return between<double>(min, max, val);
}