/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12ex01.c, page 273"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/*
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */

/* external variables */

/* function prototypes */


/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
	int *p = &a[1], *q = &a[5];

	/* value of *(p + 3) == a[4] == 14 */
	printf("*(p + 3) == %d\n", *(p + 3));

	/* value of *(q - 3) == a[2] == 34 */
	printf("*(q - 3) == %d\n", *(q - 3));

	/* value of q - p == 4 */
	printf(" q - p == %ld\n", q - p);

	printf(" p < q : %s\n", p < q ? "true" : "false");
	printf("*p < *q : %s\n", *p < *q ? "true" : "false");

	/* ch12ex02 */
	int *low = p, *high = q, *middle;
	middle = low + ((int)(high - low) / 2);
	printf("middle: %ld, low: %ld, high: %ld\n", middle, low, high);
	printf("middle = low + ((int)(high - low) / 2): %ld\n",
					middle = low + ((int)(high - low) / 2));

	/* ch12ex04 */
	#define N 10
	int b[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	p = &b[0];
	q = &b[N -1];
	int temp;
	while (p < q) {
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}
	for (int i = 0; i < N; ++i) {
		printf("b[%d]: %d\n", i, b[i]);
	}


	return 0;
}

/* function definitions */

