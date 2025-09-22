/*
/
*/

#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_board {
	unsigned int width;
	unsigned int height;
	unsigned int iterations;
	char** map;
}	t_board;

int ft_strlen(const char* string);
void ft_putstr(const char* string);

bool parseArguments(char **argv);

void freeMap(char** map, int height);
t_board* initBoard(char **argv);

void drawBoard(char **map, int width, int height);

int countAliveNeighbors(char **map, int width, int height, int y, int x);
void iterateLife(t_board* board);

void printMap(char **map);

#endif
