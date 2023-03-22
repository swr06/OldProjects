#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#define DW_SPACE " "

#include "../FileDefines.h"
#include GAME_SETTINGS
#include GRAPHICS

#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

static FILE* debugfile ;

enum error_lvl
{
    NONE,
    MILD,
    FATAL
};

void InitDebugWindow() ;
void DisplayDebugMessage(string msg) ;
void ThrowError(string errmsg, int level = MILD) ;
void _WriteToDebugFile(string writestr, bool error, int level_) ;

#endif // DEBUGWINDOW_H
