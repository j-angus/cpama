/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
#define THIS_FILE "ch13pp16.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n\n", THIS_FILE);

/**
 * Modify ch12pp01.c to include the function:
 * void reverse(char *message);
 * The function reverses the string pointed to by *message.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LINE_LENGTH 80 /* max length of user input rpn expression */

/* external variables */

/* function prototypes */
void reverse(char *message);
int read_line(char *str, int n);

int main(void)
{	PRINT_FILE_INFO
	char input[LINE_LENGTH+1];

	printf("Enter a message: ");
	read_line(input, sizeof input);
	reverse(input);
	printf("Reversal is: %s\n", input);
	return 0;
}

/* function definitions */

/**
 * reverses the characters in a string.
 */
void reverse(char *message)
{
	char *p = message;
	char *q;
	char temp;

	while (*message) /* skip to end of string */
		++message;

	if (message > p) {/* check that message isn't just a single NUL */
		q = --message; /* set *q to char before NUL terminator */

		/* swap characters */
		while (p < q) {
			temp = *p;
			*p = *q;
			*q = temp;
			++p, --q;
		}
	}

	return;
}

/**
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * Returns the numbers of chars, i, stored in *str
 * 'n' is expected to be the size of the char array pointed to by *str
 */
int read_line(char *str, int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		/* we want to store at max n-1 chars into str[] */
		if (i < n-1) {
			str[i++] = ch;
		}
		else
			break;
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}
