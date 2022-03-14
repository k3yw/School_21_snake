// Copyright 2022 "A team work of atlaskef, dyahdeme and quhurudo"
#ifndef H_RENDER
#define H_RENDER

#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define WATER_PAIR     2
#define MOUNTAIN_PAIR  3
#define PLAYER_PAIR    4

void Clear();
void InitWindow();
void DrawVoid();
void DrawPlayer();
int DrawWall(int x, int y);
void DrawBall();
int IsPlayerPos(int x, int y);
int IsBallPos(int x, int y);
int Field();

#endif