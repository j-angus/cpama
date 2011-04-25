/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex15.c, page 309"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the following function:
 * int f(char *s, char *t);
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define LINE_LEN 80

/* external variables */

/* function prototypes */
int read_line(char str[], int n);
int f(char *s, char *t);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO

	printf("f(\"abcd\", \"babc\"): %d\n", f("abcd", "babc"));

	printf("f(\"abcd\", \"bcd\"): %d\n", f("abcd", "bcd"));
	return 0;
}

/* function definitions */

int f(char *s, char *t)
{
	char *p1, *p2;
	for (p1 = s; *p1; ++p1) {
		for (p2 = t; *p2; ++p2)
			if (*p1 == *p2) break;
		if (*p2 == '\0') break;
	}
	return p1 - s;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}


