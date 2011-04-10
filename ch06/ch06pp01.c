/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch06pp01.c
 * Write a program that finds the largest in a series of numbers entered
 * by the user. The program must prompt the user to enter the numbers
 * one by one. When the user enters 0 or a negative number, the program
 * must display the lasrgest non-negative number entered.
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN 0
#define MAX 10000

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 6, Programming Project 1\n\n");
	
	double num, large = 0;
	bool cool = true;
	do {
		printf("Enter a positive number: ");
		scanf("%lf", &num);

		if (num > MIN) {
			if (num > large)
			large = num;
		}
		else {
			printf("\nSeeya turkey!\n\n");
			cool = !cool;
		}
	} while (cool);
	if (large)
		printf("The largest number entered was %.2f\n", large);

	return 0;
}
