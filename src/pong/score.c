// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <ncurses.h>
#include <stdio.h>

#include "./render.h"
#include "./score.h"

char* map =
    "_00000__0___0__0___0__0___0__00000_X___0_____00____0_0______0______0___X__"
    "000___0___0_____0_____0____00000_X__000___0___0_____0___0___0___000__X_0__"
    "_0__0___0__00000______0______0_X_00000__0______00000______0__00000_X_"
    "00000__0______00000__0___0__00000_X_00000_____0_____0______0______0___X_"
    "00000__0___0__00000__0___0__00000_X_00000__0___0__00000______0__00000_X";

void PrintScore(int N, int xOFFS) {
    int lineOffset = 0;
    const int tempN = N;
    int tens = N / 10;

    int mapOfset = tens * 36;

    N = tens;

    for (int y = 0; y < 5; y++) {
        move(26 + y, xOFFS - 8);

        for (int x = 0; x < 7; x++) {
            lineOffset = x + (y * 7);
            char A = map[(mapOfset + lineOffset)];
            if (A == '0') {
                attron(COLOR_PAIR(WATER_PAIR));
                printw("█");
                attroff(COLOR_PAIR(WATER_PAIR));
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }

    N = tempN % 10;
    mapOfset = N * 36;
    for (int y = 0; y < 5; y++) {
        move(26 + y, xOFFS);

        for (int x = 0; x < 7; x++) {
            lineOffset = x + (y * 7);
            char A = map[(mapOfset + lineOffset)];
            if (A == '0') {
                attron(COLOR_PAIR(WATER_PAIR));
                printw("█");
                attroff(COLOR_PAIR(WATER_PAIR));
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
}
