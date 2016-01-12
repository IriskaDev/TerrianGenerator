#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>


typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;

struct BITMAP_FILE_HEADER
{
	WORD type;
	DWORD size;
	WORD reserved1;
	WORD reserved2;
	DWORD offBits;
};

struct BITMAP_INFO_HEADER
{
	DWORD size;
	LONG width;
	LONG height;
	WORD planes;
	WORD bitCount;
	DWORD compression;
	DWORD sizeImage;
	LONG xPelsPerMeter;
	LONG yPelsPerMeter;
	DWORD clrUsed;
	DWORD clrImportant;
};

struct RGB_QUAD
{
	BYTE blue;
	BYTE green;
	BYTE red;
	BYTE reserved;
};


BITMAP_FILE_HEADER ConstructFileHeader()
{

};

BITMAP_INFO_HEADER ConstructInfoHeader()
{

};

RGB_QUAD ConstructRGBQuad()
{

};