#include "Sort.h"
#include "../Scene/Scene.h"
#include "../Objects/Object.h"

void SortInstancesDepth(Scene *current_scene)
{
    Instance hold_instance ;

    for (int i = 0 ; i < current_scene -> scene_textures.size() - 1 ; i++)
    {
        for (int j = 0 ; j < current_scene -> scene_textures.size() - i - 1 ; j++)
        {
            if (current_scene -> scene_textures[j].depth > current_scene -> scene_textures[j + 1].depth)
            {
                hold_instance = current_scene -> scene_textures[j] ;
                current_scene -> scene_textures[j] = current_scene -> scene_textures[j + 1] ;
                current_scene -> scene_textures[j + 1] = hold_instance ;
            }
        }
    }

    return ;
}


