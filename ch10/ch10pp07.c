/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch10pp07.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

/* external variables */

/* function prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: .						  *
 **********************************************************/
int main(void)
{
	PRINT_FILE_INFO

	return;
}
