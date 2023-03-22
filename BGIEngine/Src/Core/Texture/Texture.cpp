#include "Texture.h"

Texture::Texture()
{
    texture_x = 0 ;
    texture_y = 0 ;
    texture_type = -1 ;
    texture_empty = true ;
}

void Texture::InitTexture(vector <string> animation)
{
    int ax ;
    int ay ;

    for (int i = 0 ; i < animation.size() ; i++)
    {
        if (IsFileExist(animation[i].c_str()) == true)
        {
            GetImageSize(animation[i],&ax,&ay) ;

            if (texture_animation.size() == 0)
            {
                GetImageSize(animation[i],&texture_x,&texture_y) ;
                texture_animation.push_back(animation[i]) ;
                texture_empty = false ;
                texture_type = GetImageType(animation[i].c_str()) ;
            }

            else if(ax == texture_x && ay == texture_y && texture_empty == false && texture_type == GetImageType(animation[i].c_str()))
            {
                texture_animation.push_back(animation[i]) ;
            }
        }
    }
}

void Texture::operator= (vector <string> animation)
{
    int ax ;
    int ay ;

    for (int i = 0 ; i < animation.size() ; i++)
    {
        if (IsFileExist(animation[i].c_str()) == true)
        {
            GetImageSize(animation[i],&ax,&ay) ;

            if (texture_animation.size() == 0)
            {
                GetImageSize(animation[i],&texture_x,&texture_y) ;
                texture_animation.push_back(animation[i]) ;
                texture_empty = false ;
                texture_type = GetImageType(animation[i].c_str()) ;
            }

            else if(ax == texture_x && ay == texture_y && texture_empty == false && texture_type == GetImageType(animation[i].c_str()))
            {
                texture_animation.push_back(animation[i]) ;
            }
        }
    }
}

