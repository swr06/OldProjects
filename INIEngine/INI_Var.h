#ifndef INI_VAR_H
#define INI_VAR_H
#include <string>
#include "INI_Engine.h"

using namespace std ;

enum INIVar_t
{
    ini_tfloat,
    ini_tint,
    ini_tstr,
    ini_tdouble
};

class INI_Var ;
string ini_ReadINIFile(INI_Var *var) ;

class INI_Var
{
    public:

    INI_Var(string label, string ini_filepath)
    {
        var_label = label ;
        var_fpath = ini_filepath ;
        ini_ReadINIFile(this) ;
    }

    int var_type ;
    string var_fpath ;
    string var_label ;
};

#endif // INI_VAR_H
