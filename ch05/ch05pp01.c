/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch05pp01.c
 * Write a program that calculates how many digits a number contains.
 * Assume numbers are no longer than 4 digits.
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN 0
#define MAX 10000

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Programming Project 1\n\n");
	
	int num;
	bool cool = true;
	do {
		printf("Enter at most a positive four digit number: ");
		scanf("%d", &num);

		if (num >= MIN && num < MAX ) {
			printf("\nNumber %d has ", num);
			if (num < 10)
				printf("one digit.\n\n");
			else if (num < 100)
				printf("two digits.\n\n");
			else if (num < 1000)
				printf("three digits.\n\n");
			else
				printf("four digits.\n\n");
		}
		else {
			printf("\nInvalid number turkey!\n");
			cool = false;
		}
	} while (cool);
		
	return 0;
}
