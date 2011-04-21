/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12ex07.c, page 274"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Rewrite function sum_array() to use pointer arithmetic instead of
 * array subscripting. 
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */

/* external variables */

/* function prototypes */
int sum_array(const int *a, int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	#define N 10
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for (int i = 0; i < N; ++i) {
		printf("a[%d]: %d\n", i, a[i]);
	}

	int sum = sum_array(a, N);

	printf("sum == %d\n", sum);

	return 0;
}

/* function definitions */

int sum_array(const int *a, int n)
{
	int i, sum;

	sum = *a;
	for (i = 1; i < n; ++i)
		sum += *(a + i);
	return sum;
}
