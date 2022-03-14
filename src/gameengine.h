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
#ifndef SRC_GAMEENGINE_H_
#define SRC_GAMEENGINE_H_
/* #include "renderengine.h"
#include "gameassets.h" */
struct GameEngine;
typedef struct GameEngine* PGameEngine; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PGameEngine GameEngine__new();
void GameEngine__Init(PGameEngine instance);
/*void GameEngine__func_test(PGameEngine instance);*/
/////////////////////////////////////////////////////////////////////

#include "gameengine.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса GameEngine
 */
typedef struct GameEngine {
    __gameengine_vtable__ * call;
    /* PRenderEngine render;
    PGameAssets assets; */
    /// !!!! Объявлять переменные тута !!!!
} GameEngine;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_GAMEENGINE_H_
