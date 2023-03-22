#include "Scene.h"

Scene::Scene()
{
    scene_grid_x = 0 ;
    scene_grid_y = 0 ;
    scene_x = 0 ;
    scene_y = 0 ;
    scene_camera_x = 0 ;
    scene_camera_y = 0 ;
    scene_strech_bg = true ;
    scene_background = NULL ;
}

Scene::Scene(function <void()> scene_constructor_code)
{
    scene_constructor_code() ;
    scene_grid_x = 0 ;
    scene_grid_y = 0 ;
    scene_x = 0 ;
    scene_y = 0 ;
    scene_camera_x = 0 ;
    scene_camera_y = 0 ;
    scene_strech_bg = true ;
    scene_reset = false ;
    scene_background = NULL ;
}

void Scene::SetScreenReset(bool reset)
{
    scene_reset = reset ;
}

void Scene::SetSceneBackground(Texture *bg)
{
    if (bg != NULL)
    {
        scene_background = bg ;
    }
}

void Scene::SetSceneXY(int x, int y)
{
    if (x > 0 && x <= MAX_SCENE_SIZE_X)
    {
        scene_x = x ;
    }

    if (y > 0 && y <= MAX_SCENE_SIZE_Y)
    {
        scene_y = y ;
    }

    // throw error
}

void Scene::SetSceneVeiw(int new_x, int new_y)
{
    if (new_x > scene_x || new_y > scene_y)
    {
        // throw error
    }

    else
    {
        scene_camera_x = new_x ;
        scene_camera_y = new_y ;
    }
}

int Scene::PlaceObject(Object &obj, int x, int y, int depth)
{
    Instance new_obj ;
    Object *new_obj_p ;

    new_obj.origin_x = &(obj.obj_sprite -> sprite_origin_x) ;
    new_obj.origin_y = &(obj.obj_sprite -> sprite_origin_y) ;
    new_obj._texture = obj.obj_sprite -> sprite_texture ;
    new_obj.spd = &(obj.obj_sprite -> sprite_speed) ;
    new_obj.o_visible = &(obj.visible) ;
    new_obj.pixel_x = x ;
    new_obj.pixel_y = y ;

    if (depth != OBJ_DEPTH)
    {
        new_obj.depth = depth;
    }

    else
    {
        new_obj.depth = obj.obj_depth ;
    }

    if (scene_objects.size() > 0)
    {
        new_obj.objp = scene_objects.size() ;
    }

    else
    {
        new_obj.objp = 0 ;
    }

    new_obj_p = &obj ;
    scene_textures.push_back(new_obj) ;
    scene_objects.push_back(new_obj_p) ;

    return scene_textures.size() ;
}

void Scene::RemoveObject(int id)
{
    scene_textures.erase(scene_textures.begin() + id) ;

    if (scene_textures[id].objp != -1)
    {
        int erase_id = scene_textures[id].objp ;

        scene_objects.erase(scene_objects.begin() + erase_id) ;
    }
}

int Scene::PlaceSprite(Sprite &spr, int x, int y, int depth)
{
    Instance new_spr ;

    new_spr._texture = spr.sprite_texture ;
    new_spr.origin_x = &(spr.sprite_origin_x) ;
    new_spr.origin_y = &(spr.sprite_origin_y) ;
    new_spr.pixel_x = x ;
    new_spr.pixel_y = y ;
    new_spr.depth = depth ;
    new_spr.spd = &(spr.sprite_speed) ;
    scene_textures.push_back(new_spr) ;

    return scene_textures.size() ;
}

void Scene::RemoveSprite(int id)
{
    scene_textures.erase(scene_textures.begin() + id) ;
}
