/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch07pp06.c
 * Write a program that prints the sizes of integer types.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	printf("sizeof(char):\t\t%2d bytes\n", sizeof(char));
	printf("sizeof(short):\t\t%2d bytes\n", sizeof(short));
	printf("sizeof(int):\t\t%2d bytes\n", sizeof(int));
	printf("sizeof(long):\t\t%2d bytes\n", sizeof(long));
	printf("sizeof(float):\t\t%2d bytes\n", sizeof(float));
	printf("sizeof(double):\t\t%2d bytes\n", sizeof(double));
	printf("sizeof(long double):\t%2d bytes\n", sizeof(long double));

	return 0;
}
