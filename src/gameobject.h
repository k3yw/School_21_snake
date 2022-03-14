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

#include "./texturemap.h"
struct GameObject;
typedef struct GameObject* PGameObject; 
typedef int (*CollisionFunc)(PGameObject);


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PGameObject GameObject__new();
int GameObject__Render(PGameObject instance, int x, int y);
/*void GameObject__func_test(PGameObject instance);*/
/////////////////////////////////////////////////////////////////////

#include "gameobject.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса GameObject
 */
typedef struct GameObject {
    __gameobject_vtable__ * call;
    PTextureMap texture;
    int has_collision;
    int x;
    int y;
    int x_vel;
    int y_vel;
    CollisionFunc on_collide;
    PGameObject child_object;
    /// !!!! Объявлять переменные тута !!!!
} GameObject;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_GAMEOBJECT_H_
