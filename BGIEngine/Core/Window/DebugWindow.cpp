#include "DebugWindow.h"

void InitDebugWindow()
{
    char title[192] ;

    sprintf(title,"%s %s Debug Window",game_title.c_str(),game_version.c_str()) ;
    SetConsoleTitle(title) ;
    debugfile = fopen("test.txt","w") ;
    fprintf(debugfile,"Test") ;

    cout << game_title << DW_SPACE << game_version << DW_SPACE << "By : "
         << game_company << "(" << game_author << ")" << endl << endl ;
}

void DisplayDebugMessage(string msg)
{
    cout << endl << msg ;
    _WriteToDebugFile(msg,false,NONE) ;
}

void ThrowError(string errmsg, int level)
{
    if (level == FATAL)
    {
        showerrorbox(errmsg.c_str()) ;
    }

    else
    {
        cout << endl << "ERROR : " << errmsg << " !" ;
    }

    _WriteToDebugFile(errmsg,true,level) ;
}

void _WriteToDebugFile(string writestr, bool error, int level_)
{
    if (error == true)
    {
        if (level_ == FATAL)
        {
            fprintf(debugfile,"\nFATAL ERROR : ") ;
        }

        else
        {
            fprintf(debugfile,"\nERROR : ") ;
        }
    }

    fprintf(debugfile,"%s",writestr.c_str()) ;
}
