/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13pp01c, page 311"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Write a program that finds the "smallest" and "largest" in a series of words.
 * After the user enters the words, the program will determine which words
 * would come first and last if the words were listed in dictionary order.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define WORD_LEN 20

/* external variables */

/* function prototypes */
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char current_word[WORD_LEN + 1],
		smallest_word[WORD_LEN + 1],
		largest_word[WORD_LEN + 1];

	/* Initialise smallest and largest _words: */
	printf("Enter word: ");
	read_line(current_word, WORD_LEN);
	strcpy(smallest_word, strcpy(largest_word, current_word));

	while (strlen(current_word) != 4) {
		printf("Enter word: ");
		read_line(current_word, WORD_LEN);

		if (strcmp(current_word, smallest_word) < 0)
			strcpy(smallest_word, current_word);
		if (strcmp(current_word, largest_word) > 0)
			strcpy(largest_word, current_word);
	}
	printf("Smallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);
	return 0;
}

/* function definitions */

/**
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * Returns the numbers of chars stored in str[]
 */
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
		else
			break;
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}


