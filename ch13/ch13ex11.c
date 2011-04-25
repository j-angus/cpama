/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex06.c, page 309"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Edit strcmp() function to use pointer arithmetic instead of integer indexes.
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
void capitalise(int n, char str[n]);
void censor(char str[], const char hide[]);
int my_strcmp(char *s, char *t);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	/* stores up to LINE_LEN char, allows space for null terminator */
	char word1[LINE_LEN + 1];
	char word2[LINE_LEN + 1];

	printf("Enter two words to compare.\n");
	printf("Word one: ");
	read_line(word1, LINE_LEN);
	printf("Word two: ");
	read_line(word2, LINE_LEN);

	printf("Result of comparison: %d\n", my_strcmp(word1, word2));

	return 0;
}

/* function definitions */

int my_strcmp(char *s, char *t)
{
	while (*s == *t) {
		if (*s == '\0')
			return 0;
		s++, t++;
	}
	return *s - *t;
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


