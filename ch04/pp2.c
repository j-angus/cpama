/**
 * file: pp2.c
 * Programming Proj #2
 * ch4: C Programmign: A modern Approach
 * gcc -Wall -o rev_digits pp2.c
 * 
 * Displays reversed 3 digit number entered by the user.
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

int main (int argc, char **argv)
{
	int num; /* the number entered by the user */
	
	printf("Please enter a positive three digit number: ");
	scanf("%d", &num);
	printf("You entered: %d\n", num);
	
	if (num < 100 || num > 999) {
		printf("That was a crap number!\n");
		printf("You're supposed to enter a positive three digit "
			"number dude.\n");
	}
	else
		printf("Digits reversed: %03d\n", rev_int(num));
	
	return 0;
}
