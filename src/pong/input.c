// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#include <ncurses.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "./collision.h"
#include "./engine.h"
#include "./input.h"

void ControllPlayer(char g) {  // Управление игроками
    if (IsBorderPlayer1() != 1) {
        if (g == 'a') {
            player1y--;
        }
    }
    if (IsBorderPlayer1() != -1) {
        if (g == 'z') {
            player1y++;
        }
    }

    if (IsBorderPlayer2() != 1) {
        if (g == 'k') {
            player2y--;
        }
    }
    if (IsBorderPlayer2() != -1) {
        if (g == 'm') {
            player2y++;
        }
    }
}

void SpawnThread() {  // Создание второго потока
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, InputThread, NULL);
}

void* InputThread() {  // Функция второго потока
    char g;
    while (score_player1 != 21) {
        scanf("%c", &g);
        ControllPlayer(g);
    }
    return NULL;
}
