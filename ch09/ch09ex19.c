/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch09ex19.c
 * 'mystery' recursive function.
 */

#include <stdio.h>
#include <stdbool.h>

void pb(int n);

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 9, Exercise 19\n\n");
	
	int num = 55;

	pb(num); /* prints 'num' as a binary number */
	
	return 0;
}

void pb(int n)
{
	if (n != 0) {
		pb(n / 2);
		putchar('0' + n % 2);
	}
}
