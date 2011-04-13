/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
/* Based on: poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

#define THIS_FILE "ch10pp03.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define CARD_TYPE 2
#define RANK 0
#define SUIT 1
#define ROYAL 50
#define STRAIGHT 10
#define ACE_LOW_STRAIGHT 18

/* external variables */
bool royal, straight, flush, four, three;
int pairs;	 /* can be 0, 1, or 2 */
int hand[NUM_CARDS][CARD_TYPE]; /* 5 card hand, hand[x][0] == rank
						hand[x][1] == suit */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 * repeatedly.						  *
 **********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	for (;;) {
		read_cards();
		analyze_hand();
		print_result();
	}
}

/**********************************************************
 * read_cards: Reads the cards into the external	  *
 * variables num_in_rank and num_in_suit;		  *
 * checks for bad cards and duplicate cards.		  *
 **********************************************************/
void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank, suit;
	bool bad_card;
	bool duplicate = false;
	int cards_read = 0;
	int card;
	int card_type;

	for (card = 0; card < NUM_CARDS; ++card) {
		for (card_type = 0; card_type < CARD_TYPE; ++card_type)
			hand[card][card_type] = -1;
	}

	while (cards_read < NUM_CARDS) {
		bad_card = false;
		duplicate = false;
		printf("Enter a card: ");

		rank_ch = getchar();
		switch (rank_ch) {
			case '0': exit(EXIT_SUCCESS);

			case '2': rank = 0; break;
			case '3': rank = 1; break;
			case '4': rank = 2; break;
			case '5': rank = 3; break;
			case '6': rank = 4; break;
			case '7': rank = 5; break;
			case '8': rank = 6; break;
			case '9': rank = 7; break;
			case 't': case 'T': rank = 8; break;
			case 'j': case 'J': rank = 9; break;
			case 'q': case 'Q': rank = 10; break;
			case 'k': case 'K': rank = 11; break;
			case 'a': case 'A': rank = 12; break;
			default:  bad_card = true;
		}

		suit_ch = getchar();
		switch (suit_ch) {
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default:  bad_card = true;
		}

		while ((ch = getchar()) != '\n')
			if (ch != ' ') bad_card = true;

		if (bad_card)
			printf("Bad card; ignored.\n");
		else {
			/* check for duplicate card */
			for (card = 0; card < cards_read; ++card)
				if ((hand[card][RANK] == rank) &&
					(hand[card][SUIT] == suit))
						duplicate = true;
			if (duplicate)
				printf("Duplicate card; ignored.\n");
			else {
				hand[cards_read][RANK] = rank;
				hand[cards_read][SUIT] = suit;
				cards_read++;
			}
		}
	}
}


/**********************************************************
 * analyze_hand: Determines whether the hand contains a	  *
 * straight, a flush, four-of-a-kind,			  *
 * and/or three-of-a-kind; determines the	 	  *
 * number of pairs; stores the results into 		  *
 * the external variables straight, flush,		  *
 * four, three, and pairs.				  *
 **********************************************************/
void analyze_hand(void)
{
	int card;
	int rank_sum = 0; /* add ranks to see if we have a straight */

	royal = false;
	straight = false;
	flush = true;
	four = false;
	three = false;
	pairs = 0;

	/* check for flush */
	for (card = 0; card < NUM_CARDS - 1; ++card) {
		if (hand[card][SUIT] != hand[card + 1][SUIT]) {
			flush = false;
			break;
		}
	}

	/* check for a royal straight: T,J,Q,K,A
	 * T + J + Q + K + A ==  50
	 */
	for (card = 0; card < NUM_CARDS; ++card)
		rank_sum += hand[card][RANK];
		if (rank_sum == ROYAL)
			royal = true;

	if (flush && royal) {
		return;
	}
	/* ace high stright */
	if (royal) {
		straight = true;
		return;
	}

	/* check for straight */
	rank_sum = 0;

	for (card = 0; card < NUM_CARDS; ++card) {
		if (hand[card][RANK] == 12) /* ace */
			rank_sum += 12;
		else
			rank_sum += (hand[card][RANK] % 5);
	}
	if ((rank_sum == STRAIGHT) || (rank_sum == ACE_LOW_STRAIGHT)) {
		straight = true;
		return;
	}

	int same = 0;
	for (int i = 0; i < NUM_CARDS; ++i) {
		for (int j = 0; j <  NUM_CARDS; ++j) {
			if (i != j) {
				if (hand[i][RANK] == hand[j][RANK]) {
					++same;
				}
			}
		}
	}
	switch (same) {
		case 12: four  = true; break;
		case  8: three = true; pairs = 1;
		case  6: three = true; break;
		case  4: pairs = 2; break;
		case  2: pairs = 1; break;
		default: break;
	}
}

/**********************************************************
 * print_result: Prints the classification of the hand,	  *
 * based on the values of the external			  *
 * variables straight, flush, four, three,		  *
 * and pairs.						  *
 **********************************************************/
void print_result(void)
{
	if (royal && flush) printf("Royal flush");
	else if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (three && pairs == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (pairs == 2) printf("Two pairs");
	else if (pairs == 1) printf("Pair");
	else printf("High card");

	printf("\n\n");
}
