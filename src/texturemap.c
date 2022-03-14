#include <stdio.h>
#include <curses.h>

#include "./game_defaults.h"
#include "./renderengine.h"
#include "./texturemap.h"

/////////////////////////////////////////////////////////////////////
/**
 * @brief Инициализация VTable класса TextureMap
 */
__texturemap_vtable__
    __texturemap_vtable___defaults__ = {
    /* .func_test = func_test, */
    .Test_Function = TextureMap__Test_Function,
    .Render = TextureMap__Render
    // !!! Инициализация функций... !!!
};
/////////////////////////////////////////////////////////////////////

PTextureMap TextureMap__new() {
    PTextureMap ret = (PTextureMap)malloc(sizeof(TextureMap));
    ret->call = &__texturemap_vtable___defaults__;
    return ret;
}

char* pixel_buffer[TILE_WIDTH * TILE_SIZE_X][TILE_HEIGHT * TILE_SIZE_Y];

void TextureMap__Test_Function(PTextureMap instance) {
    printf("test %d\n", instance->test);
}

void TextureMap__Render(PTextureMap instance, int x, int y) {
    for (int i = -1; i < 2; i++, x += i)
    {
        for (int j = -1; j < 2; j++, y += j)
        {
            printw("%s", instance->buffer[i + 1][j + 1]);
        
        }
        printw("\n");
    }
   
}



int main() {
    RenderEngine render = RENDERENGINE();
    render.call->Init(&render);

    PRenderEngine test_en = NEW_RENDERENGINE();

    TextureMap test = TEXTUREMAP(
        .test = 4,
        .buffer = {{"x", "_", "x"}, {"_", "x", "_"}, {"x", "_", "x"}}
    );

    test.call->Render(&test, 0, 0);



    render.call->Destroy(&render);
    return 0;
}