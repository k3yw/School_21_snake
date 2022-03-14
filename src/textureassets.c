#include <stdlib.h>
#include "./textureassets.h"
#include "./renderengine.h"
#include "./texturemap.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса TextureAssets
 */
__textureassets_vtable__
    __textureassets_vtable___defaults__ = {
    /*.func_test = TextureAssets__func_test,*/
    .Init = TextureAssets__Init
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PTextureAssets TextureAssets__new() {
    PTextureAssets ret = (PTextureAssets)malloc(sizeof(TextureAssets));
    ret->call = &__textureassets_vtable___defaults__;
    return ret;
}

/*
void TextureAssets__func_test(PTextureAssets instance) {
    PTextureMap test = TEXTUREASSETS();
    test->call.func_test(&test);
} 
*/

void TextureAssets__Init(PTextureAssets instance, PRenderEngine render) {
    /**
     * @brief Тестовая текстура
     */

    /* render->call->AppendTexture(render, ) */
}

/* код */
