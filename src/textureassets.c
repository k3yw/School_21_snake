#include <stdlib.h>
#include "./textureassets.h"
#include "./renderengine.h"
#include "./texturemap.h"
#include "./textures/wall.h"

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
    RawTexture tt = {
        {Q_BLOCK1, W_BLOCK1, E_BLOCK1},
        {A_BLOCK1, S_BLOCK1, A_BLOCK1},
        {Z_BLOCK1, W_BLOCK1, C_BLOCK1},
    };
    instance->bank->call->add(instance->bank, (void *)NEW_TEXTUREMAP(&tt));
}

/* код */
