/*
/
*/

#include "life.h"

int main(int argc, char **argv) {
	if (argc != 4) {
		ft_putstr("Please run ./<executable> <width> <height> <iterations>\n");
		return (1);
	}
	argv++;
	if (!parseArguments(argv)) {
		ft_putstr("Please input only positive integers\n");
		return (1);
	}
	t_board* myBoard = initBoard(argv);
	if (!myBoard) {
		ft_putstr("board init failed\n");
		return (1);
	}
	drawBoard(myBoard->map, myBoard->width, myBoard->height);
	if (myBoard->iterations > 0) {
		for (unsigned int iter = 0; iter < myBoard->iterations; iter++) {
			iterateLife(myBoard);
		}
	}
	printMap(myBoard->map);
	freeMap(myBoard->map, myBoard->height);
	free(myBoard);
	return (0);
}
