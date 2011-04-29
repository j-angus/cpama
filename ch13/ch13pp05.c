/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* Write a program named sum.c that adds up its command-line arguments, which
 * are assumed to be integers.
 */
#define THIS_FILE "ch13pp05.c, page 312"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

#include <stdio.h>
#include <stdlib.h> /*  for atoi() */

int main(int argc, char **argv)
{	PRINT_FILE_INFO
	int i, total = 0;

	for (i = 0; i < argc; ++i)
		total += atoi(argv[i]);

	printf("Total: %d\n", total);

	return 0;
}
