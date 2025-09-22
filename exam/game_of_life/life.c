/*
/
*/

#include "life.h"

int ft_strlen(const char* string) {
	if (!string) {
		return 0;
	}
	int i = 0;
	while (string[i]) {
		++i;
	}
	return (i);
}

void ft_putstr(const char* string) {
	if (!string) {
		return;
	}
	int len = ft_strlen(string);
	for (int i = 0; i < len; ++i) {
		putchar(string[i]);
	}
}

bool parseArguments(char **argv) {
	if (!argv || !*argv) {
		return false;
	}
	int width = atoi(argv[0]);
	int height = atoi(argv[1]);
	int iterations = atoi(argv[2]);
	return width > 0 && height > 0 && iterations >= 0;
}

void freeMap(char** map, int height) {
	if (!map || height <= 0) {
		return;
	}
	for (int i = 0; i < height; ++i) {
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
}

t_board* initBoard(char** argv){
	if (!argv || !*argv) {
		return NULL;
	}
	t_board* newBoard = malloc(sizeof(t_board));
	if (!newBoard) {
		return NULL;
	}
	int wid = atoi(argv[0]);
	int hei = atoi(argv[1]);
	int iters = atoi(argv[2]);
	newBoard->width = wid;
	newBoard->height = hei;
	newBoard->iterations = iters;
	newBoard->map = NULL;
	printf("Board has width: %d, height: %d, iterations: %d\n",
		newBoard->width, newBoard->height, newBoard->iterations);
	newBoard->map = malloc(sizeof(char*) * (hei + 1));
	if (!newBoard->map) {
		free(newBoard);
		return NULL;
	}
	newBoard->map[hei] = NULL;
	for (int i = 0; i < hei; ++i) {
		newBoard->map[i] = malloc(sizeof(char) * (wid + 1));
		if (!newBoard->map[i]) {
			freeMap(newBoard->map, i);
			newBoard->map = NULL;
			free(newBoard);
			return NULL;
		}
		for (int j = 0; j < wid; ++j) {
			newBoard->map[i][j] = ' ';
		}
		newBoard->map[i][wid] = '\0';
	}
	printMap(newBoard->map);
	return (newBoard);
}

void drawBoard(char **map, int width, int height) {
	if (!map || !*map) {
		return;
	}
	int x = 0, y = 0;
	bool penDown = false;
	char c;
	while (read(0, &c, 1) == 1) {
		if (c == 'x') penDown = !penDown;
		else if (c == 'w' && y > 0) y--;
		else if (c == 'a' && x > 0) x--;
		else if (c == 's' && y < height - 1) y++;
		else if (c == 'd' && x < width - 1) x++;
		if (penDown) map[y][x] = '0';
	}
	printMap(map);
}

int countAliveNeighbors(char **map, int width, int height, int y, int x) {
	int count = 0;

	for (int dy = -1; dy <= 1; ++dy) {
		for (int dx = -1; dx <= 1; ++dx) {
			if (dy == 0 && dx == 0) {
				continue;
			}
			int ny = y + dy;
			int nx = x + dx;
			if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
				if (map[ny][nx] == '0') count++;
			}
		}
	}
	return count;
}

void iterateLife(t_board* board) {
	if (!board) {
		return;
	}
	int hei = board->height;
	int wid = board->width;

	char** tempMap = malloc(sizeof(char*) * (hei + 1));
	if (!tempMap) {
		return;
	}
	tempMap[hei] = NULL;
	for (int i = 0; i < hei; ++i) {
		tempMap[i] = malloc(sizeof(char) * (wid + 1));
		if (!tempMap[i]) {
			freeMap(tempMap, i);
			free(tempMap);
			return;
		}
		for (int j = 0; j < wid; ++j) {
			int aliveNeighbors = countAliveNeighbors(board->map, wid, hei, i, j);
			if (board->map[i][j] == '0') {
				tempMap[i][j] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? '0' : ' ';
			} else {
				tempMap[i][j] = (aliveNeighbors == 3) ? '0' : ' ';
			}
		}
		tempMap[i][wid] = '\0';
	}
	for (int i = 0; i < hei; i++) {
		for (int j = 0; j < wid; j++) {
			board->map[i][j] = tempMap[i][j];
		}
		free(tempMap[i]);
	}
	free(tempMap);
}

void printMap(char **map) {
	if (!map || !*map) {
		return;
	}
	ft_putstr("---------MAP---------\n");
	for (int i = 0; map[i]; ++i) {
		ft_putstr(map[i]);
		ft_putstr("\n");
	}
}
