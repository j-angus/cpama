/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex08.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the folowing function:
 * int *find_largest(int a[], int n);
 * When passed an array 'a' of length 'n', the function will return a pointer
 * to the array's largest element.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define MAX 20 /* Max array size */

/* external variables */

/* function prototypes */
void random_fill(int length, int a[length], int limit);
int *find_largest(int a[], int n);

/* main() */
/********************************************************
 * main: implement find_largest() function
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO

	int *lrg_ptr; /* stores index to largest element within a[] */
	int a[MAX];

	random_fill(MAX, a, MAX);

	for(int i = 0; i < MAX; ++i)
		printf("a[%d]: %d\n%s", i, a[i], i == MAX -1 ? "\n" : "");

	lrg_ptr = find_largest(a, MAX);
	printf("*lrg_ptr:\t %02d\n\n", *lrg_ptr);

	printf("lrg_ptr: %ld, &a[0]: %ld, a: %ld\n", lrg_ptr, &a[0], a);
	printf("lrg_ptr - &a[0]: %02ld\n", lrg_ptr - &a[0]);
	printf("lrg_ptr - a[0]:\t %02ld\n", lrg_ptr - a);

	return 0;
}

/* function definitions */

/**
 * fill an array with random integers
 */
void random_fill(int length, int a[length], int limit)
{
	srand((unsigned) time(NULL)); /* seed random generator */

	for (int i = 0; i < length; ++i)
		a[i] = rand() % limit;
	return;
}

/**
 * Find largest element in array a[].
 */
int *find_largest(int a[], int n)
{
	/* int largest = a[0]; */
	int *lrg_ptr = &a[0];

	for (int i = 0; i < n; ++i) {
		if (a[i] > *lrg_ptr) {
			/* largest = a[i]; */
			lrg_ptr = &a[i];
		}
	}

	return lrg_ptr;
}
