/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.					 *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.	 *
 *********************************************************/

#define THIS_FILE "ch12p06.c, page 276"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);
/* use pointers to keep track of array position
   based on maxmin.c (Chapter 11, page 250)
   Finds the largest and smallest elements in an array
 */
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{ PRINT_FILE_INFO
	int b[N], i, big, small;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &b[i]);

	max_min(b, N, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int *p = a;

	*max = *min = *p;
	for (++p; p < a + n; ++p) {
		if (*p > *max)
			*max = *p;
		else if (*p < *min)
			*min = *p;
	}
}
