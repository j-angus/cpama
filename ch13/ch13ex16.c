/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex16.c, page 310"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Condense count_spaces() function from section 13.4
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
int count_spaces(const char *s);
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char line[LINE_LEN + 1];
	printf("Enter a line of text: ");
	read_line(line, LINE_LEN);
	printf("Number of spaces in line: %d\n", count_spaces(line));
	return 0;
}

/* function definitions */

int count_spaces(const char *s)
{
	int count = 0;

	while (*s)
		if (*s++ == ' ')
			count++;
	return count;
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


