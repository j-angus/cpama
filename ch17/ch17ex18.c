/* ch17ex18.c */
/* sort array in descending order */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 20

int compare_int(const void *x, const void *y);

int main (void)
{
	int a[LENGTH]; /* = {9, 1, 2, 8, 7, 4, 6, 5, 0, 3}; */
	int i;

	for (i = 0; i < LENGTH; ++i)
		printf("a[%d] = %d\n", i, a[i]);

	qsort(a, LENGTH, sizeof(a[0]), compare_int);

	for (i = 0; i < LENGTH; ++i)
		printf("a[%d] = %d\n", i, a[i]);

	return 0;
}

/**
 * compare_int: returns x < y: -1
 * 			x == y: 0
 * 			x > y: +1
 */
int compare_int(const void *x, const void *y)
{
	const int *x1 = x;
	const int *y1 = y;

	/* x1 < y1 = -1: sort ascending order */
	/* x1 > y1 = -1: sort descending order */
	return ((*x1 > *y1) ? -1 : ((*x1 == *y1) ? 0 : 1));
}
