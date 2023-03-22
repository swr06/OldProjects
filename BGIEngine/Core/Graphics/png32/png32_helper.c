#include "png32_helper.h"

#ifndef WIDTHBYTES
#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)
#endif

typedef struct tagMEMFILE
{
	unsigned char *pbyData;	//data
	unsigned char *pbyCur;	//cur data
	DWORD dwRemain;			//valid data size
}MEMFILE,*PMEMFILE;

void MemFile_Init(PMEMFILE pMemFile,unsigned char *pbyData,DWORD dwSize)
{
	pMemFile->pbyData=pMemFile->pbyCur=pbyData;
	pMemFile->dwRemain=dwSize;
}

void MemFile_Read(png_structp png_ptr, png_bytep pbyData, png_size_t nLength)
{
	PMEMFILE pMemFile=(PMEMFILE)png_ptr->io_ptr;
	if(pMemFile->dwRemain>=nLength)
	{
		memcpy(pbyData,pMemFile->pbyCur,nLength);
		pMemFile->pbyCur+=nLength;
		pMemFile->dwRemain-=nLength;
	}else
	{
		png_error(png_ptr,"io error");
	}
}

PNGINFO *Png32_LoadFromMem(unsigned char *pbyData,DWORD dwSize)
{
	PNGINFO *pRet=NULL;
	MEMFILE memfile;
	// create read struct
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	// create info struct
	png_infop info_ptr = png_create_info_struct(png_ptr);
	// create private read struct
	MemFile_Init(&memfile,pbyData,dwSize);
	// init io mode
	png_set_read_fn(png_ptr,&memfile,MemFile_Read);
	// read entire image (high level)
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);

	if(info_ptr->valid & PNG_INFO_IDAT && info_ptr->pixel_depth==32)
	{
		int i,j;
		pRet=(PNGINFO*)malloc(sizeof(PNGINFO));
		pRet->nWidth=info_ptr->width;
		pRet->nHeight=info_ptr->height;
		pRet->ppbyRow=info_ptr->row_pointers;
		info_ptr->row_pointers=NULL;
		//do pre-muliple
		for(i=0;i<pRet->nHeight;i++)
		{
			BYTE *pdata=pRet->ppbyRow[i];
			for(j=0;j<pRet->nWidth;j++)
			{
				pdata[0]=(pdata[0]*pdata[3])/255;
				pdata[1]=(pdata[1]*pdata[3])/255;
				pdata[2]=(pdata[2]*pdata[3])/255;
				pdata[3]=~pdata[3];
				pdata+=4;
			}
		}
	}
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	return pRet;
}

PNGINFO *Png32_Load(const char * pszFileName)
{
	FILE* file = fopen(pszFileName, "rb");
	// unable to open
	if (file)
	{
		PNGINFO *pRet=NULL;
		// create read struct
		png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
		// create info struct
		png_infop info_ptr = png_create_info_struct(png_ptr);
		png_init_io(png_ptr, file);
		// read entire image (high level)
		png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);
		fclose(file);

		if(info_ptr->valid & PNG_INFO_IDAT && info_ptr->pixel_depth==32)
		{
			int i,j;
			pRet=(PNGINFO*)malloc(sizeof(PNGINFO));
			pRet->nWidth=info_ptr->width;
			pRet->nHeight=info_ptr->height;
			pRet->ppbyRow=info_ptr->row_pointers;
			info_ptr->row_pointers=NULL;
			//do pre-muliple
			for(i=0;i<pRet->nHeight;i++)
			{
				BYTE *pdata=pRet->ppbyRow[i];
				for(j=0;j<pRet->nWidth;j++)
				{
					pdata[0]=(pdata[0]*pdata[3])/255;
					pdata[1]=(pdata[1]*pdata[3])/255;
					pdata[2]=(pdata[2]*pdata[3])/255;
					pdata[3]=~pdata[3];
					pdata+=4;
				}
			}
		}
		png_destroy_read_struct(&png_ptr, &info_ptr, 0);
		return pRet;
	}else
	{
		return NULL;
	}
}

