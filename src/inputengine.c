#include <stdlib.h>
#include "./inputengine.h"


/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса InputEngine
 */
__inputengine_vtable__
    __inputengine_vtable___defaults__ = {
    /*.func_test = InputEngine__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PInputEngine InputEngine__new() {
    PInputEngine ret = (PInputEngine)malloc(sizeof(InputEngine));
    ret->call = &__inputengine_vtable___defaults__;
    return ret;
}

/*
void InputEngine__func_test(PInputEngine instance) {
    PTextureMap test = INPUTENGINE();
    test->call.func_test(&test);
} 
*/

/* код */
