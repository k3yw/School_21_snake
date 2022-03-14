#include <stdlib.h>
#include "./gameobject.h"


/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameObject
 */
__gameobject_vtable__
    __gameobject_vtable___defaults__ = {
    .OnCollide = NULL
    /*.func_test = GameObject__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PGameObject GameObject__new() {
    PGameObject ret = (PGameObject)malloc(sizeof(GameObject));
    ret->call = &__gameobject_vtable___defaults__;
    return ret;
}

/*
void GameObject__func_test(PGameObject instance) {
    PTextureMap test = GAMEOBJECT();
    test->call.func_test(&test);
} 
*/

/* код */