void	Png32_Free(PNGINFO *pPngInfo)
{
	int row;
	if(!pPngInfo->ppbyRow) return;
	for (row = 0; row < pPngInfo->nHeight; row++)
	{
		free(pPngInfo->ppbyRow[row]);
	}
	free(pPngInfo->ppbyRow);
	free(pPngInfo);
}

void	Png32_Show(HDC hdc,int xDest,int yDest,int nWidth,int nHeight,
				   PNGINFO *pPngInfo,int xSour,int ySour)
{


	if(xSour+nWidth>(int)pPngInfo->nWidth) nWidth=pPngInfo->nWidth-xSour;
	if(ySour+nHeight>(int)pPngInfo->nHeight) nHeight=pPngInfo->nHeight-ySour;
	if(nWidth>0 && nHeight>0)
	{
	HDC hmemdc=0;
	LPBYTE pBitsDest=NULL;
	HBITMAP hbmpDest=0;
	HGDIOBJ hOldBmp=0;
	BITMAPINFO bmi;
	//sour memory
	unsigned char ** row_pointers = pPngInfo->ppbyRow+pPngInfo->nHeight-1-(pPngInfo->nHeight-ySour-nHeight);
	//Do alpla blend
	int nLineTailDest=WIDTHBYTES(24*nWidth)-3*nWidth;
	// Initialize header to 0s.
	ZeroMemory(&bmi, sizeof(bmi));
	// Fill out the fields you care about.
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = nWidth;
	bmi.bmiHeader.biHeight = nHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;

	// Create the surface.
	hmemdc=CreateCompatibleDC(hdc);
	// Get Dest Rectangle memory
	hbmpDest = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS,(void **)&pBitsDest, NULL, 0);
	hOldBmp=SelectObject(hmemdc,hbmpDest);
	BitBlt(hmemdc,0,0,nWidth,nHeight,hdc,xDest,yDest,SRCCOPY);

#ifdef ASM_CORE
	__asm
	{
		push esi
		push edi
		push eax
		push ebx
		push ecx
		push edx
		push es
		push ds

		mov ax,ds
		mov es,ax

		mov edi,pBitsDest
		mov ecx,nHeight
beginy:
		mov ebx, row_pointers
		mov esi,[ebx]
		;//offset picture's left margin
		mov eax,xSour
		imul eax,4		;//4 bytes make up one pixel
		add esi,eax
		mov eax,nWidth
beginx:
			;//get alpla value
			xor ebx,ebx
			mov bl,[esi+3]

			;//blue
			xor dx,dx
			mov dl,[edi];
			imul dx,bx
			add dh,[esi+2]
			mov [edi],dh	;//save result to *pBitsDest
			inc edi
			;//green
			xor dx,dx
			mov dl,[edi];
			imul dx,bx
			add dh,[esi+1]
			mov [edi],dh	;//save result to *pBitsDest
			inc edi
			;//red
			xor dx,dx
			mov dl,[edi];
			imul dx,bx
			add dh,[esi]
			mov [edi],dh	;//save result to *pBitsDest
			inc edi
			add esi,4

			dec eax
			cmp eax,0
			jne beginx
		add edi,nLineTailDest
		sub row_pointers,4	;//next line

		loop beginy

		pop ds
		pop es
		pop edx
		pop ecx
		pop ebx
		pop eax
		pop edi
		pop esi
	}
#else//ASM_CORE
	{
		int i,j;
		BYTE *p1=pBitsDest;
		for(i=0;i<nHeight;i++)
		{
			BYTE *p2=*(row_pointers--);
			for(j=0;j<nWidth;j++)
			{
				*p1++=((p2[3]*(*p1))>>8)+p2[2];
				*p1++=((p2[3]*(*p1))>>8)+p2[1];
				*p1++=((p2[3]*(*p1))>>8)+p2[0];
				p2+=4;
			}
			p1+=nLineTailDest;
		}
	}
#endif//ASM_CORE
	//render
	BitBlt(hdc,xDest,yDest,nWidth,nHeight,hmemdc,0,0,SRCCOPY);
	SelectObject(hmemdc,hOldBmp);
	//Free memory
	DeleteObject(hbmpDest);
	DeleteDC(hmemdc);
	}
}

