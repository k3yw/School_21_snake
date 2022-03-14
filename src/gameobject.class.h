// Copyright 2022 atlaskef
/**
 * @file gameobject.h
 * @author atlaskef
 * @brief class-alike ООП декларация структур
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SRC_GAMEOBJECT_CLASS_H_
#define SRC_GAMEOBJECT_CLASS_H_

#include "./gameobject.h"

/////////////////////////////////////////////////////////////////////
/**
 * Декларация Virtual Table класса GameObject
 */
typedef struct {
    /*void (*func_test)(PGameObject);*/
    void (*OnCollide)(PGameObject);
    int (*Render)(PGameObject, int, int);
    /// !!! Декларация функций... !!!
} __gameobject_vtable__;

extern __gameobject_vtable__ __gameobject_vtable___defaults__;
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
/**
 * Декларация макроса для базовой инициализации GameObject
 */
#define GAMEOBJECT(...) {\
.call = &__gameobject_vtable___defaults__,\
__VA_ARGS__}

#define NEW_GAMEOBJECT() GameObject__new()
/////////////////////////////////////////////////////////////////////


#endif  // SRC_GAMEOBJECT_CLASS_H_
