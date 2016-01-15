#pragma once
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>

//#define RPIX_IDENTIFIER "RPIX"
//
//#define RPIX_HEADERLENGTH 30
//
//#define RPIX_MAJOR_VERSION 1
//#define RPIX_MINOR_VERSION 0
//
//#define RPIX_COMPRESSION_UNDEFINED 0
//#define RPIX_COMPRESSION_NONE 1
//#define RPIX_COMPRESSION_CCITT_FAX_G3 2
//#define RPIX_COMPRESSION_CCITT_FAX_G4 3
//#define RPIX_COMPRESSION_DEFAULT RPIX_COMPRESSION_NONE
//
//#define RPIX_PIXEL_ORDER_UNDEFINED 0
//#define RPIX_PIXEL_ORDER_NORMAL 1
//#define RPIX_PIXEL_ORDER_REVERSE 2
//#define RPIX_PIXEL_ORDER_DEFAULT RPIX_PIXEL_ORDER_NORMAL
//
//#define RPIX_SCANLINE_ORDER_UNDEFINED 0
//#define RPIX_SCANLINE_ORDER_NORMAL 1
//#define RPIX_SCANLINE_ORDER_INVERSE 2
//#define RPIX_SCANLINE_ORDER_DEFAULT RPIX_SCANLINE_ORDER_NORMAL
//
//#define RPIX_INTERLEAVING_UNDEFINED 0
//#define RPIX_INTERLEAVING_BIP 1
//#define RPIX_INTERLEAVING_BIL 2
//#define RPIX_INTERLEAVING_BSQ 3
//#define RPIX_INTERLEAVING_DEFAULT RPIX_INTERLEAVING_BIP
//
//#define RPIX_CHANNEL_UNDEFINED 0

namespace Utils
{
	//typedef struct RawPixelHeader
	//{
	//	unsigned char identifier[4]; /* Always "RPIX" */

	//	unsigned long	hdrlength; /* Length of this header in bytes */
	//	/* Including the hdrlength field */
	//	/* Not including the identifier field */
	//	/* &k.hdrlength + k.hdrlength = pixels */

	//	unsigned char majorversion; /* Major revision # of RPIX format */
	//	unsigned char minorversion; /* Minor revision # of RPIX format */

	//	unsigned long width;  /* Image width in pixels */
	//	unsigned long height; /* Image height in pixels */
	//	unsigned char comptype;   /* Compression (none, FAXG3, FAXG4, ... ) */
	//	unsigned char pixelorder; /* Pixel order */
	//	unsigned char scnlorder;  /* Scanline order */
	//	unsigned char interleave; /* Interleaving (BIP/BIL/BSQ) */

	//	unsigned char numbands; /* Number of bands in image (1-255) */
	//	unsigned char rchannel; /* Default red channel assignment */
	//	unsigned char gchannel; /* Default green channel assignment */
	//	unsigned char bchannel; /* Default blue channel assignment */
	//	/* Grayscale images are encoded in R */
	//	/* The first band is 1, not 0 */
	//	/* A value of 0 means "no band" */

	//	unsigned char reserved[8]; /* For later use */
	//} RAW_FILE_HEADER;

	int WriteGrayscaleRawmap8Bit(const int & pWidth, const int & pHeight, BYTE * pBuffer, char * pName);
}