#define ADD_RECTS_COUNT 40
HRGN	Png32_MakeRgn(PNGINFO *pPngInfo)
{
	HRGN hRgn=NULL;
													// (after processing of current)
	DWORD	dwRectsCount = pPngInfo->nHeight;	// number of rects in allocated buffer
	INT		i, j;									// current position in mask image
	INT		first = 0;								// left position of current scan line
	RECT	rc;
													// where mask was found
	BOOL	wasfirst = FALSE;						// set when mask has been found in current scan line
	BOOL	ismask;									// set when current color is mask color

	// allocate memory for region data
	// region data here is set of regions that are rectangles with height 1 pixel (scan line)
	// that's why first allocation is <bm.biHeight> RECTs - number of scan lines in image
	RGNDATAHEADER* pRgnData = (RGNDATAHEADER*)malloc(sizeof(RGNDATAHEADER) + dwRectsCount * sizeof(RECT) );
	// get pointer to RECT table
	LPRECT pRects = (LPRECT)(pRgnData + 1);
	// zero region data header memory (header  part only)
	memset( pRgnData, 0, sizeof(RGNDATAHEADER) + dwRectsCount * sizeof(RECT) );
	// fill it by default
	pRgnData->dwSize	= sizeof(RGNDATAHEADER);
	pRgnData->iType		= RDH_RECTANGLES;


	for ( i = 0; i<pPngInfo->nHeight;i++ )
	{
		LPBYTE	pColor = pPngInfo->ppbyRow[i];
		for ( j = 0; j < pPngInfo->nWidth; j++ )
		{
			ismask=pColor[3]==0xFF;
			pColor+=4;
			if ( wasfirst )
			{
				if ( ismask )
				{
					// save current RECT
					rc.left=first,rc.right=j,rc.top=i,rc.bottom=i+1;
					pRects[ pRgnData->nCount++ ] = rc;
					// if buffer full reallocate it with more room
					if ( pRgnData->nCount >= dwRectsCount )
					{
						dwRectsCount += ADD_RECTS_COUNT;
						pRgnData=(RGNDATAHEADER*)realloc(pRgnData,sizeof(RGNDATAHEADER) + dwRectsCount * sizeof(RECT) );
						pRects = (LPRECT)(pRgnData + 1);
					}
					wasfirst = FALSE;
				}
			}else if ( !ismask )		// set wasfirst when mask is found
			{
				first = j;
				wasfirst = TRUE;
			}
		}

		if ( wasfirst && !ismask )
		{
			// save current RECT
			rc.left=first,rc.right=j,rc.top=i,rc.bottom=i+1;
			pRects[ pRgnData->nCount++ ] = rc;
			// if buffer full reallocate it with more room
			if ( pRgnData->nCount >= dwRectsCount )
			{
				dwRectsCount += ADD_RECTS_COUNT;
				pRgnData=(RGNDATAHEADER*)realloc(pRgnData,sizeof(RGNDATAHEADER) + dwRectsCount * sizeof(RECT) );
				pRects = (LPRECT)(pRgnData + 1);
			}
			wasfirst = FALSE;
		}
	}
	// create region
	hRgn = ExtCreateRegion( NULL, sizeof(RGNDATAHEADER) + pRgnData->nCount * sizeof(RECT), (LPRGNDATA)pRgnData );
	// release region data
	free(pRgnData);

	return hRgn;
}
