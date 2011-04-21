/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12ex07.c, page 274"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the following funciton: 
 * bool search(const int a[], int n, int key)
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */

/* external variables */

/* function prototypes */
bool search(const int a[], int n, int key);
void store_zeros(int a[], int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	#define N 10
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int key = 24;
	for (int i = 0; i < N; ++i) {
		printf("a[%d]: %d\n", i, a[i]);
	}

	printf("key %d was %s found in array a[]\n", key, 
		search(a, N, key) ? "\b" : "not");

	/* ch12ex08 */
	store_zeros(a, N);

	for (int i = 0; i < N; ++i) {
		printf("a[%d]: %d\n", i, a[i]);
bool search(const int a[], int n, int key)
{
	int i;
	bool found = false;

	for (i = 0; i < n; ++i)
		if (*(a + i) == key) {
			found = true;
			break;
		}
	return found;
}

void store_zeros(int a[], int n) 
{
	for (; n-- > 0;)
		*(a++) = 0;
	return;
}
	}
	return 0;
}

/* function definitions */

bool search(const int a[], int n, int key)
{
	int i;
	bool found = false;

	for (i = 0; i < n; ++i)
		if (*(a + i) == key) {
			found = true;
			break;
		}

	return found;
}

void store_zeros(int a[], int n) 
{
	for (; n-- > 0;)
		*(a++) = 0;
	return;
}
