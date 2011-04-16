/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex04.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/*
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* defines */

/* external variables */

/* function prototypes */
void swap(int *p, int *q);

/* main() */
/********************************************************
 * main: implement swap() function
 ********************************************************/
int main(void)
{

	PRINT_FILE_INFO

	int a = 10;
	int b =100;

	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("swapped...\na: %d, b: %d\n", a, b);

	return 0;
}

/* function definitions */
void swap(int *p, int *q)
{
	int temp = *p;

	*p = *q;
	*q = temp;

	return;
}
