// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./collision.h"
#include "./engine.h"
#include "./input.h"
#include "./render.h"

#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define FIELD_CENTER FIELD_WIDTH / 2
#define PLAYER_MAX_SCORE 21

int main() {
    InitWindow();
    SpawnThread();

    while (score_player1 < PLAYER_MAX_SCORE &&
           score_player2 < PLAYER_MAX_SCORE) {
        Field();
    }

    clear();
    refresh();

    if (score_player1 >= PLAYER_MAX_SCORE) {
        system("osascript -e 'display dialog \"Congratulations Player One!\"'");
    } else {
        system("osascript -e 'display dialog \"Congratulations Player Two!\"'");
    }

    endwin();
    return 0;
}
