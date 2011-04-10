/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.					 *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.	 *
 *********************************************************/

/* ch05ex01.c */


#include <stdio.h>

int main(void)
{
	int i, j, k;
	
	/* ex 1.a */
	i = 2; j = 3;
	k = i * j == 6;
	printf("Ex1.(a)\tk: %d\n", k);
	
	/* ex 1.b */
	i = 5; j = 10; k = 1;
	printf("Ex1.(b)\ti = %d; j = %d; k = %d\n", i, j, k);
	printf("k > i < j: %d\n", k > i < j);
	
	/* ex 1.c */
	i = 3; j = 2; k = 1;
	printf("Ex1.(c)\ti = %d; j = %d; k = %d\n", i, j, k);
	printf("i < j == j < k: %d\n", i < j == j < k);
	
	/* ex 1.d */
	i = 3; j = 4; k = 5;
	printf("Ex1.(d)\ti = %d; j = %d; k = %d\n", i, j, k);
	printf("i %% j + i < k: %d\n", i % j + i < k);
	printf("%d %% %d + %d: %d\n", i, j, i, i % j + i);
	
	
	
	return 0;
}
