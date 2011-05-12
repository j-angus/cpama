/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
#define THIS_FILE "ch13pp14.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Modify ch08pp16.c, Write a program that tests whether two words are anagrams
 * of each other, To include the function:
 * bool are_anagrams(const char *word1, const char *word2);
 * The function returns true if the strings pointed to by word1 and word2
 * are anagrams.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h> /* for strlen() */

#define MAX_WORD_LEN 80
#define ALPHABET 26

/* function prototypes */
bool are_anagrams(const char *word1, const char *word2);
int read_line(char str[], int n);

int main(void)
{	PRINT_FILE_INFO
	char word1[MAX_WORD_LEN+1]; /* user input */
	char word2[MAX_WORD_LEN+1]; /* user input */
	bool is_anagram;

	printf("Enter first word: ");
	read_line(word1, sizeof(word1));

	printf("Enter second word: ");
	read_line(word2, sizeof(word2));

	is_anagram = are_anagrams(word1, word2);

	/* test array to see if words contained same letters */
	/* all zeros means words were equal */
	printf("The words are %s anagrams.\n", is_anagram ? "\b" : "not");

	return 0;
}

/* function prototypes */

/**
 * The function returns true if the strings pointed to by word1 and word2
 * are anagrams.
 */
bool are_anagrams(const char *word1, const char *word2)
{
	bool is_anagram = true;
	int letter[ALPHABET];
	int word_size = 0;

	/* initialise letter store */
	for (int i=0; i < ALPHABET; ++i)
		letter[i] = 0;

	if ((word_size = strlen(word1)) == strlen(word2)) {
		/* store number of each letter of word1 into letter[] */
		while (*word1) {
			if (isalpha(*word1))
				++letter[tolower(*word1++) - 'a'];
			else /* invalid: contains non-alpha char */
				return false;
		}

		while (*word2) {
			if (isalpha(*word2))
				--letter[tolower(*word2++) - 'a'];
			else /* invalid: contains non-alpha char */
				return false;
		}
	}
	for (int i=0; i < ALPHABET; ++i) {
		if (letter[i]) {
			is_anagram = false;
			break;
		}
	}
	return is_anagram;
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
