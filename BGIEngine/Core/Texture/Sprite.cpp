#include "Sprite.h"

// void AddSpriteCollusionMask(int collusion_x, int collusion_y) ;

Sprite::Sprite()
{
    sprite_origin_x = 0 ;
    sprite_origin_y = 0 ;
    sprite_speed = DEFAULT_SPRITE_SPD ;
    sprite_texture = NULL ;
    sprite_current_frame = 0 ;
}

void Sprite::InitSprite(Texture &texture, unsigned int speed)
{
    if (texture.texture_empty == false)
    {
        sprite_texture = &texture ;
        sprite_speed = speed ;
    }
}

void Sprite::SetSpriteOrigin(int x, int y)
{
    sprite_origin_x = y ;
    sprite_origin_y = x ;
}

void Sprite::StartSpriteAnimation(int speed)
{
    sprite_speed = speed ;
}
