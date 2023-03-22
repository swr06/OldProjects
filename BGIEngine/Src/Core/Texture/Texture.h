#ifndef TEXTURE_H
#define TEXTURE_H

#include "../FileDefines.h"
#include CONSTANTS
#include FUNCTIONS

#include <iostream>
#include <vector>

using namespace std ;

class Texture
{
    public :

    Texture() ;

    vector <string> texture_animation ;
    int texture_x ;
    int texture_y ;
    int texture_type ;
    bool texture_empty ;

    // for internal use only
    void InitTexture(vector <string> animation) ;
    void operator= (vector <string> animation) ;
};

#endif // TEXTURE_H
