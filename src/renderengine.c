#include <ncurses.h>
#include <stdlib.h>
#include "game_defaults.h"
#include "texturemap.h"
#include "./renderengine.h"
#include "./gameengine.h"


/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса RenderEngine
 */
__renderengine_vtable__
    __renderengine_vtable___defaults__ = {
    /*.func_test = RenderEngine__func_test,*/
    .Init = RenderEngine__Init,
    .Destroy = RenderEngine__Destroy,

    .InitTextures = RenderEngine__InitTextures,
    .DestroyTextures = RenderEngine__DestroyTextures,
    .AppendTexture = RenderEngine__AppendTexture,

    .InitWindow = RenderEngine__InitWindow,
    .DestroyWindow = RenderEngine__DestroyWindow
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PRenderEngine RenderEngine__new() {
    PRenderEngine ret = (PRenderEngine)malloc(sizeof(RenderEngine));
    ret->call = &__renderengine_vtable___defaults__;
    return ret;
}


int RenderEngine__Init(PRenderEngine instance) {
    instance->call->InitWindow();
    instance->call->InitTextures(instance);
    return 0;
}

int RenderEngine__Destroy(PRenderEngine instance) {
    instance->call->DestroyWindow(instance);
    instance->call->DestroyTextures(instance);
    return 1;
}


int RenderEngine__AppendTexture(PRenderEngine instance, 
    RawTexture texture) {
    return 1;
}

int RenderEngine__InitTextures(PRenderEngine instance) {
/*     TextureMap test = TEXTUREMAP(
        .test = 4,
        .buffer = {{"x", "_", "x"}, {"_", "x", "_"}, {"x", "_", "x"}}
    );

    instance->Textures[0] = &test; */
    /* instance->Text */
    return 1;
}

int RenderEngine__DestroyTextures(PRenderEngine instance) {
    return 1;
}

int RenderEngine__InitWindow() {
    initscr();
    resize_term(SCREEN_WIDTH, SCREEN_HEIGHT);
    cbreak();
    noecho();
    return 1;
}

int RenderEngine__DestroyWindow(PRenderEngine instance) {
    getch();
    endwin();
    return 1;
}

/* код */
