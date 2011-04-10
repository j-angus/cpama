/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King																				 *
 *********************************************************/

/* derived from square2.c (Chapter 6, page 110) */
/* Prints a table of squares using a for statement */

/* 
 * ch07pp01.c
 * loops. 
 */


#include <stdio.h>

int main(void)
{
	long i, n;

	printf("This program prints a table of squares.\n");

	printf("Enter number of entries in table: ");
	scanf("%ld", &n);
	getchar(); /* catch the '\n' left behind by the scanf() function */
	for (i = 1; i <= n ; i++) {
		printf("%25ld%25ld\n", i, i * i);
		if (!(i % 23)) {
			printf("Press Enter to continue...");
			getchar();
		}
	}
	 
	return 0;
}
