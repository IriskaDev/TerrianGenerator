#include "ParticleSedimetary.h"


namespace TerrianGenerator
{
	void defaultRandInit(unsigned _seed)
	{
		srand(_seed);
	}

	float defaultRand()
	{
		return (float)rand() / RAND_MAX;
	}

	ParticleSedimetary::ParticleSedimetary(
		const int & pWidth, 
		const int & pLength, 
		const int & pHeight, 
		const int & pSearchR, 
		const float & pAThreshold, 
		const float & pPHeight)
		:
		width(pWidth),
		length(pLength),
		height(pHeight),
		searchR(pSearchR),
		srMul2(pSearchR * 2),
		srPow2(pSearchR * pSearchR),
		aThreshold(pAThreshold),
		pHeight(pPHeight)
	{
		startPos = glm::vec3(0.0f, 0.0f, 0.0f);
		InitAField();

		walkerDir8[0] = glm::vec3(-1.0f, 1.0f, .0f);
		walkerDir8[1] = glm::vec3(.0f, 1.0f, .0f);
		walkerDir8[2] = glm::vec3(1.0f, 1.0f, .0f);
		walkerDir8[3] = glm::vec3(-1.0f, .0f, .0f);
		walkerDir8[4] = glm::vec3(1.0f, .0f, .0f);
		walkerDir8[5] = glm::vec3(-1.0f, -1.0f, .0f);
		walkerDir8[6] = glm::vec3(.0f, -1.0f, .0f);
		walkerDir8[7] = glm::vec3(1.0f, -1.0f, .0f);

		walkerDir4[0] = glm::vec3(.0f, -1.0f, .0f);
		walkerDir4[1] = glm::vec3(1.0f, .0f, .0f);
		walkerDir4[2] = glm::vec3(.0f, 1.0f, .0f);
		walkerDir4[3] = glm::vec3(-1.0f, .0f, .0f);

		randInit = &defaultRandInit;
		randFunc = &defaultRand;
	}

	ParticleSedimetary::~ParticleSedimetary()
	{
		DisposeAField();
	}

	int ParticleSedimetary::InitAField()
	{
		//aField = new FloatPtr[width];
		//for (int i = 0; i < width; ++i)
		//{
		//	aField[i] = new float[length];
		//	for (int j = 0; j < length; ++j)
		//	{
		//		aField[i][j] = 0;
		//	}
		//}
		aField = new AFieldArr(width, length, 0);
		return 1;
	}

	int ParticleSedimetary::DisposeAField()
	{
		//for (int i = 0; i < width; ++i)
		//{
		//	delete[] aField[i];
		//}
		//delete[] aField;
		delete aField;
		return 1;
	}

	void ParticleSedimetary::SetStartPos(const glm::vec3 & pStartPos)
	{
		startPos = pStartPos;
	}

	void ParticleSedimetary::SetRandFunc(const rand_init_func & init, const rand_func & func)
	{
		randInit = init;
		randFunc = func;
	}

	int ParticleSedimetary::Walker(const int & steps)
	{
		(*randInit)(time_t(0));
		glm::vec3 curPos = startPos;
		for (int i = 0; i < steps; ++i)
		{
			int dirIdx = (int)((*randFunc)() * 8);
			if (dirIdx >= 8)
				dirIdx = 7;
			int dropNum = 1 + (int)((*randFunc)() * 1);
			glm::vec3 tmpPos = curPos + walkerDir8[dirIdx];
			int tmpX = (int)tmpPos.x;
			int tmpY = (int)tmpPos.y;
			if (tmpX < width && tmpX >= 0 && tmpY < length && tmpY >= 0)
			{
				curPos = tmpPos;
				glm::vec3 center = glm::vec3(tmpX, tmpY, (*aField)[tmpX][tmpY]);
				for (int j = 0; j < dropNum; ++j)
				{
					glm::vec3 dropPos = SearchAvaPosition(center);
					int dropX = (int)dropPos.x, dropY = (int)dropPos.y;
					(*aField)[dropX][dropY] += pHeight;
				}
			}
		}
		return 1;
	}

	glm::vec3 ParticleSedimetary::SearchAvaPosition(const glm::vec3 & pCenter)
	{
		int srp2 = srPow2;
		int curDirIdx = floor((*randFunc)() * 4);
		if (curDirIdx >= 4)
			curDirIdx = 3;
		int dirChangeMark = 0;
		int stepLength = 0;
		glm::vec3 center = glm::vec3(pCenter);
		glm::vec2 vec2Center = glm::vec2(pCenter);
		glm::vec2 curP = glm::vec2(pCenter);
		glm::vec3 centerCpy = pCenter;
		float cAltitude = pCenter.z;
		int min_x = pCenter.x - searchR, max_x = pCenter.x + searchR;
		int min_y = pCenter.y - searchR, max_y = pCenter.y + searchR;
		while (stepLength <= srMul2)
		{
			curDirIdx = (curDirIdx + 1) % 4;
			if (dirChangeMark % 2 == 0)
				++stepLength;
			for (int i = 0; i < stepLength; ++i)
			{
				curP = curP + glm::vec2(walkerDir4[curDirIdx].x, walkerDir4[curDirIdx].y);
				int x = (int)curP.x, y = (int)curP.y;
				if (x < 0 || x >= width)
					continue;
				if (y < 0 || y >= length)
					continue;
				if (glm::length(curP - vec2Center) >= searchR)
					continue;
				if ((*aField)[x][y] <= center.z - aThreshold)
				{
					center = glm::vec3(x, y, (*aField)[x][y]);
					break;
				}
			}
			++dirChangeMark;
		}

		float bias = glm::length(center - centerCpy);
		if (bias < 0.003)
			return center;
		else
			return SearchAvaPosition(center);
	}

}