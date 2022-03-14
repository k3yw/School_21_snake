#include <stdlib.h>
#include "./game_defaults.h"
#include "./gameassets.h"
#include "./gameobject.h"
#include "textures/wall.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameAssets
 */
__gameassets_vtable__
    __gameassets_vtable___defaults__ = {
    /*.func_test = GameAssets__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

void custom_on_collide(PGameObject p ) {

}
PGameObject GameAssets__InitWall();
PGameObject GameAssets__InitWall() {
    PGameObject wall = NEW_GAMEOBJECT();
    RawTexture tt = WALL_TEXTURE_;
    wall->call->OnCollide = custom_on_collide;
    
    PTextureMap wall_texture = NEW_TEXTUREMAP(&tt);
    wall->texture = wall_texture;
    wall->has_collision = 1;
    return wall;
}

PGameObject GameAssets__InitSnake(PGameAssets instance) {
    PGameObject ret = NEW_GAMEOBJECT();

    RawTexture head = GOLOVF_PRAVO;
    RawTexture tail = HVOST_LEFT;

    ret->has_collision = 1;
    ret->texture = NEW_TEXTUREMAP(&head);
    ret->child_object = NEW_GAMEOBJECT();
    PGameObject tobj = ret->child_object;
    tobj->has_collision = 1;
    tobj->texture = NEW_TEXTUREMAP(&tail);

    int x_off = 0;
    int y_off = 0;

    instance->objects[20 + x_off][10 + y_off] = ret;

    return ret;
}

PGameObject* GameAssets__Init21Wall(PGameAssets instance) {
    PGameObject* ret =  malloc(sizeof(PGameObject) * 9);/* NEW_GAMEOBJECT(); */
    RawTexture test[9] = { 
        L_21_ID_11, L_21_ID_21, L_21_ID_31, 
        L_21_ID_12, L_21_ID_22, L_21_ID_32, 
        L_21_ID_13, L_21_ID_23, L_21_ID_33 
    };

    PRawTexture head[4] = { &test[0], &test[1], &test[2], &test[3] };

    for (int i = 0; i < 9; i++)
    {
        PGameObject obj = NEW_GAMEOBJECT();
        ret[i] = obj;
        obj->has_collision = 1;
        obj->texture = NEW_TEXTUREMAP(&test[i]);
    }

    int x_off = 2;
    int y_off = 4;

    instance->objects[30 + x_off][10 + y_off] = ret[0];
    instance->objects[31 + x_off][10 + y_off] = ret[1];
    instance->objects[32 + x_off][10 + y_off] = ret[2];

    instance->objects[30 + x_off][11 + y_off] = ret[3];
    instance->objects[31 + x_off][11 + y_off] = ret[4];
    instance->objects[32 + x_off][11 + y_off] = ret[5];

    instance->objects[30 + x_off][12 + y_off] = ret[6];
    instance->objects[31 + x_off][12 + y_off] = ret[7];
    instance->objects[32 + x_off][12 + y_off] = ret[8];

    return ret;
}


PGameAssets GameAssets__new() {
    PGameAssets ret = (PGameAssets)malloc(sizeof(GameAssets));
    ret->call = &__gameassets_vtable___defaults__;
    ret->bank = NEW_DARRAY();

    // INIT
    PGameObject wall = GameAssets__InitWall();
    /* ret->bank->call->add(ret->bank, (void *)wall); */

    for (int x = 0; x < TILE_WIDTH; x++)
    {
        for (int y = 0; y < TILE_HEIGHT; y++)
        {
            ret->objects[x][y] = NULL;
            
            if ((y == 0 || y == TILE_HEIGHT - 1) || (x == 0 || x == TILE_WIDTH - 1)) {
                if (x <= TILE_CENTER_X + 9 && x >= TILE_CENTER_X - 9) {
                    continue;
                } else if (y <= TILE_CENTER_Y + 5 && y >= TILE_CENTER_Y - 5) {
                    continue;
                }
                ret->objects[x][y] = wall;
            }
        }
    }
    GameAssets__Init21Wall(ret);
    GameAssets__InitSnake(ret);
    return ret;
}

/*
void GameAssets__func_test(PGameAssets instance) {
    PTextureMap test = GAMEASSETS();
    test->call.func_test(&test);
} 
*/

/* код */
