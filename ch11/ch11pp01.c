/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11pp01.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Modify PP 07 from ch 2 so that it includes the following function:
 * void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
 * The function determines the smallest number of notes required to pay the
 * amount repr4esented by dollars.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define MAX 20 /* Max array size */

/* external variables */

/* function prototypes */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

/* main() */
/********************************************************
 * main: implement find_largest() function
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO



	return 0;
}

/* function definitions */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

	return;
}
