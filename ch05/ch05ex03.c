/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* ch05ex03.c */
/* illustrate short-circuit behaviour of logical expressions */

#include <stdio.h>

int main(void)
{
	int i, j, k = 0;
	
	/* ex 3.a */
	i = 3; j = 4; k = 5;
	printf("Ex3a\ni == %d, j == %d, k == %d\n", i, j, k);
	printf("i < j || ++j < k: %d\n", i < j || ++j < k);
	printf("i == %d, j == %d, k == %d\n", i, j, k);
	
	/* ex 3.b */
	i = 7; j = 8; k = 9;
	printf("Ex3b\ni == %d, j == %d, k == %d\n", i, j, k);
	printf("i - 7 && j++ < k: %d\n", i - 7 && j++ < k);
	printf("i == %d, j == %d, k == %d\n", i, j, k);

	/* ex 3.c */
	i = 7; j = 8; k = 9;
	printf("Ex3c\ni == %d, j == %d, k == %d\n", i, j, k);
	printf("(i = j) || (j = k): %d\n", (i = j) || (j = k));
	printf("i == %d, j == %d, k == %d\n", i, j, k);

	/* Ex3d */
	i = 1; j = 1; k = 1;
	printf("Ex3d\ni == %d, j == %d, k == %d\n", i, j, k);
	printf("++i || ++j && ++k: %d\n", ++i || ++j && ++k);
	printf("i == %d, j == %d, k == %d\n", i, j, k);
	
	return 0;
}
