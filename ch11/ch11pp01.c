/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11pp01.c, page 256"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Write a program that asks the user to enter a dollar amount and then shows
 * how to pay that amount using $20, $10, $5, and $1 denominations.
 */
/* Modify PP 07 from ch 2 so that it includes the following function:
 * void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
 * The function determines the smallest number of notes required to pay the
 * amount represented by dollars.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */

/* external variables */

/* function prototypes */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

/* main() */
/********************************************************
 * main: implement pay_amount() function
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	int dollars = 0; /* user input, amount of dollars to change */
	int twenties, tens, fives, ones; /* change required to pay dollars */

	/* Get amount to change from user */
	printf("Enter dollar amount: ");
	scanf("%d", &dollars);

	/* calculate required change */
	pay_amount(dollars, &twenties, &tens, &fives, &ones);

	printf("\n$20 notes:%3d\n$10 notes:%3d\n $5 notes:%3d\n $1 notes:%3d\n",
						twenties, tens, fives, ones);

	return 0;
}

/* function definitions */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	*twenties = dollars / 20;
	dollars %= 20;
	*tens = dollars / 10;
	dollars %= 10;
	*fives = dollars / 5;
	dollars %= 5;
	*ones = dollars;
	return;
}
