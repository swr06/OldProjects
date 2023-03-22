#ifndef RENDER_H
#define RENDER_H

#include <gdiplus.h>
#include <windows.h>
#include <string>

#include "../FileDefines.h"
#include "png32/png32_helper.h"
#include BGIM_TYPES
#include GRAPHICS
#include TEXTURE

using namespace std ;
using namespace Gdiplus ;

void RenderImageFile(Texture *texture, int left, int top, int right, int bottom, int frame) ;

#endif // RENDER_H
