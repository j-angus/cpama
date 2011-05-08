/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition
 * By K. N. King
 *********************************************************/
#define THIS_FILE "ch13pp10c, page 312"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Modify ch07pp11 so that it includes function:
 * void reverse_name(char *name);
 *
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define NAME_LEN 80

/* external variables */

/* function prototypes */
void reverse_name(char *name);
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char username[NAME_LEN+1];

	printf("Enter a first and last name: ");
	read_line(username, sizeof(username));
	reverse_name(username);
	printf("Name reversed: %s\n", username);
	return 0;
}

/* function definitions */

/**
 * reverse_name() expects *name to contain a Firstname and a Lastname.
 * We alter *name so that it reads: Lastname, F.
 * We ignore leading whitespace, whitespace between Firstname and Lastname,
 * and trailing whitespace.
 */
void reverse_name(char *name)
{
	char *initial; /* initial of first name */
	char *lastname;
	char *p = name;

	while (isspace(*p)) /* skip past whitespace */
		++p;
	if (*p) { /* ensure we have a char and not \0 */
		initial = p;
		/* look for end of first name */
		while (isalpha(*p) && !isspace(*p))
			++p;
		if (*p) { /* ensure we have a char and not \0 */
			while (isspace(*p)) /* skip past whitespace */
				++p;
			lastname = p;
			/* look for end of lastname, stop when *p == non-alpha,
			 * \0 or whitespace */
			while (isalpha(*p) && !isspace(*p))
				++p;
			if (*p) /* end of lastname not \0 terminated */
				*p = '\0'; /* make it so */
			/* copy lastname to beginning of name */
			sprintf(name, "%s, %c.", lastname, *initial);
		} else
			printf("ERROR: No lastname...\n");
	} else
		printf("ERROR: No name entered...\n");

	return;
}

/**
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * Returns the numbers of chars, i, stored in str[]
 */
int read_line(char str[], int n)
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


