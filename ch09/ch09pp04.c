/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch09pp04.c
 * Write a program that tests whether two words are anagrams of each other.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 80
#define ALPHABET 26

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);
 
int main(void)
{
	int word1[ALPHABET]; /* array to record characters in entered words */
	int word2[ALPHABET]; /* array to record characters in entered words */
	int i; /* array index */
	bool is_anagram = true;

	for (i = 0; i < ALPHABET; ++i) {
		word1[i] = 0;
		word2[i] = 0;
	}
		
	printf("Enter first word: ");
	read_word(word1);
	printf("Enter second word: ");
	read_word(word2);
	
	is_anagram = equal_array(word1, word2);

	printf("The words are %s anagrams.\n", is_anagram ? "\b" : "not");
	return 0;
}


void read_word(int counts[26]) {
	int ch; /* store user input */

	for (int i = 0; i < MAX_WORD_LEN; ++i) {
		ch = tolower(getchar());
		if (ch == '\n') {
			break;
		}
		else if (isalpha(ch)) {
			--counts[ch - 'a'];
		}
	}
	
	return;
}

bool equal_array(int counts1[26], int counts2[26]) {
	bool arrays_equal = true; /* flag indicates equality of arrays */

	for (int i = 0; i < 26; ++i) {
		if (counts1[i] != counts2[i]) {
			arrays_equal = false;
			break;
		}
	}
	return arrays_equal;
}

