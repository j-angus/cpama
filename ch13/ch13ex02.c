/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex02.c, page 308"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/*
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */

/* external variables */

/* function prototypes */


/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char *p = "abc";
/*
	puts("putchar(p): ");
	putchar(p);
	puts("\n");
	puts("putchar(*p): ");
	putchar(*p);
	puts("\n");
	puts("puts(p): ");
	puts(p);
	puts("puts(*p): ");
	puts(p);
*/
	int i, j = 0;
	char s[81];

/*	12abc34 56def78
 */
	printf("Enter some stuff: ");
	scanf("%d%s%d", &i, &s, &j);

	printf("i: %d, s: %s, j: %d\n", i, s, j);


	return 0;
}

/* function definitions */

