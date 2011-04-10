/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch08pp14.c
 * Write a program that reverses the words in a sentence.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 128

int main(void)
{
	int ch; /* user input */
	char sentence[MAX_LEN]; /* array to store user entered sentence */
	char terminator = '\0'; /* holds end of sentence terminator */
	int i, j; /* array index */

	for (i = 0; i < MAX_LEN; ++i)
		sentence[i] = '\0';

	printf("Enter a sentence (max %d char long,)'.', '!', '?' to end: ", MAX_LEN);
	for (i = 0; i < MAX_LEN; ++i) {
		ch = getchar();
		if (ch != '.' && ch != '!' && ch != '?') {
			sentence[i] = ch;
		}
		else {
			terminator = ch;
			break;
		}
	}

	printf("Reversal of sentence: ");
	
	/* seek from end of array backwards to the last letter */
	i = MAX_LEN - 1;
	while (sentence[i] != '\0')
		--i;
	j = i;
	for (; i >= 0; --i) {
		if (sentence[i] == ' ') {
			for (int k = i + 1; k <=j; ++k) 
				printf("%c", sentence[k]);
			printf("%c", sentence[i]);
			j = i;
		}
		else if (sentence[j] == ' ')
			j = i;
	}
	for (i = 0; i <=j; ++i) 
		printf("%c", sentence[i]);
		
	printf("%c\n", terminator);
	
	return 0;
}
