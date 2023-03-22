#ifndef OBJECT_H
#define OBJECT_H

#include "../FileDefines.h"
#include SPRITE
#include FUNCTIONS
#include CONSTANTS

#include <vector>
#include <functional>

using namespace std ;

typedef function <void()> void_function ;
class Object ;

enum _events_
{
    /* mouse events given below
    WM_MOUSEMOVE
    WM_LBUTTONDBLCLK
    WM_LBUTTONDOWN
    WM_LBUTTONUP
    WM_MBUTTONDBLCLK
    WM_MBUTTONDOWN
    WM_MBUTTONUP
    WM_RBUTTONDBLCLK
    WM_RBUTTONDBLCLK
    WM_RBUTTONUP
    */
    e_keyboard,
    e_mouse,

    e_loop,

    e_game_start,
    e_game_end,

    e_in_scene,
    e_scene_start,
    e_scene_end ,

    e_collision,
    e_object_at_xy
};

class Event
{
    public:

    Event() ;

    // for in-program use only
    void _sendresponse(bool response) ; // used to trigger event

    int event_type ;
    int event_second_type ;
    int event_collusion_x ;
    int event_collusion_y ;
    int event_click_x ;
    int event_click_y ;
    Object *event_collusion_obj ;
    void *event_scene ;
    void_function event_function ;
};

class Object
{
    public:

    Object() ;

    // Object Properties
    void AddObjectSprite(Sprite& spr) ;
    void SetObjectVisible(bool visible_ = false) ;

    // Events
    void InitObjectAtXYEvent(Object &obj, int x, int y) ;
    void InitKeyboardEvent(int keystroke, void_function kfunction) ;
    void InitMouseEvent(int mouse_button, void_function mfunction) ;
    void InitLoopEvent( void_function lfunction) ;
    void InitCollusionEvent(Object &obj, void_function cfunction) ;
    void InitEvent(int type, void_function efunction) ;
    void InitInSceneEvent(void *scene, void_function scene_function) ;

    // for internal use only
    void _SendMsg(int etype) ;
    void _MsgCheckInScene() ;
    void __SendMsg(Event etype) ;
    bool _EventExists(int etype) ;
    void CheckCollusion() ;

    int obj_x ;
    int obj_y ;
    int obj_depth ;
    bool visible ;
    vector <Event> obj_events ;
    Sprite *obj_sprite ;

    int save_ox ; // saved x value
    int save_oy ; // saved y value
    bool restore ;
};

// for placing instances in rooms

class Instance
{
    public :

    void _UpdateFrame() ;
    Instance() ;

    Texture *_texture ;
    int *origin_x ;
    int *origin_y ;
    int *spd ;
    bool *o_visible ;
    int depth ;
    int pixel_x ;
    int pixel_y ;
    int objp ;
    int current_frame ; // last frame
} ;

#endif // OBJECT_H
