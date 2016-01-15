#pragma once
#include <Windows.h>
#include <glm/glm.hpp>
#include <Array2D.h>

typedef unsigned short USHORT;

namespace Utils
{
	const unsigned char NORMAL_BYTEORDER_NORMAL_SCANLINE = 0;
	const unsigned char NORMAL_BYTEORDER_INVERSE_SCANLINE = 1;
	const unsigned char INVERSE_BYTEORDER_NORMAL_SCANLINE = 2;
	const unsigned char INVERSE_BYTEORDER_INVERSE_SCANLINE = 3;

	int Arr2DToArr1DByte(Array2D<float> * data, float maxium, BYTE * output, const USHORT & mode = NORMAL_BYTEORDER_NORMAL_SCANLINE);
}

