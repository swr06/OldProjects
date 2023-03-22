#ifndef SPRITE_H
#define SPRITE_H

#include "../FileDefines.h"
#include CONSTANTS
#include FUNCTIONS
#include TEXTURE

class Sprite
{
    public :

    Sprite() ;

    void InitSprite(Texture &texture, unsigned int speed) ;
    void AddSpriteCollusionMask(int collusion_x, int collusion_y) ;
    void StartSpriteAnimation(int speed) ;
    void SetSpriteOrigin(int x, int y) ;

    int sprite_speed ; // in frames
    int sprite_current_frame ;
    int sprite_origin_x ;
    int sprite_origin_y ;
    int sprite_collusion_mask_x ;
    int sprite_collusion_mask_y ;
    int sprite_collusion_location_x ;
    int sprite_collusion_location_y ;
    Texture *sprite_texture ;
};

#endif // SPRITE_H
