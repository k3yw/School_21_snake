// Copyright 2022 atlaskef
/**
 * @file renderengine.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_RENDERENGINE_H_
#define SRC_RENDERENGINE_H_

#include "game_defaults.h"
#include "gameengine.h"

struct RenderEngine;
typedef struct RenderEngine* PRenderEngine; 
typedef char* RawTexture[TILE_SIZE_X][TILE_SIZE_Y];
typedef RawTexture* PRawTexture;

#include "texturemap.h"

/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PRenderEngine RenderEngine__new();
/*void RenderEngine__func_test(PRenderEngine instance);*/
int RenderEngine__Init(PRenderEngine instance);
int RenderEngine__Destroy(PRenderEngine instance);

int RenderEngine__AppendTexture(PRenderEngine instance, 
    PRawTexture texture);
int RenderEngine__InitTextures(PRenderEngine instance);
int RenderEngine__DestroyTextures(PRenderEngine instance);

int RenderEngine__InitWindow();
int RenderEngine__DestroyWindow(PRenderEngine instance);
/////////////////////////////////////////////////////////////////////

#include "renderengine.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса RenderEngine
 */
typedef struct RenderEngine {
    __renderengine_vtable__ * call;
    PTextureMap Textures[MAX_TEXTURES];
    /// !!!! Объявлять переменные тута !!!!
} RenderEngine;
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


#endif  // SRC_RENDERENGINE_H_
