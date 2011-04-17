/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex06.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the folowing function:
 * void find_two_largest(int a[], int n, int *largest, int *second_largest);
 * When passed an array a of length 'n', the function will search a for its
 * largest and second-largest elements, storing them in the variables pointed to
 * by largest and second_largest.
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define MAX 50

/* external variables */

/* function prototypes */
void random_fill(int length, int a[length], int limit);
void find_two_largest(int a[], int n, int *largest, int *second_largest);

/* main() */
/********************************************************
 * main: implement split_time() function
 ********************************************************/
int main(void)
{

	PRINT_FILE_INFO

	int largest, second_largest;
	int a[MAX];

	random_fill(MAX, a, MAX);

	for(int i = 0; i < MAX; ++i)
		printf("a[%d]: %d\n", i, a[i]);

	find_two_largest(a, MAX, &largest, &second_largest);
	printf("largest:\t%d\nsecond_largest:\t%d\n", largest,
							second_largest);

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
 * Find largest and second-largest elements in array a[].
 */
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int smallest = a[0];
	for (int i = 0; i < n; ++i)
		if (a[i] < smallest)
			smallest = a[i];

	*largest = smallest;
	*second_largest = smallest;

	for (int i = 0; i < n; ++i) {
		if (a[i] > *largest) {
			*second_largest = *largest;
			*largest = a[i];
		}
		else if ((a[i] > *second_largest) && (a[i] < *largest))
				*second_largest = a[i];
	}

	return;
}
