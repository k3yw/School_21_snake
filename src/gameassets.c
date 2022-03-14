#include <stdlib.h>
#include "./game_defaults.h"
#include "./gameassets.h"
#include "./gameobject.h"

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

PGameAssets GameAssets__new() {
    PGameAssets ret = (PGameAssets)malloc(sizeof(GameAssets));
    ret->call = &__gameassets_vtable___defaults__;

    // INIT
    /* for (int x = 0; x < TILE_WIDTH; x++)
        {
            for (int y = 0; y < TILE_HEIGHT; y++)
            {
                if ((y == 0 || y == TILE_HEIGHT - 1) || (x == 0 || x == TILE_WIDTH - 1)) {
            
                    ret->objects[x][y] = 
                }
            }
        }
 */
    PGameObject wall = NEW_GAMEOBJECT();
    ret->bank->call->add(ret->bank, (void *)wall);

    for (int x = 0; x < TILE_WIDTH; x++)
    {
        for (int y = 0; y < TILE_HEIGHT; y++)
        {
            if ((y == 0 || y == TILE_HEIGHT - 1) || (x == 0 || x == TILE_WIDTH - 1)) {
        
                ret->objects[x][y] = wall;
            }
        }
    }

    return ret;
}

/*
void GameAssets__func_test(PGameAssets instance) {
    PTextureMap test = GAMEASSETS();
    test->call.func_test(&test);
} 
*/

/* код */
