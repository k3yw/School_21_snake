// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <stdio.h>

#include "./ball.h"
#include "./collision.h"
#include "./engine.h"
#include "./input.h"
#include "./render.h"

int IsBorderPlayer1() {  // проверка коллизии первого игрока на верхние/нижние
                         // границы.
    if (player1y - 2 == 1) {
        return 1;
    }
    if (player1y + 2 == 25) {
        return -1;
    }
    return 0;
}

int IsBorderPlayer2() {  // проверка коллизии второго игрока на верхние/нижние
                         // границы.
    if (player2y - 2 == 1) {
        return 1;
    }
    if (player2y + 2 == 25) {
        return -1;
    }
    return 0;
}

int IsBorderBallY() {  // проверка коллизи мяча и верхней границы.
    if (ball_y - 1 == 1) {
        return 1;
    }
    if (ball_y + 1 == 25) {
        return 1;  // меняется вектор У
    }
    return 0;
}

int IsBorderBallX() {  // проверка коллизи мяча и ракетки.
    if (((ball_x - player2x <= 1) && (ball_x - player2x >= -1)) &&
        ((player2y - ball_y) <= 1 && (player2y - ball_y) >= -1)) {
        return 1;
    }

    if (((ball_x - player1x <= 1) && (ball_x - player1x >= -1)) &&
        ((player1y - ball_y) <= 1 && (player1y - ball_y) >= -1)) {
        return 1;
    }
    return 0;
}

int IsGoalP1() {  // забивает первый игрок
    if (ball_x + vector_x == 80) {
        return 1;
    }
    return 0;
}

int IsGoalP2() {  // забивает второй игрок
    if (ball_x + vector_x == 1) {
        return 1;
    }
    return 0;
}
