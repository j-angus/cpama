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
void censor(const char hide[], char str[]);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	/* stores up to LINE_LEN char, allows space for null terminator */
	char line[LINE_LEN + 1];
	char hide_text[] = "foobar";

	printf("Enter a line of text: ");
	read_line(line, LINE_LEN);

	censor(hide_text, line);

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

/** Search for 'hide' in str, replace  all occurrances with 'x'
 */
void censor(const char hide[], char str[])
{
	int hide_len, str_len;

	puts("hide:");
	puts(hide);
	hide_len = strlen(hide);
	printf("hide_len: %d\n", hide_len);

	char strikeout[hide_len + 1];
	char *p = hide;
	char *q = strikeout;
	while (*p++)
		*q++ = 'x';
	*q = '\0';
	int strikeout_len = strlen(strikeout);
	printf("strikeout_len: %d\n", strikeout_len);
	puts("strikeout:");
	puts(strikeout);

	puts("str:");
	puts(str);
	str_len = strlen(str);
	printf("str_len: %d\n", str_len);

	p = str;
	p = strstr(str, hide);
	strncpy(p, strikeout, strikeout_len);
	while (p = strstr(p, hide))
		strncpy(p, strikeout, strikeout_len);

	/* now use strstr to find hide in str */
	/* use strncpy to replace hide in str with 'x's */

	return;
}
