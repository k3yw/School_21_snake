#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <sys/time.h>

#define TILE_SIZE_X 3
#define TILE_SIZE_Y 3
#define TILE_WIDTH 60
#define TILE_HEIGHT 21


#define PIXEL_BLOCK "█"
#define PIXEL_HALFB "▄"
#define PIXEL_HALFT "▀"
#define SPACE "░"

typedef struct texture_map {
    char * buffer[TILE_SIZE_X][TILE_SIZE_Y];
} texture;

/* char* (*texture_map[3][3])[10]; */
texture * texture_map[10];
char* pixel_buffer[TILE_WIDTH * TILE_SIZE_X][TILE_HEIGHT * TILE_SIZE_Y];

void one_to_nine_character(int index, int x, int y) {
    x = x * 3 + 1;
    y = y * 3 + 1;
    
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            /* pixel_buffer[x + i][y + j] = (*texture_map[index])[i + 1][j + 1]; */
            pixel_buffer[x + i][y + j] = texture_map[index]->buffer[j + 1][i + 1];
        }
    }
}

void draw_final_console() {
    /* for (int i = 0; i < TILE_WIDTH * TILE_SIZE_X; i++) {
        for (int j = 0; j < TILE_HEIGHT * TILE_SIZE_Y; j++) {
            if (pixel_buffer[i][j] == NULL) {
                printf("_");
                continue;
            }
            printf("%s", (pixel_buffer[i][j]));
        }
        printf("\n");
    } */

    for (int y = 0; y < TILE_HEIGHT * TILE_SIZE_Y; y++)
    {
        for (int x = 0; x < TILE_WIDTH * TILE_SIZE_X; x++)
        {
            if (pixel_buffer[x][y] == NULL) {
                printf("_");
                continue;
            }
            printf("%s", (pixel_buffer[x][y]));
        }
        printf("\n");
    }
    
}

void set_big_buff() {
    for (int x = 0; x < (TILE_WIDTH); x++) {
        for (int y = 0; y < TILE_HEIGHT; y++) {
            /* if (i == 0) one_to_nine_character(1, i, j);
            else {
                one_to_nine_character(0, i, j);
            } */
            /* one_to_nine_character(i % 2 , i, j); */
            int is_wall = 0;
            if (y == 0 || y == TILE_HEIGHT - 1) {
                is_wall = 1;
            } else if (x == 0 || x == TILE_WIDTH - 1) {
                is_wall = 1;
            }

            one_to_nine_character(is_wall , x, y);
            /* if (i == 0 || i == TILE_WIDTH - 1) {
                
            } */
        }
    }
}
int main() {
    /* texture texture_first = {
        .buffer = {
            {PIXEL_HALFB, PIXEL_BLOCK, PIXEL_HALFB},
            {PIXEL_BLOCK,PIXEL_BLOCK,PIXEL_BLOCK},
            {PIXEL_HALFT, PIXEL_BLOCK, PIXEL_HALFT},
        }
    }; */

    texture texture_second = {
        .buffer = {
            {PIXEL_BLOCK, PIXEL_HALFT, PIXEL_BLOCK},
            {PIXEL_BLOCK, SPACE, PIXEL_BLOCK},
            {PIXEL_BLOCK, PIXEL_HALFB, PIXEL_BLOCK}
        }
    };

    texture texture_space = {
        .buffer = {
            {SPACE, SPACE, SPACE},
            {SPACE,SPACE,SPACE},
            {SPACE, SPACE, SPACE},
        }
    };
    
    /* texture blank = {
        .buffer = {
            {"1", "2", "3"},
            {"4", "5", "6"},
            {"7", "8", "9"}
        }
    }; */

    texture_map[0] = &texture_space;
    texture_map[1] = &texture_second;

    set_big_buff();
    draw_final_console();

    return 0;
}

/*    texture_map[1] = &texture2; */

//    for (int i = 0; i < 1; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            for (int k = 0; k < 3; k++)
//            {
//                printf("%s", (*texture_map[i])[j][k]);
//            }
//            printf("\n");
//        }
//        printf("========\n");
//    }

/* char texture2[TILE_SIZE_X][TILE_SIZE_Y] = {
 {'y', 'y', 'y'},
 {'y', "x", "x"},
 {'y', 'y', 'y'},
 }; */

/*     char* pixel_buffer[TILE_WIDTH * TILE_SIZE_X][TILE_HEIGHT * TILE_SIZE_Y];
 int tile_map[TILE_WIDTH][TILE_HEIGHT]; */
/* char* texture_map[10]; */

//long long current_timestamp() {
//    struct timeval te;
//    gettimeofday(&te, NULL); // get current time
//    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
//    // printf("milliseconds: %lld\n", milliseconds);
//    return milliseconds;
//}