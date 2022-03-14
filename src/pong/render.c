// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./ball.h"
#include "./collision.h"
#include "./engine.h"
#include "./input.h"
#include "./render.h"
#include "./score.h"

#define FIELD_Y 1
#define FIELD_X 1
#define FIELD_WIDTH 80
#define FIELD_HEIGHT 25
#define FIELD_CENTER 80 / 2

WINDOW* win;

void InitWindow() {  // Инициализация и потготовка терминала к игре
    setlocale(LC_ALL, "");
    system("printf '\e[8;35;80t'");
    win = initscr();
    start_color();
    init_pair(GRASS_PAIR, COLOR_GREEN, COLOR_BLACK);
    init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLACK);
    init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_BLACK);
    init_pair(PLAYER_PAIR, COLOR_RED, COLOR_BLACK);
    resizeterm(FIELD_HEIGHT + 10, FIELD_WIDTH);
}

void DrawVoid() {  // Отрисовка пустоты (пробела)
    printw(" ");
}

void DrawPlayer() {  // Отрисовка ракетки (игрока)
    attron(COLOR_PAIR(PLAYER_PAIR));
    printw("█");
    attroff(COLOR_PAIR(PLAYER_PAIR));
}

int DrawWall(int x, int y) {  // Отрисовка стены
    // Если мы сейчас наверху поля
    if (y == FIELD_Y) {
        if (x == FIELD_X || x % 40 == 0) {
            printw("█");
            return 1;
        }
        printw("▀");
        return 1;
    }

    if ((x == 1 && y == 1) || (x >= FIELD_CENTER && y == 1)) {
        if (x == FIELD_CENTER) {
            printw("▄");
            return 1;
        }
        if (x == FIELD_WIDTH) {
            printw("▄");
            return 1;
        } else {
            printw("▄");
            return 1;
        }
    }
    if (x == 1 || x == FIELD_WIDTH || x == FIELD_CENTER) {
        printw("█");
        return 1;
    }
    if (y == 1 || y == FIELD_HEIGHT) {
        printw("▄");
        return 1;
    }
    return 0;
}

void DrawBall() {  // Отрисовка мяча
    attron(COLOR_PAIR(GRASS_PAIR));
    printw("■");
    attroff(COLOR_PAIR(GRASS_PAIR));
}

int IsPlayerPos(int x, int y) {  // Анализ расположения игрока
    if (x == player1x && y == player1y) {
        return 1;
    }
    if (x == player2x && y == player2y) {
        return 1;
    }
    if (x == player1x && y + 1 == player1y) {
        return 1;
    }
    if (x == player2x && y + 1 == player2y) {
        return 1;
    }
    if (x == player1x && y - 1 == player1y) {
        return 1;
    }
    if (x == player2x && y - 1 == player2y) {
        return 1;
    }
    return 0;
}

int IsBallPos(int x, int y) {  // Анализ расположения мяча
    if (x == ball_x && y == ball_y) {
        return 1;
    }
    return 0;
}

void Clear() {  // Функция очистки экрана
    clear();
    system("printf '\e[8;35;80t'");
}
int Field() {  // Функция отрисовки поля
    Clear();
    MovemetBall();

    for (int y = FIELD_X; y <= FIELD_HEIGHT; y++) {
        for (int x = FIELD_Y; x <= FIELD_WIDTH; x++) {
            if (IsPlayerPos(x, y)) {
                DrawPlayer();
                continue;
            }
            if (IsBallPos(x, y) == 1) {
                DrawBall();
                continue;
            }
            if (DrawWall(x, y) != 1) {
                DrawVoid();
            }
        }
    }

    printw("\n");

    PrintScore(score_player1, 12);
    PrintScore(score_player2, 70);

    printw("\n");
    refresh();

    usleep(80000);
    return 0;
}
