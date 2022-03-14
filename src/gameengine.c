#include <stdlib.h>
#include "./gameengine.h"
#include "gameobject.h"
#include "inputengine.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameEngine
 */
__gameengine_vtable__
    __gameengine_vtable___defaults__ = {
    /* .Init = GameEngine__Init */
    /* .GameLoop = GameEngine__GameLoop */
    /*.func_test = GameEngine__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

void GameEngine__Init(PGameEngine instance) {
    /* instance->assets = NEW_GAMEASSETS();
    instance->render = NEW_RENDERENGINE(); */
}

PGameEngine GameEngine__new() {
    PGameObject obj = NEW_GAMEOBJECT();
    obj->call->Render(obj, 4, 5);
    PInputEngine input = NEW_INPUTENGINE();
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
