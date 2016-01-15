#include "BitmapUtils.h"


namespace Utils
{
	int WriteGrayscaleBitmap(const int & pWidth, const int & pHeight, BYTE * pBuffer, char * pName)
	{
		int fileHeaderSize = sizeof(BITMAP_FILE_HEADER), infoHeaderSize = sizeof(BITMAP_INFO_HEADER);
		int lineByte = (pWidth + 3) / 4 * 4;
		BITMAP_FILE_HEADER *fileHeader = (BITMAP_FILE_HEADER *)malloc(fileHeaderSize);
		BITMAP_INFO_HEADER *infoHeader = (BITMAP_INFO_HEADER *)malloc(infoHeaderSize);
		RGB_QUAD *quad = (RGB_QUAD *)malloc(256 * sizeof(RGB_QUAD));
		fileHeader->bfType = 0x4D42;
		fileHeader->bfSize = fileHeaderSize + infoHeaderSize + 256 * sizeof(RGB_QUAD)+lineByte * pHeight;
		fileHeader->bfReserved1 = 0;
		fileHeader->bfReserved2 = 0;
		fileHeader->bfOffBits = fileHeaderSize + infoHeaderSize + 256 * sizeof(RGB_QUAD);

		infoHeader->biSize = infoHeaderSize;
		infoHeader->biWidth = pWidth;
		infoHeader->biHeight = pHeight;
		infoHeader->biPlanes = 1;
		infoHeader->biBitCount = 8;
		infoHeader->biCompression = 0;
		infoHeader->biSizeImage = lineByte * pHeight;
		infoHeader->biXPelsPerMeter = 0;
		infoHeader->biYPelsPerMeter = 0;
		infoHeader->biClrUsed = 0;
		infoHeader->biClrImportant = 0;

		for (int i = 0; i < 256; ++i)
		{
			quad[i].rgbRed = quad[i].rgbGreen = quad[i].rgbBlue = i;
			quad[i].rgbReserved = 0;
		}


		FILE *fp;
		errno_t err = fopen_s(&fp, pName, "wb");
		if (err != 0)
		{
			return 1;
		}
		fwrite(fileHeader, fileHeaderSize, 1, fp);
		fwrite(infoHeader, infoHeaderSize, 1, fp);
		fwrite(quad, sizeof(RGB_QUAD), 256, fp);

		if (pWidth < lineByte)
		{
			BYTE * imgWriteBuf = (BYTE *)malloc(lineByte * pHeight);
			for (int i = 0; i < pHeight; ++i)
			{
				for (int j = 0; j < pWidth; ++j)
				{
					*(imgWriteBuf + i * lineByte + j) = *(pBuffer + i * pWidth + j);
				}
			}
			fwrite(imgWriteBuf, pHeight * lineByte, 1, fp);
			free(imgWriteBuf);
		}
		else
		{
			fwrite(pBuffer, pHeight * lineByte, 1, fp);
		}

		fclose(fp);

		free(fileHeader);
		free(infoHeader);
		free(quad);
		return 0;
	}
}