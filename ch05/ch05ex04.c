/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* ch05ex04.c */
/* write a single expression whose value is either -1, 0, or +1,
 * depending on whether i is less than, equal to, or greater than j
 * respectively. */

#include <stdio.h>

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n");
	printf("Chapter 5, Exercise 4\n");
	
	int i, j;
	i = 1; j =2;
	printf("i == %d, j == %d\n", i, j);
	printf("i < j ? -1 : (i == j ? 0 : 1): %2d\n", 
					i < j ? -1 : (i == j ? 0 : 1));
	i = 1; j =1;
	printf("i == %d, j == %d\n", i, j);
	printf("i < j ? -1 : (i == j ? 0 : 1): %2d\n", 
					i < j ? -1 : (i == j ? 0 : 1));
	i = 2; j =1;
	printf("i == %d, j == %d\n", i, j);
	printf("i < j ? -1 : (i == j ? 0 : 1): %2d\n", 
					i < j ? -1 : (i == j ? 0 : 1));
	
	
	return 0;
}
