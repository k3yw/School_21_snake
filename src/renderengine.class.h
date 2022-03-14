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
#ifndef SRC_RENDERENGINE_CLASS_H_
#define SRC_RENDERENGINE_CLASS_H_

#include <stdlib.h>
#include "game_defaults.h"
#include "./renderengine.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса RenderEngine
 */
typedef struct {
    /*void (*func_test)(PRenderEngine);*/
    /// !!! Декларация функций... !!!
    int (*Init)(PRenderEngine);
    int (*Destroy)(PRenderEngine);

    int (*InitTextures)(PRenderEngine);
    int (*DestroyTextures)(PRenderEngine);
    int (*AppendTexture)(PRenderEngine, RawTexture);

    int (*InitWindow)();
    int (*DestroyWindow)(PRenderEngine);
} __renderengine_vtable__;

extern __renderengine_vtable__ __renderengine_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации RenderEngine
 */
#define RENDERENGINE(...) {\
.call = &__renderengine_vtable___defaults__,\
__VA_ARGS__}

#define NEW_RENDERENGINE() RenderEngine__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_RENDERENGINE_CLASS_H_
