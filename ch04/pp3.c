/**
 * file: pp3.c
 * Programming Project 3
 * ch4: C Programmign: A modern Approach
 * gcc -Wall -o pp3 pp3.c
 * 
 * Displays reversed 3 digit number entered by the user.
 *  
 */


#include <stdio.h>


int main (int argc, char **argv)
{
	int i1, i2, i3; /* digits entered by the user */
	
	printf("Please enter a positive three digit number: ");
	scanf("%1d%1d%1d", &i1, &i2, &i3);
	
	printf("Digits reversed: %d%d%d\n", i3, i2, i1);
	
	return 0;
}
