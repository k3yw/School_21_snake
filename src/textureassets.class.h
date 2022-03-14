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
#ifndef SRC_TEXTUREASSETS_CLASS_H_
#define SRC_TEXTUREASSETS_CLASS_H_

#include "./textureassets.h"
#include "./renderengine.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса TextureAssets
 */
typedef struct {
    /*void (*func_test)(PTextureAssets);*/
    /// !!! Декларация функций... !!!
    void (*Init)(PTextureAssets, PRenderEngine);
} __textureassets_vtable__;

extern __textureassets_vtable__ __textureassets_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации TextureAssets
 */
#define TEXTUREASSETS(...) {\
.call = &__textureassets_vtable___defaults__,\
__VA_ARGS__}

#define NEW_TEXTUREASSETS() TextureAssets__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_TEXTUREASSETS_CLASS_H_
