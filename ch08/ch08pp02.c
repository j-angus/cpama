/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King																				 *
 *********************************************************/

/* ch08pp02.c */
/* from repdigit.c (Chapter 8, page 166) */
/* Checks numbers for repeated digits */

#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
	int digit;
	int total[10] = {0}; /* store num times a digit appears */
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		++total[digit];
		n /= 10;
	}

	printf("Digit:\t\t");
	for (int i = 0; i < (int)(sizeof(total) / sizeof(total[0])); ++i)
		printf("%5d", i);
	printf("\nOcccurrences:\t");
	for (int i = 0; i < (int)(sizeof(total) / sizeof(total[0])); ++i)
		printf("%5d", total[i]);
	printf("\n");

	return 0;
}
