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
#ifndef SRC_GAMEASSETS_H_
#define SRC_GAMEASSETS_H_
#include "game_defaults.h"
#include "gameobject.h"
struct GameAssets;
typedef struct GameAssets* PGameAssets; 


/////////////////////////////////////////////////////////////////////
/**
 * !!! Объявлять функции тута !!!
 */

// ...
PGameAssets GameAssets__new();
/*void GameAssets__func_test(PGameAssets instance);*/
/////////////////////////////////////////////////////////////////////

#include "gameassets.class.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Декларация класса GameAssets
 */
typedef struct GameAssets {
    __gameassets_vtable__ * call;
    PGameObject objects[TILE_WIDTH][TILE_HEIGHT];
    /// !!!! Объявлять переменные тута !!!!
} GameAssets;
/////////////////////////////////////////////////////////////////////

#endif  // SRC_GAMEASSETS_H_
