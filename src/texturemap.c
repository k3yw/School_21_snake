#include <stdio.h>
#include <curses.h>
#include <unistd.h>

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
    /* printf("                   \n");
    printf("                   \n");
    printf("                   \n"); */
    x = x * 3;
    y = y * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            move(y + j, x + i);
            printw("█", instance->buffer[i][j]);
        }
    }
    
}

#include "./textures/wall.h"

int main() {
    RenderEngine render = RENDERENGINE();
    render.call->Init(&render);
    TextureMap test = TEXTUREMAP(
        .test = 4,
        .buffer = WALL_TEXTURE_
    );
    /* test.call->Render(&test, 0, 0);
    test.call->Render(&test, 1, 0);
    clear();
    test.call->Render(&test, 1, 0);
    test.call->Render(&test, 2, 0); */

    for (size_t i = 0; i < 10; i++)
    {
        clear();
        system("printf '\e[8;35;80t'");
        test.call->Render(&test, i + 2, 5);
        for (int x = 0; x < TILE_WIDTH; x++)
        {
            for (int y = 0; y < TILE_HEIGHT; y++)
            {
                if ((y == 0 || y == TILE_HEIGHT - 1) || (x == 0 || x == TILE_WIDTH - 1)) {
                    test.call->Render(&test, x, y);
                }
            }
        }
        refresh();
        usleep(50000);
    }
    

    render.call->Destroy(&render);
    return 0;
}