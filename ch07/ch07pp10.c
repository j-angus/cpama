/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch07pp10.c
 * Write a program that counts the number of vowels in a sentence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int ch; /* user input */
	int num_vowels = 0;
	bool cool = true;

	printf("Enter a sentence: ");

	while ((ch = toupper(getchar())) != '\n') {
		switch (ch) {
			case 'A': case 'E': case 'I': case 'O': case 'U':
				++num_vowels;
				break;
		}
	}
	printf("Your sentence contains %d vowels.\n", num_vowels);

	return 0;
}
