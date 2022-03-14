#include <stdlib.h>
#include "./gameengine.h"


/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameEngine
 */
__gameengine_vtable__
    __gameengine_vtable___defaults__ = {
    /* .GameLoop = GameEngine__GameLoop */
    /*.func_test = GameEngine__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PGameEngine GameEngine__new() {
    PGameEngine ret = (PGameEngine)malloc(sizeof(GameEngine));
    ret->call = &__gameengine_vtable___defaults__;
    return ret;
}


/* void GameEngine__GameLoop(PGameEngine instance) {

}; */

/*
void GameEngine__func_test(PGameEngine instance) {
    PTextureMap test = GAMEENGINE();
    test->call.func_test(&test);
} 
*/

/* код */
