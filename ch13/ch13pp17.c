/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
#define THIS_FILE "ch13pp17.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n\n", THIS_FILE);

/**
 * Modify ch12pp02.c to include the function:
 * bool is_palindrome(char *message);
 * The function returns true if the string pointed to by *message is
 * a painldrome.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LINE_LENGTH 80 /* max length of user input rpn expression */

/* external variables */

/* function prototypes */
bool is_palindrome(const char *message);
int read_line(char *str, int n);

int main(void)
{	PRINT_FILE_INFO
	char input[LINE_LENGTH+1];

	printf("Enter a message: ");
	read_line(input, sizeof input);
	printf("message is %s a palindrome\n",
	is_palindrome(input) ? "\b" : "not");
	return 0;
}

/* function definitions */

/**
 * determines whether a string is a palindrome.
 * returns true if *message is a palindrome.
 */
bool is_palindrome(const char *message)
{
	const char *p = message;
	const char *q;
	bool is_pal = true;

	while (*message) /* skip to end of string */
		++message;

	if (message > p) { /* check that message isn't just a single NUL */
		q = --message; /* set *q to char before NUL terminator */

		/* compare characters */
		while (p < q) {
			if (*p != *q) {
				is_pal = false;
				break;
			}
			++p, --q;
		}
	}

	return is_pal;
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
