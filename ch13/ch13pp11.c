/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition
 * By K. N. King
 *********************************************************/
#define THIS_FILE "ch13pp11c, page 312"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Modify ch07pp13 so that it includes function:
 * double compute_average(const char *sentence);
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define SENT_LEN 80

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
	double avg_wordlen = 0;

	printf("Enter a sentence: ");
	read_line(sentence, sizeof(sentence));
	avg_wordlen = compute_average(sentence);
	printf("Average word length: %0.1lf\n", avg_wordlen);
	return 0;
}

/* function definitions */

/**
 * compute the average word length within sentence
 */
double compute_average(const char *sentence)
{
	int wordlen = 0;
	int num_words = 0;

	while (*sentence) { /* assume sentence '\0' terminated */
		/* tally total characters as long as they are alpha */
		if (isalpha(*sentence)) {
			++wordlen;
			++sentence;
		} else {
			/* increment num_words when we read a non-alpha char */
			++num_words;
			/* skip past non-alpha chars */
			while (!isalpha(*sentence) && *sentence)
				sentence++;
		}
	}

	if (num_words)
		return (float) wordlen / num_words;
	else
		return 0;
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


