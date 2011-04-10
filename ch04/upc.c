/**
 * file: upc.c
 * Programming Project 3
 * ch4: C Programmign: A modern Approach
 * gcc -Wall -o upc upc.c
 * 
 * Computes a Universal Product Code check digit.
 *  
 */


#include <stdio.h>

/**
 * Reverses a three digit integer. 
 */
int rev_int(int num)
{	
	return ((num % 10) * 100) + ((num % 100) - (num % 10)) + (num / 100);
}

int main (void)
{
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, 
									total;
	printf("Enter the first (single) digit: ");
	scanf("%1d", &d);
	printf("Enter first group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	printf("Enter second group of five digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
	
	first_sum = d + i2 + i4 + j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;
	
	printf("Check Digit: %d\n", 9 - ((total - 1) % 10));
	
	return 0;
}

