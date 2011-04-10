/**
 * file: pp4.c
 * Programming Project 3
 * ch4: C Programmign: A modern Approach
 * gcc -Wall -o pp4~ pp4.c
 * 
 * Convert a base 10 int to octal.
 *  
 */


#include <stdio.h>


int main (int argc, char **argv)
{
	int base_10; /* number entered by the user */
	int octal; /* The final octal converted num */
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &base_10);
	
	octal = base_10 % 8;
	octal += 10 * ((base_10 / 8) % 8);
	octal += 100 * ((base_10 / 64) % 8);
	octal += 1000 * ((base_10 / 512) % 8);
	octal += 10000 * ((base_10 / 4096) % 8);
	
	printf("Octal num: %05d\n", octal);
	
	return 0;
}
 
