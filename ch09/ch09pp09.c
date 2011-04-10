/**********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition  *
 * By K. N. King					  *
 *********************************************************/

/* this file: ch09pp09.c
 *
 * Write a program that simulates the game of craps, played with two dice.
 * On the first roll, the player wins if the sum of the dice is 7 or 11.
 *
 * The player loses if the sum is 2, 3, or 12. Any other roll is called the
 * "point" and the game continues. On each subsequent roll, the player wins if
 * they roll the point again. The player loses by rolling 7 (Snake Eyes).
 * Any other roll is ignored and the game contines.
 *
 * At the end of each game, the program will ask the user whether or not to
 * play the game again. When the user enters a response other than 'y' or 'Y',
 * the program will display the number of wins and losses then terminate.
 *
 * Write the game as three functions: main, roll_dice, and play_game.
 *
 * roll_dice should generate two random numbers, each between 1 & 6, and
 * return their sum.
 *
 * play_game should play one craps game(calling roll_dice to determine the
 * outcome of each dice roll); it will return true if the player wins and false
 * if the player loses. play_game is also responsible for displaying messages
 * showing the results of the player's dice rolls.
 *
 * main will call play_game repeatedly, keeping track of the number of wins and
 * losses and displaying the "you win" & "you lose" messages.
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <strings.h>

#define MAX_WORD_LEN 80
#define ALPHABET 26

struct dice
{
	int die_1;
	int die_2;
	int dice_sum;
};

struct dice roll_dice(void);
bool play_game(void);

/* main loop
 *
 */
int main(void)
{
	int wins = 0;
	int losses = 0;
	char choice[2] = "Y";

	/* Program Banner */
	printf("C Programming: A Modern Approach: ch09pp08.c\n");

	srand((unsigned)time(NULL)); /* seed random number generator */

	while (strcasecmp(choice, "N")) {
		play_game() ? ++wins : ++losses;

		printf("Play again? (y/n): ");
		scanf("%1s", choice);
	}
	printf("wins: %d\nlosses: %d\n", wins, losses);

	return 0;
}

/* roll_dice
 *
 */
struct dice roll_dice(void)
{
	struct dice roll;

	/* printf("roll_dice()\n"); */
	printf("Roll dice...\n");
	roll.die_1 = (rand() % 6) + 1;
	roll.die_2 = (rand() % 6) + 1;
	roll.dice_sum = roll.die_1 + roll.die_2;
	printf("\ndie_1:\t%d\ndie_2:\t%d\ntotal:\t%2d\n",
							roll.die_1,
							roll.die_2,
							roll.dice_sum);
	return roll;
}

/* play_game
 *
 */
bool play_game(void)
{
	bool win = false;
	bool point_result = false;
	int point = 0;
	struct dice game;

	/* printf("play_game()\n"); */

	game = roll_dice();

	switch(game.dice_sum) {
		case 7: case 11: win = true;
			break;
		case 2: case 3: case 12: win = false;
			break;
		default: point = game.dice_sum;
	}

	if (point) {
		printf("POINT!!\n");
		do {
			game = roll_dice();
			if (game.dice_sum == 7) {
				point_result = true;
				win = false;
				printf("Bad luck, Snake Eyes!\n");
			}
			if (game.dice_sum == point) {
				point_result = true;
				win = true;
			}
		} while (point_result == false);
	}

	printf("You %s.\n", win ? "Won" : "Lost");

	return win;
}
