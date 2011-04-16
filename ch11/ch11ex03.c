/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex03.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/*
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* defines */
#define MAX_NUM 10
/* external variables */

/* function prototypes */
void avg_sum(double a[], int n, double *avg, double *sum);

/* main() */
/********************************************************
 * main: Read a number input from the user.
 * 	calls: clear_digit_array(), process_digit(),
 * 		print_digit_array()
 ********************************************************/
int main(void)
{

	PRINT_FILE_INFO

	double numbers[MAX_NUM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double avg, sum;

	printf("address: &sum: %p\n", &sum);
	avg_sum(numbers, MAX_NUM, &avg, &sum);

	printf("avg: %f, sum: %f\n", avg, sum);

	return 0;
}

/* function definitions */
void avg_sum(double a[], int n, double *avg, double *sum)
{
	int i;

	*sum = 0.0;

	printf("address: sum: %p\n", sum);

	for (i = 0; i < n;  ++i)
		*sum += a[i];

	*avg = *sum / n;

	return;
}
