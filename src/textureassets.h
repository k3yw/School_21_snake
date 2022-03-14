// Copyright 2022 atlaskef
/**
 * @file textureassets.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_TEXTUREASSETS_H_
#define SRC_TEXTUREASSETS_H_
#include "./renderengine.h"

struct TextureAssets;
typedef struct TextureAssets* PTextureAssets; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PTextureAssets TextureAssets__new();
void TextureAssets__Init(PTextureAssets instance, PRenderEngine render);
/*void TextureAssets__func_test(PTextureAssets instance);*/
/////////////////////////////////////////////////////////////////////

#include "textureassets.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса TextureAssets
 */
typedef struct TextureAssets {
    __textureassets_vtable__ * call;
    /// !!!! Объявлять переменные тута !!!!
} TextureAssets;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_TEXTUREASSETS_H_
