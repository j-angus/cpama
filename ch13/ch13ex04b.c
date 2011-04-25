/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex04b.c, page 308"
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
#define LINE_LEN 80

/* external variables */

/* function prototypes */
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	/* stores up to LINE_LEN char, allows space for null terminator */
	char line[LINE_LEN + 1];

	printf("Enter a line of text: ");
	read_line(line, LINE_LEN);
	printf("line:\n\n%s\n", line);

	return 0;
}

/* function definitions */

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		if (i < n) {
			if (isspace(ch)) /* stop reading on whitespace */
				break;
			str[i++] = ch;
		}
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}
