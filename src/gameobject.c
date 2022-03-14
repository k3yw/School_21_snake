#include <stdlib.h>
#include "./gameobject.h"
#include "renderengine.h"
#include "texturemap.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса GameObject
 */
__gameobject_vtable__
    __gameobject_vtable___defaults__ = {
    .OnCollide = NULL,
    .Render = GameObject__Render
    /*.func_test = GameObject__func_test,*/
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

int GameObject__Render(PGameObject instance, int x, int y) {
    PGameObject object = instance;
    if (object == NULL) {
        return 0;
    }
    
    PTextureMap texture = object->texture;
    if (texture == NULL || texture->call == NULL ) {
        return 0;
    }

    texture->call->Render(texture, x, y);
    PGameObject tmp = NULL;
    /* while ((tmp = object->child_object) != NULL) {
        tmp->call->Render(tmp, x, y);
    } */

    return 1;
}

PGameObject GameObject__new() {
    PGameObject ret = (PGameObject)malloc(sizeof(GameObject));
    ret->call = &__gameobject_vtable___defaults__;
    ret->child_object = NULL;
    ret->has_collision = 0;
    ret->on_collide = NULL;
    ret->texture = NULL;
    ret->x = 0;
    ret->y = 0;
    ret->x_vel = 0;
    ret->y_vel = 0;
    return ret;
}

/*
void GameObject__func_test(PGameObject instance) {
    PTextureMap test = GAMEOBJECT();
    test->call.func_test(&test);
} 
*/

/* код */
