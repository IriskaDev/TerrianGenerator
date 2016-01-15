#include "RawImageUtils.h"



namespace Utils
{
	int WriteGrayscaleRawmap8Bit(const int & pWidth, const int & pHeight, BYTE * pBuffer, char * pName)
	{
		FILE *fp;
		errno_t err = fopen_s(&fp, pName, "wb");

		if (err != 0)
		{
			return 1;
		}
		//fwrite(header, RPIX_HEADERLENGTH, 1, fp);
		fwrite(pBuffer, sizeof(BYTE), pHeight * pWidth, fp);

		fclose(fp);
		return 0;
	}
}