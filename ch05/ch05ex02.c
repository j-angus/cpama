/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.					 *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.	 *
 *********************************************************/

/* ch05ex02.c */
/* logical operators */

#include <stdio.h>

int main(void)
{
	int i, j, k = 0;
	
	/* ex 2.a */
	i = 10; j = 5;
	printf("Ex2a\ti: %d, j: %d, k: %d\n", i, j, k);
	printf("!i < j: %d\n", !i < j);
	
	/* ex 2.b */
	i = 2; j = 1;
	printf("Ex2b\ti: %d, j: %d, k: %d\n", i, j, k);
	printf("!!i < !j: %d\n", !!i < !j);
	
	/* ex 2.c */
	i = 5; j = 0; k = -5;
	printf("Ex2c\ti: %d, j: %d, k: %d\n", i, j, k);
	printf("i && j || k: %d\n", i && j || k);
	
	/* ex 2.d */
	i = 1; j = 2; k = 3;
	printf("Ex2d\ti: %d, j: %d, k: %d\n", i, j, k);
	printf("i < j || k: %d\n", i < j || k);
	
	return 0;
}
