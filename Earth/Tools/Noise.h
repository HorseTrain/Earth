#pragma once

#include "inttypes.h"
#include "assert.h"
#include "random"
#include "math.h"

static uint32_t hash(uint32_t x) 
{
	x += (x << 10u);
	x ^= (x >> 6u);
	x += (x << 3u);
	x ^= (x >> 11u);
	x += (x << 15u);
	return x;
}

static int GetHeightRaw(int sx)
{
	srand(hash(sx));

	int hm = rand() & UCHAR_MAX;

	return hm;
}

static float MCos(float x)
{
	return (cos(x * 3.14159265358979323846) / 2.0f) + 0.5f;
}

static float Slerp(float l, float r, float dis)
{
	assert(dis >= 0 && dis <= 1);

	dis = MCos(1 - dis);

	return l + ((r - l) * dis);
}

static float GetDec(float test)
{
	return test - (int)test;
}

static float GetHeight1D(float loc)
{
	loc = abs(loc);

	float h0 = GetHeightRaw((int)loc);
	float h1 = GetHeightRaw((int)loc + 1);

	return Slerp(h0, h1, GetDec(loc)) / UCHAR_MAX;
}

static float GetHeight2D(float x, float y)
{
	float hx = GetHeight1D(x);
	float hy = GetHeight1D(y);

	return (hx + hy) / 2.0;
}

static float GetHeight3D(float x, float y, float z)
{
	float hx = GetHeight1D(x);
	float hy = GetHeight1D(y);
	float hz = GetHeight1D(z);

	return (hx + hy + hz) / 3.0;
}