#ifndef _PNG32_HELPER_
#define _PNG32_HELPER_

#include <windows.h>
#include "libpng/png.h"

/* Inhibit C++ name-mangling for libpng functions but not for system calls. */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct tagPNGINFO
{
	int nWidth;					//width
	int nHeight;				//height
	unsigned char **ppbyRow;	//data:rgba
}PNGINFO;

PNGINFO * Png32_Load(const char * pszFileName);
PNGINFO *Png32_LoadFromMem(unsigned char *pbyData,DWORD dwSize);
void	Png32_Free(PNGINFO * pPngInfo);
void	Png32_Show(HDC hdc,int xDest,int yDest,int nWidth,int nHeight, PNGINFO * pPngInfo,int xSour,int ySour);
HRGN	Png32_MakeRgn(PNGINFO *pPngInfo);

#ifdef __cplusplus
}
#endif

#endif//_PNG32_HELPER_
