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
	*(++s_ptr) = '\0'; /* NUL terminate sentence to create a string */

	char *s_tail = --s_ptr; /* a pointer to the end of the sentence */
	char *w_head = --s_ptr; /* a pointer to the beginning of a word */
	char *bound; /* pointer to word boundary */

	printf("Reversal of sentence: ");
	/* first we test if sentence only contains a terminator */
	if (s_ptr != sentence) {
		while (--w_head >= sentence) {
			/* find beginning of word */
			if (*w_head == ' ' || w_head == sentence) {
				bound = w_head;
				/* don't want to print leading ' ' */
				if (*w_head == ' ')
					++w_head;
				while (w_head <= s_ptr) { /* print word */
					if (!isspace(*w_head))
						putchar(*w_head);
					++w_head;
				}
				if (bound != sentence)
					putchar(' ');
				/* reset boundaries to search for next word */
				s_ptr = --bound;
				w_head = bound;
			}
		}
		putchar(*s_tail);
	}
	else
		printf("%s\n", sentence);
	putchar('\n');

	return 0;
}
