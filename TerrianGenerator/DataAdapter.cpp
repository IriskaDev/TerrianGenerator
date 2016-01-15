#include "DataAdapter.h"

namespace Utils
{

	/*
	*	maxium is the max value in data;
	*	output must be allocated, it's length equals to Array2D<float>.Width() * Array2D<float>.Height();
	*/
	int Arr2DToArr1DByte(Array2D<float> * data, float maxium, BYTE * output, const USHORT & mode)
	{
		int length = data->Height();
		int width = data->Width();

		if (length == 0 || width == 0)
			return 1;

		int outterStep, innerStep;
		int innerStart, outterStart;
		int outterEnd, innerEnd;

		switch (mode)
		{
		case NORMAL_BYTEORDER_NORMAL_SCANLINE:
			outterEnd = -1, innerEnd = width;
			outterStart = length - 1, innerStart = 0;
			outterStep = -1, innerStep = 1;
			break;
		case NORMAL_BYTEORDER_INVERSE_SCANLINE:
			outterEnd = length, innerEnd = width;
			outterStart = 0, innerStart = 0;
			outterStep = 1, innerStep = 1;
			break;
		case INVERSE_BYTEORDER_NORMAL_SCANLINE:
			outterEnd = -1, innerEnd = -1;
			outterStart = length - 1, innerStart = width - 1;
			outterStep = -1, innerStep = -1;
			break;
		case INVERSE_BYTEORDER_INVERSE_SCANLINE:
			outterEnd = length, innerEnd = -1;
			outterStart = 0, innerStart = width - 1;
			outterStep = 1, innerStep = -1;
			break;
		default:
			outterEnd = -1, innerEnd = width;
			outterStart = length - 1, innerStart = 0;
			outterStep = -1, innerStep = 1;
			break;
		}

		int ci = 0;
		int cj = 0;
		for (int i = outterStart; i != outterEnd; i += outterStep)
		{
			cj = 0;
			for (int j = innerStart; j != innerEnd; j += innerStep)
			{
				float height = (*data)[j][i];
				float percent = height / maxium;
				int val = floor(255 * percent);
				*(output + ci*width + cj) = char(val);
				++cj;
			}
			++ci;
		}
		return 0;
	}


} 

