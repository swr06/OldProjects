#ifndef SCENE_H
#define SCENE_H

#include "../FileDefines.h"
#include OBJECT
#include CONSTANTS

#include <functional>
#include <vector>

/*
PlaceObject() ;
DestroyObject() ;
SetRoomBG
PutObjectGrid
PutObject
SetRoomTileGrid
PlaceSprite
SetRoomCreationCode
SetRoomXY
*/

using namespace std ;

const int OBJ_DEPTH = -8 ;

class Scene
{
    public :

    Scene() ; // default constructor
    Scene(function <void()> scene_constructor_code) ; // Room Constructor Code

    int PlaceSprite(Sprite& spr, int x, int y, int depth = DEFAULT_DEPTH) ;
    int PlaceObject(Object& obj, int x, int y, int depth = OBJ_DEPTH) ;
    void SetScreenReset(bool reset) ;
    void SetSceneBackground(Texture *bg) ;
    void SetSceneXY(int x, int y) ;
    void SetSceneVeiw(int new_x, int new_y) ;
    void RemoveObject(int id) ;
    void RemoveSprite(int id) ;

    int scene_grid_x ;
    int scene_grid_y ;
    int scene_x ;
    int scene_y ;
    int scene_camera_x ; // the game window will display from scene_show_x & y to game_window_x & y
    int scene_camera_y ;
    bool scene_reset ;
    bool scene_strech_bg ;

    Texture *scene_background ;
    vector <Instance> scene_textures ; // used for drawing textures at various X and Y coordinates
    vector <Object*> scene_objects ;
    vector <Sprite*> scene_sprites ;
};

#endif // SCENE_H
