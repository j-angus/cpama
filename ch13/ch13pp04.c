/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* Write a program named reverse.c that echoes its command-line arguments in
 * reverse order.
 */
#define THIS_FILE "ch13pp02.c, page 311"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

#include <stdio.h>

int main(int argc, char **argv)
{	PRINT_FILE_INFO
	for (int i = argc-1; i > 0; --i)
		printf("%s%c", argv[i], i != 0 ? ' ' : '\n');
	return 0;
}
