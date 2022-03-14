#include <stdlib.h>
#include "./gameengine.h"


/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameEngine
 */
__gameengine_vtable__
    __gameengine_vtable___defaults__ = {
    /*.func_test = GameEngine__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PGameEngine GameEngine__new() {
    PGameEngine ret = (PGameEngine)malloc(sizeof(GameEngine));
    ret->call = &__gameengine_vtable___defaults__;
    return ret;
}

/*
void GameEngine__func_test(PGameEngine instance) {
    PTextureMap test = GAMEENGINE();
    test->call.func_test(&test);
} 
*/

/* код */
