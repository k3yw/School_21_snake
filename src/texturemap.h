// Copyright 2022 atlaskef
/**
 * @file texturemap.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_TEXTUREMAP_H_
#define SRC_TEXTUREMAP_H_

struct TextureMap;
typedef struct TextureMap* PTextureMap; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */
PTextureMap TextureMap__new();
// ...
/* void func_test(PTextureMap instance); */
void TextureMap__Test_Function(PTextureMap instance);
void TextureMap__Render(PTextureMap, int x, int y);
/////////////////////////////////////////////////////////////////////

#include "texturemap.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса TextureMap
 */
typedef struct TextureMap {
    __texturemap_vtable__ * call;
    /// !!!! Объявлять переменные тута !!!!
    int test;
    char * buffer[TILE_SIZE_X][TILE_SIZE_Y];
} TextureMap;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_TEXTUREMAP_H_
