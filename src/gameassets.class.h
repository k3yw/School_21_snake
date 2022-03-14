// Copyright 2022 atlaskef
/**
 * @file gameassets.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_GAMEASSETS_CLASS_H_
#define SRC_GAMEASSETS_CLASS_H_

#include "./gameassets.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса GameAssets
 */
typedef struct {
    /*void (*func_test)(PGameAssets);*/
    /// !!! Декларация функций... !!!
} __gameassets_vtable__;

extern __gameassets_vtable__ __gameassets_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации GameAssets
 */
#define GAMEASSETS(...) {\
.call = &__gameassets_vtable___defaults__,\
__VA_ARGS__}

#define NEW_GAMEASSETS() GameAssets__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_GAMEASSETS_CLASS_H_
