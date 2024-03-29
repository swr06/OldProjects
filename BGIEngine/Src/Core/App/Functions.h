#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#if       _WIN32_WINNT < 0x0500
  #undef  _WIN32_WINNT
  #define _WIN32_WINNT   0x0500
#endif

#include "../FileDefines.h"
#include GRAPHICS
#include CONSTANTS

#include <iostream>
#include <sstream>
#include <math.h>
#include <windows.h>
#include <fstream>
#include <winsock.h>
#include <winsock2.h>
#include <conio.h>

using namespace std ;

enum image_type
{
    t_png,
    t_gif,
    t_bmp,
};

static int mouse_clk ;
static int mouse_clk_x ;
static int mouse_clk_y ;
static const bool mmoveevent = false ;

char *prepend(char* prepend_string, char* _string) ;
bool _GetPJGSize_(const char *fn, bool val) ;
bool _GetPJGSize(char *fn, int *x,int *y) ;
int _GetBmpSize(char* pth, int *x, int *y) ;
long _Extract(FILE *fp1,long offset,int size_) ;
int GetImageType(const char *pth) ;
void GetImageSize(string path, int *x, int *y) ;
int GetImageSize_(string path, bool return_val) ; // return_val : 0 = x, 1 = y
bool IsFileExist(const char *fname) ;
bool AnyMouseClick() ;
void ThrowError(char *err_str) ;
void Error(unsigned short error_num) ;
void HideConsole() ;
void ShowConsole() ;
int GetRecentMouseClick(int &kind, int &x, int &y) ;
void _ClearAllMouseEvents() ;

#endif // FUNCTIONS_H
