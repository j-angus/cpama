/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition
 * By K. N. King
 *********************************************************/
#define THIS_FILE "ch13pp12.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Modify ch08pp14 so that it stores the words in a two-dimensional array
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define SENT_LEN 600
#define	WORD_LEN 20
#define WORD_MAX 30

/* external variables */

/* function prototypes */
double compute_average(const char *sentence);
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char sentence[SENT_LEN+1];
	int i = 0;
	char *word_store[WORD_MAX];
	char store[WORD_MAX][WORD_LEN];
	char *p = sentence, *q = p;
	char endsen = '\0';

	printf("Enter a sentence: ");
	read_line(sentence, sizeof(sentence));

	/* search for the end of the sentence, if it is punctuation,
	 * save it for later and replace with \0
	 */
	while (*p)
		++p;
	if (ispunct(*--p)) {
		endsen = *p;
		*p = '\0';
	}
	p = q;
	/* store words in sentence into word_store */
	while (*q) {
		while (*q && !isspace(*q)) /* skip to end of word */
			++q;
		if (*q) { /* ensure we're not at the end of the sentence */
			*q++ = '\0'; /* turn word into a string */

			if (i < (WORD_MAX - 1)) {
				/* strcpy(word_store[i++], p); */
				/* store[i] = p; */
				strncpy(store[i], p, WORD_LEN);
				word_store[i++] = p;
				while (*q && isspace(*q)) /* skip whitespace */
					++q;
				if (*q)
					p = q;
			}
			else
				break; /* word_store full */
		} else {
			word_store[i] = p;
			strncpy(store[i], p, WORD_LEN);
		}
	}
	int j = i;
	printf("Reversal of sentence:\n");
	for ( ; 0 <= i; --i)
		printf("%s%c", word_store[i], 0 < i ? ' ' : '\0');
	printf("%c\n", endsen ? endsen : '\0');

	printf("Reversal of sentence (using store[]):\n");
	for ( ; 0 <= j; --j)
		printf("%s%c", store[j], 0 < j ? ' ' : '\0');
	printf("%c\n", endsen ? endsen : '\0');

	return 0;
}

/* function definitions */

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
