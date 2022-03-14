#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#include "game_defaults.h"
#include "texturemap.h"
#include "./renderengine.h"
#include "./gameengine.h"
#include "gameobject.h"


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
    .DestroyWindow = RenderEngine__DestroyWindow,
    /* .Loop = RenderEngine__Loop */
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

/* void RenderEngine__Loop(PRenderEngine instance, PGameEngine game_engine) {
    for (size_t i = 0; i < 30; i++)
    {
        for (int x = 0; x < TILE_WIDTH; x++)
        {
            for (int y = 0; y < TILE_HEIGHT; y++)
            {
                PGameObject object = tt_o->objects[x][y];

                if (object == NULL) {
                    RenderVoid(x, y);
                    continue;
                }

                object->call->Render(object, x, y);
            }
        }
        refresh();
        usleep(500000);
    }
} */

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
    PRawTexture texture) {
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
    setlocale(LC_ALL, "");
    initscr();
    resize_term(SCREEN_HEIGHT, SCREEN_WIDTH);
    cbreak();
    /* noecho(); */
    return 1;
}

int RenderEngine__DestroyWindow(PRenderEngine instance) {
    getch();
    endwin();
    return 1;
}

/* код */
