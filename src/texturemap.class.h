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
#ifndef SRC_TEXTUREMAP_CLASS_H_
#define SRC_TEXTUREMAP_CLASS_H_

#include "./texturemap.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса TextureMap
 */
typedef struct {
    /* void (*func_test)(PTextureMap); */
    /// !!! Декларация функций... !!!
    void (*Test_Function)(PTextureMap);
    void (*Render)(PTextureMap, int, int);
} __texturemap_vtable__;

extern __texturemap_vtable__ __texturemap_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации TextureMap
 */
/* #define TEXTUREMAP(...) {\
.call = &__texturemap_vtable___defaults__,\
__VA_ARGS__} */

#define NEW_TEXTUREMAP(texture) TextureMap__new(texture)
/////////////////////////////////////////////////////////////////////


#endif  // TEXTUREMAP_CLASS_H_
