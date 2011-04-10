/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch07pp13.c
 * Write a program that calculates the average word length for a sentence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	int ch; /* user input */
	int wl= 0, total = 0, wc = 0;

	printf("Enter a sentence: ");

	while ((ch = getchar()) != '\n') {
		if (ch != ' ') {
			++wl;
		}
		else if (wl > 0) {
			total += wl;
			++wc;
			wl = 0;
		}
	/*
	printf ("**DEBUG** ch: '%d'\t wl: %d\t wc: %d\n", ch, wl, wc);
	*/
	}
	if (wl > 0) {
		total += wl;
		++wc;
		/*
		printf ("**DEBUG** ch: '%d'\t wl: %d\t wc: %d\n", ch, wl, wc);
		*/
	}
	printf("Average word length: %.1f\n", (double)total / wc);

	return 0;
}
