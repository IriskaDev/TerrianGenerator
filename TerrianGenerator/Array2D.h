#pragma once
#include <stdlib.h>

namespace Utils
{
	template<typename T>
	class Array2DDataContainer
	{
	private:
		int len;
		T * cursor;
		T * data;
	public:
		Array2DDataContainer() : len(4)
		{
			data = new T[4];
			cursor = data;
		};
		Array2DDataContainer(const Array2DDataContainer<T> & pArrC) : len(pArrC.len)
		{
			data = new T[len];
			cursor = data;
			for (int i = 0; i < len; ++i)
			{
				data[i] = pArrC.data[i];
			}
		};
		Array2DDataContainer(const int & pLen) : len(pLen)
		{
			data = new T[pLen];
			cursor = data;
		};
		Array2DDataContainer(const int & pLen, const T & init) : len(pLen)
		{
			data = new T[pLen];
			cursor = data;
			for (int i = 0; i < pLen; ++i)
			{
				data[i] = init;
			}
		}
		~Array2DDataContainer()
		{
			delete[] data;
		};

		void ResetCursor()
		{
			cursor = data;
		};
		void SetCursor(const int & pOffset)
		{
			cursor = data + pOffset;
		}

		T& operator[](const int & pOffset)
		{
			return *(cursor + pOffset);
		};
	};

	template<typename T>
	class Array2D
	{
	private:
		int width;
		int height;
		Array2DDataContainer<T> * data;
	public:
		Array2D() : width(2), height(2)
		{
			data = new Array2DDataContainer<T>(4);
		};
		Array2D(const Array2D<T> & pArr) : width(pArr.width), height(pArr.height)
		{
			data = new Array2DDataContainer<T>(pArr);
		};
		Array2D(const int & pWidth, const int & pHeight) : width(pWidth), height(pHeight)
		{
			data = new Array2DDataContainer<T>(pWidth * pHeight);
		};
		Array2D(const int & pWidth, const int & pHeight, const T & pInit) : width(pWidth), height(pHeight)
		{
			data = new Array2DDataContainer<T>(pWidth * pHeight, pInit);
		};
		~Array2D()
		{
			delete data;
		};
		int Width()
		{
			return width;
		};
		int Height()
		{
			return height;
		};

		Array2DDataContainer<T>& operator[](const int & row)
		{
			int offset = row * width;
			data->SetCursor(offset);
			return *data;
		};
	};
};
