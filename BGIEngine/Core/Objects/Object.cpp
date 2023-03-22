#include "Object.h"

/*
void _SendMsg(int etype) ;
bool _EventExists(int etype) ;
*/

Event::Event()
{
    event_type = -1 ;
    event_second_type = -1 ;
    event_collusion_x = -1 ;
    event_collusion_y = -1 ;
    event_collusion_obj = 0 ;
}

void Event::_sendresponse(bool response)
{
    if (response == true && event_type != 0)
    {
        event_function() ;
    }
}

Object::Object()
{
    visible = true ;
    obj_sprite = NULL ;
    obj_x = 0 ;
    obj_y = 0 ;
    save_ox = 0 ;
    save_oy = 0 ;
    obj_depth = DEFAULT_DEPTH ;
}

void Object::AddObjectSprite(Sprite& spr)
{
    obj_sprite = &spr ;
}

void Object::SetObjectVisible(bool visible_)
{
    visible = visible_ ;
}

void Object::InitKeyboardEvent(int keystroke, void_function kfunction)
{
    Event obj_event ;
    obj_event.event_type = e_keyboard ;
    obj_event.event_second_type = keystroke ;
    obj_event.event_function = kfunction ;
    obj_events.push_back(obj_event) ;
}

void Object::InitMouseEvent(int mouse_button, void_function mfunction)
{
    Event obj_event ;
    obj_event.event_type = e_mouse ;
    obj_event.event_second_type = mouse_button ;
    obj_event.event_function = mfunction ;
    obj_events.push_back(obj_event) ;
}

void Object::InitInSceneEvent(void *scene, void_function scene_function)
{
    Event obj_event ;
    obj_event.event_type = e_in_scene ;
    obj_event.event_scene = scene ;
    obj_event.event_second_type = NULL ;
    obj_event.event_function = scene_function ;
    obj_events.push_back(obj_event) ;
}

void Object::InitLoopEvent(void_function lfunction)
{
    Event obj_event ;
    obj_event.event_type = NULL ;
    obj_event.event_second_type = NULL ;
    obj_event.event_function = lfunction ;
    obj_events.push_back(obj_event) ;
}

void Object::InitCollusionEvent(Object &obj, void_function cfunction)
{
    Event obj_event ;
    obj_event.event_type = e_collision ;
    obj_event.event_second_type = NULL ;
    obj_event.event_collusion_obj = &obj ;
    obj_event.event_function = cfunction ;
    obj_events.push_back(obj_event) ;
}

void Object::InitObjectAtXYEvent(Object &obj, int x, int y)
{
    Event obj_event ;
    obj_event.event_type = e_object_at_xy ;
    obj_event.event_second_type = NULL ;
    obj_event.event_collusion_x = x ;
    obj_event.event_collusion_y = y ;
    obj_events.push_back(obj_event) ;
}

void Object::InitEvent(int type, void_function efunction)
{
    Event obj_event ;
    obj_event.event_type = type ;
    obj_event.event_second_type = NULL ;
    obj_event.event_function = efunction ;
    obj_events.push_back(obj_event) ;
}

void Object::_SendMsg(int etype)
{
    if (etype != e_keyboard || etype != e_mouse || etype != e_collision)
    {
        int esize = obj_events.size() ;

        for (int i = 0 ; i < esize ; i++)
        {
            if (obj_events[i].event_type == etype)
            {
                obj_events[i].event_function() ;
            }
        }
    }
}

void Object::__SendMsg(Event etype)
{
    int oesize = obj_events.size() ;

    for (int i = 0 ; i < oesize ; i++)
    {
        if (etype.event_type == e_collision)
        {
            if (obj_events[i].event_type == etype.event_type)
            {
                if (obj_events[i].event_collusion_obj == etype.event_collusion_obj)
                {
                    obj_events[i].event_function() ;
                }
            }
        }

        else if (obj_events[i].event_type == etype.event_type)
        {
            if (obj_events[i].event_second_type == etype.event_second_type)
            {
                obj_events[i].event_function() ;
            }
        }
    }
}

/*
bool MouseInRange(int minx,int maxx,int miny,int maxy)
{
    int x = mousex ;
    int y = mousey ;

    if (y >= miny) && (y <= maxy) && (x >= minx) && (x <= maxx)
    {
        return true ;
    }

    else
    {
        return false
    }
}
*/

bool Object::_EventExists(int etype)
{
    int event_size = obj_events.size() ;
    bool retval = false ;

    for (int i = 0 ; i < event_size ; i++)
    {
        if (obj_events[i].event_type == etype)
        {
            retval = true ;

            break ;
        }
    }

    return retval ;
}

Instance::Instance()
{
    _texture = 0 ;
    pixel_x = 0 ;
    pixel_y = 0 ;
    origin_x = 0 ;
    origin_y = 0 ;
    spd = 0 ;
    current_frame = 0 ;
    objp = -1 ;
    o_visible = 0 ;
    depth = DEFAULT_DEPTH ;
}

void Instance::_UpdateFrame()
{
    if (current_frame == _texture -> texture_animation.size() - 1) // if the current frame is the last frame
    {
        current_frame = 0 ;
    }

    else
    {
        current_frame++ ;
    }
}
