/* ch16ex18.c */

#include <stdio.h>

typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
typedef enum {BLACK, WHITE} Colour;
typedef struct {
	Piece piece;
	Colour colour;

} Square;

Square square[8][8] = {
	{{.piece=ROOK, .colour=BLACK}, {.piece=KNIGHT, .colour=BLACK}, {.piece=BISHOP, .colour=BLACK}, {.piece=KING, .colour=BLACK}, {.piece=QUEEN, .colour=BLACK}, {.piece=BISHOP, .colour=BLACK}, {.piece=KNIGHT, .colour=BLACK}, {.piece=ROOK, .colour=BLACK}},
	{{.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}, {.piece=PAWN, .colour=BLACK}},
	{{.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}},
	{{.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}},
	{{.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}},
	{{.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}, {.piece=EMPTY, .colour=BLACK}},
	{{.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}, {.piece=PAWN, .colour=WHITE}},
	{{.piece=ROOK, .colour=WHITE}, {.piece=KNIGHT, .colour=WHITE}, {.piece=BISHOP, .colour=WHITE}, {.piece=KING, .colour=WHITE}, {.piece=QUEEN, .colour=WHITE}, {.piece=BISHOP, .colour=WHITE}, {.piece=KNIGHT, .colour=WHITE}, {.piece=ROOK, .colour=WHITE}}
};

int main (void)
{
	int i = 0, j = 0;
	for ( ; i < 8; ++i)
		for (j = 0; j < 8; ++j)
			printf("%d%d%c", square[i][j].piece,
					 square[i][j].colour,
					 j < 8 - 1 ? ',' : '\n');
	/*
	for ( ; i < 8; ++i) {
		for (j = 0; j < 8; ++j)
			printf("s[%d][%d]%c", i, j,
						   j < (8 - 1) ? ',' : '\n');
	}
	*/
	return 0;
}

