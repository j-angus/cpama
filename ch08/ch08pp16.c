/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch08pp16.c
 * Write a program that tests whether two words are anagrams of each other.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 80
#define ALPHABET 26
int main(void)
{
	int ch; /* user input */
	int word[ALPHABET]; /* array to record characters in entered words */
	int i; /* array index */
	bool is_anagram = true;

	for (i = 0; i < ALPHABET; ++i)
		word[i] = 0;
		
	printf("Enter first word: ");
	for (i = 0; i < MAX_WORD_LEN; ++i) {
		ch = tolower(getchar());
		if (ch == '\n') {
			break;
		}
		else if (isalpha(ch)) {
			++word[ch - 'a'];	
		}
	}

	printf("Enter second word: ");
	for (i = 0; i < MAX_WORD_LEN; ++i) {
		ch = tolower(getchar());
		if (ch == '\n') {
			break;
		}
		else if (isalpha(ch)) {
			--word[ch - 'a'];
		}
	}
	
	/* test array to see if words contained same letters */
	/* all zeros means words were equal */	
	for (i = 0; i < ALPHABET; ++i) {
		if (word[i] != 0) {
			is_anagram = false;
			break;
		}
	}
		
	printf("The words are %s anagrams.\n", is_anagram ? "\b" : "not");		
	
	return 0;
}
