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
#ifndef SRC_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_H_

struct GameObject;
typedef struct GameObject* PGameObject; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PGameObject GameObject__new();
/*void GameObject__func_test(PGameObject instance);*/
/////////////////////////////////////////////////////////////////////

#include "gameobject.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса GameObject
 */
typedef struct GameObject {
    __gameobject_vtable__ * call;
    /// !!!! Объявлять переменные тута !!!!
} GameObject;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_GAMEOBJECT_H_
