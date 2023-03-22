#include "Render.h"

void RenderImageFile(Texture *texture, int left, int top, int right, int bottom, int frame)
{
    HDC hdc = BGI__GetWinbgiDC() ;

    if (frame < 0 || texture == NULL)
    {
        // error
    }

    if (texture -> texture_empty == false && texture -> texture_type == t_png)
    {
        if (IsFileExist(texture -> texture_animation[frame].c_str()))
        {
            Png32_Show(hdc,left,top,right,right,Png32_Load(texture -> texture_animation[frame].c_str()),0,0) ;
        }
    }

    else if (texture -> texture_empty == false && (texture -> texture_type == t_bmp || texture -> texture_type == t_gif))
    {
        if (IsFileExist(texture -> texture_animation[frame].c_str()))
        {
            readimagefile(texture -> texture_animation[frame].c_str(),left,top,right,bottom) ;
        }
    }

    else
    {
        // error
    }

    BGI__ReleaseWinbgiDC() ;
}

