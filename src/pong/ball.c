// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "./collision.h"
#include "./engine.h"
#include "./input.h"
#include "./render.h"

void ResetGame() {  // функция перезапуска игры
    usleep(2000000);
    player1y = 13;
    player2y = 13;

    ball_x = 40;
    ball_y = 11;
}

void MovemetBall() {  // функции перемещения мяча.
    ball_x = ball_x + vector_x;
    ball_y = ball_y + vector_y;
    if (IsBorderBallY() == 1) {
        vector_y = -vector_y;
        printf("\a");
    }
    if (IsBorderBallX() == 1) {
        vector_x = -vector_x;
        printf("\a");
    }
    if (IsGoalP1() == 1) {
        score_player1++;
        ResetGame();
    }
    if (IsGoalP2() == 1) {
        score_player2++;
        ResetGame();
    }
}
