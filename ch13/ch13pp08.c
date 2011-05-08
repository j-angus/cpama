/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition
 * By K. N. King
 *********************************************************/
#define THIS_FILE "ch13pp08c, page 312"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Modify ch07pp05 (compute scrabble word value) to include the function:
 * int compute_scrabble_value(const char *word);
 * The function returns the SCRABBLE value of the string pointed to by 'word'.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define WORD_LEN 10

/* external variables */

/* function prototypes */
int compute_scrabble_value(const char *word);
int read_line(char str[], int n);

/* main() */
/********************************************************
 * main: compute SCRABBLE value from user entered word.
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char scrabble_word[WORD_LEN+1];
	int scrabble_value = 0;

	printf("Enter a word: ");
	read_line(scrabble_word, sizeof(scrabble_word));
	scrabble_value = compute_scrabble_value(scrabble_word);
	printf("SCRABBLE value of %s is: %d\n", scrabble_word, scrabble_value);
	return 0;
}

/* function definitions */


int compute_scrabble_value(const char *word)
{
	int value = 0; /* the computed SCRABBLE value of *word */

	while (*word) {
		switch (tolower(*word++)) {
		case 'a': case 'e': case 'i': case 'l': case 'n':
		case 'o': case 'r': case 's': case 't': case 'u':
			value ++; break;
		case 'd': case 'g':
			value += 2; break;
		case 'b': case 'c': case 'm': case 'p':
			value += 3; break;
		case 'f': case 'h': case 'v': case 'w': case 'y':
			value += 4; break;
		case 'k':
			value += 5; break;
		case 'j': case 'x':
			value += 8; break;
		case 'q': case 'z':
			value += 10; break;
		default:	/* not a letter */
			break;
		}
	}

	return value;
}

/**
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * n is the size of str[]
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


