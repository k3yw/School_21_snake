#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>

#include "./game_defaults.h"
#include "./renderengine.h"
#include "./textures/wall.h"
#include "./texturemap.h"
#include "./gameassets.h"
void RenderVoid(int x, int y);
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

PTextureMap TextureMap__new(PRawTexture texture) {
    PTextureMap ret = (PTextureMap)malloc(sizeof(TextureMap));
    ret->call = &__texturemap_vtable___defaults__;
    ret->test = 0;
    ret->buffer = malloc(sizeof(RawTexture));
    memcpy(ret->buffer, texture, sizeof(RawTexture));
    return ret;
}

char* pixel_buffer[TILE_WIDTH * TILE_SIZE_X][TILE_HEIGHT * TILE_SIZE_Y];

void TextureMap__Test_Function(PTextureMap instance) {
    printf("test %d\n", instance->test);
}

void RenderVoid(int x, int y) {
    x = x * 3;
    y = y * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            move(y + j, x + i);
            printw(" ");
        }
    }
}

void TextureMap__Render(PTextureMap instance, int x, int y) {
    /* printf("                   \n");
    printf("                   \n");
    printf("                   \n"); */
    /* if (instance == NULL || instance->buffer == NULL) {
        return;
    } */
    x = x * 3;
    y = y * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            move(y + j, x + i);
            if (instance == NULL || instance->buffer == NULL) {
                printw(" ");
            } else {
                printw("%s", (*instance->buffer)[j][i]);
            }
            
        }
    }
    
}

#include "./textures/wall.h"

int main() {
    RenderEngine render = RENDERENGINE();
    render.call->Init(&render);
    PGameAssets tt_o = NEW_GAMEASSETS();
   /*  RawTexture tt = {
        {Q_BLOCK1, W_BLOCK1, E_BLOCK1},
        {A_BLOCK1, S_BLOCK1, A_BLOCK1},
        {Z_BLOCK1, W_BLOCK1, C_BLOCK1},
    };
    TextureMap__new(tt = {
        {Q_BLOCK1, W_BLOCK1, E_BLOCK1},
        {A_BLOCK1, S_BLOCK1, A_BLOCK1},
        {Z_BLOCK1, W_BLOCK1, C_BLOCK1},
    }); */
    RawTexture tt = {
        {Q_BLOCK1, W_BLOCK1, E_BLOCK1},
        {A_BLOCK1, S_BLOCK1, A_BLOCK1},
        {Z_BLOCK1, W_BLOCK1, C_BLOCK1},
    };
    PTextureMap test = NEW_TEXTUREMAP(&tt);
    /* test.call->Render(&test, 0, 0);
    test.call->Render(&test, 1, 0);
    clear();
    test.call->Render(&test, 1, 0);
    test.call->Render(&test, 2, 0); */

    for (int x = 0; x < TILE_WIDTH; x++)
        {
            for (int y = 0; y < TILE_HEIGHT; y++)
            {
                PGameObject object = tt_o->objects[x][y];
                int new_x = object->x + object->x_vel;
                int new_y = object->y + object->y_vel;
                PGameObject tmp = tt_o->objects[new_x][new_y];
                if (tmp != NULL && tmp->has_collision) {
                    tmp->call->OnCollide(tmp, object);
                }

                if (object == NULL) {
                    RenderVoid(x, y);
                    continue;
                }
/*                 if (object == NULL) {
                    RenderVoid(x, y);
                    continue;
                }
                
                PTextureMap texture = object->texture;
                if (texture == NULL || texture->call == NULL ) {
                    RenderVoid(x, y);
                    continue;
                } */

                object->call->Render(object, x, y);

/*                 texture->call->Render(texture, x, y); */
            }
        }

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
/*                 if (object == NULL) {
                    RenderVoid(x, y);
                    continue;
                }
                
                PTextureMap texture = object->texture;
                if (texture == NULL || texture->call == NULL ) {
                    RenderVoid(x, y);
                    continue;
                } */

                object->call->Render(object, x, y);

/*                 texture->call->Render(texture, x, y); */
            }
        }
        test->call->Render(test, i + 1, 5);
        refresh();
        usleep(500000);
    }
    

    render.call->Destroy(&render);
    return 0;
}