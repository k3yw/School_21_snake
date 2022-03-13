#include <stdio.h>
#include <curses.h>

#include "./game_defaults.h"
#include "./render.h"
#include "./texturemap.h"

char* pixel_buffer[TILE_WIDTH * TILE_SIZE_X][TILE_HEIGHT * TILE_SIZE_Y];

void Test_Function(PTextureMap instance) {
    printf("test %d\n", instance->test);
}

void Render(PTextureMap instance, int x, int y) {
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
    /* printf("start\n"); */
    initscr();
    resize_term(SCREEN_WIDTH, SCREEN_HEIGHT);
    cbreak();
    noecho();
    /* printf("start\n"); */
    /* raw(); */
    TextureMap test = TEXTUREMAP(
        .test = 4,
        .buffer = {{"x", "_", "x"}, {"_", "x", "_"}, {"x", "_", "x"}}
    );

    test.call->Render(&test, 0, 0);
    getch();
    endwin();
    /* test.call->Test_Function(&test); */
    return 0;
}