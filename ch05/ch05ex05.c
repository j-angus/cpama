/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* ch05ex08.c */
/* write a single expression whose value is either -1, 0, or +1,
 * depending on whether i is less than, equal to, or greater than j
 * respectively. */

#include <stdio.h>

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Exercise 5\n\n");
	
	int n = 5;
	/* is the following logical statement legal? */
	
	if (n >= 1 <= 10)
		printf("n,(%d), is between 1 and 10\n", n);
		
	/* what happens if n == 0 ? */
	
	n = 0;
	if (n >= 1 <= 10)
		printf("n,(%d), is between 1 and 10\n", n);
	
	/* logical statement is legal, but not giving the desired
	 * result due to operator precedence. To find out if 'n' lies
	 * between 1 and 10, write expression thus: */
	 
	 n = 5;
	 if (n > 1 && n < 10)
		printf("n,(%d), is between 1 and 10\n", n);
		
	n = 0;
	if (n > 1 && n < 10)
		printf("n,(%d), is between 1 and 10\n", n);
	else
		printf("n,(%d), is not between 1 and 10\n", n);
		
	return 0;
}
