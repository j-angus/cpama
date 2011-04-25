/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex06.c, page 309"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/*
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

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	/* stores up to LINE_LEN char, allows space for null terminator */
	char line[LINE_LEN + 1];
	char hide_text[] = "foo";

	printf("Enter a line of text: ");
	read_line(line, LINE_LEN);

	censor(line, hide_text);

	printf("Censored text: %s\n", line);
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
			str[i++] = ch;
		}
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}

void capitalise(int n, char str[n])
{
	for (char *p = str; p < str + n; ++p)
		*p = toupper(*p);
	return;
}

/** Search for 'hide' in 'str', replace  all occurrances with 'x's
 */
void censor(char *str, const char *hide)
{
	char *p = str;
	const char *q = hide;

	/* p is set to the beginning of the location that 'hide'
	 * is found to occur in 'str'
	 */
	while ((p = strstr(p, q))) { /* true while 'hide' is found in 'str' */
		while(*q++)		/* For each character in 'hide', */
			*p++ = 'x';	/* place 'x' into 'str' */
		q = hide; /* reset q to point to 'hide' */
	}
	return;
}

/* Another possible method to replace a word within a string
void censor(char *str, const char *hide)
{
	char *p = str;
	const char *q = hide;
*/
	/* Create the censor string (x's) to strikeout matching text */
/*
	int hide_len, i;
	hide_len = strlen(hide);
	char strikeout[hide_len + 1];
	for (i = 0; i < hide_len; ++i)
		strikeout[i] = 'x';
	strikeout[i] = '\0';
	while (p = strstr(p, hide)) {
		strncpy(p, strikeout, hide_len);

	return;
}

*/
