// Copyright 2022 atlaskef
/**
 * @file gameengine.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_GAMEENGINE_CLASS_H_
#define SRC_GAMEENGINE_CLASS_H_

#include "./gameengine.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса GameEngine
 */
typedef struct {
    /*void (*func_test)(PGameEngine);*/
    /// !!! Декларация функций... !!!
} __gameengine_vtable__;

extern __gameengine_vtable__ __gameengine_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации GameEngine
 */
#define GAMEENGINE(...) {\
.call = &__gameengine_vtable___defaults__,\
__VA_ARGS__}

#define NEW_GAMEENGINE() GameEngine__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_GAMEENGINE_CLASS_H_
