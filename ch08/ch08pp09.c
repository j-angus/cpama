/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King																				 *
 *********************************************************/

/* ch08pp09.c
 * Program 'walks' letters of the alphabet randomly across a 10x10 grid
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int main(void)
{
	int col, row, move, num_tries;
	int grid[ROW][COL];
	int alpha = 'A';
	bool moved = true;

	/* initialise grid */
	for (row = 0; row < ROW; ++row)
		for (col = 0; col < COL; ++col)
			grid[row][col] = '.';

	srand((unsigned) time(NULL));
	row = rand() % ROW;
	col = rand() % COL;
	/* place letters onto grid */
	for (alpha = 'A'; alpha <= 'Z'; ++ alpha) {
		move = (rand() % ROW) % 4;
		moved = false;
		num_tries = 0;
		do {
			printf("move: %d, ", move);
			switch (move) {
				case 0: if (row && grid[row-1][col] == '.') {
						--row;
						moved = true;
					}
					else {
						++move;
						++num_tries;
					}
					break;
				case 1: if (row < ROW-1 &&
						grid[row+1][col] == '.') {
						++row;
						moved = true;
					}
					else {
						++move;
						++num_tries;
					}
					break;
				case 2: if (col && grid[row][col-1] == '.') {
						--col;
						moved = true;
					}
					else {
						++move;
						++num_tries;
					}
					break;
				case 3: if (col < COL-1 &&
						grid[row][col+1] == '.') {
						++col;
						moved = true;
					}
					else {
						move = 0;
						++num_tries;
					}
					break;
			}
			printf("moved: %s\n", moved ? "true" : "false");
		} while(!moved && num_tries < 4);
		
		if (moved) {
			grid[row][col] = alpha;
		}
		else
			break;

	}

	/* display grid */
	for (row = 0; row < ROW; ++row) {
		for (col = 0; col < COL; ++col)
			printf("%c", grid[row][col]);
		printf("\n");
	}

	return 0;
}
