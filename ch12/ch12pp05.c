/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch12pp05.c
 * Write a program that reverses the words in a sentence.
 * Use a pointer to keep track of position in array.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define LENGTH 80

int main(void)
{
	char sentence[LENGTH]; /* array to store user entered sentence */
	char *s_ptr; /* pointer to sentence */
	char term = '\0'; /* holds end of sentence terminator */
	int i, j; /* array index */

	/* Initialise array */
	for (s_ptr = sentence; s_ptr < (sentence + LENGTH); ++s_ptr)
		*s_ptr = '\0';

	printf("Enter a sentence (max %d char long,)'.', '!', '?' to end: ",
			LENGTH);

	for (s_ptr = sentence; s_ptr < (sentence + LENGTH); ++s_ptr) {
		*s_ptr = getchar();
		if (*s_ptr == '.' || *s_ptr == '!' || *s_ptr == '?') {
			term = *s_ptr;
			break;
		}
	}
	*s_ptr = '\0';

	printf("Reversal of sentence: ");

	/* seek from end of array backwards to the last letter in the string */
	i = LENGTH - 1;
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

	printf("%c\n", term);

	return 0;
}
