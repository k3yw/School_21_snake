#include <stdlib.h>
#include "./gameassets.h"


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
    return ret;
}

/*
void GameAssets__func_test(PGameAssets instance) {
    PTextureMap test = GAMEASSETS();
    test->call.func_test(&test);
} 
*/

/* код */
