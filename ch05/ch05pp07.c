/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch05pp07.c
 * Write a program that finds the largest and smallest of four integers
 * entered by the user.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Programming Project 7\n\n");
	
	int n1, n2, n3, n4; /* User input */
	int large, small;
	bool cool = true; /* flag: Is user input valid? */

	do {
		printf("\nEnter four integers: ");
		scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

		if (n1 > n2 && n1 > n3 && n1 > n4) {
			large = n1;
			small = n2 > n3 ? (n3 > n4 ? n4 : n3) :
				(n2 > n4 ?  n4 : n2);
		}
		else if (n2 > n3 && n2 > n4) {
			large = n2;
			small = n1 > n3 ? (n3 > n4 ? n4 : n3) :
				(n1 > n4 ?  n4 :  n1);
		}
		else if (n3 > n4) {
			large = n3;
			small = n1 > n2 ? (n2 > n4 ? n4 : n2) :
				(n1 > n4 ?  n4 :  n1);
		}
		else {
			large = n4;
			small = n1 > n2 ? (n2 > n3 ? n3 : n2) :
				(n1 > n3 ?  n3 :  n1);
			/*
			 * printf("Invalid numbers dude! Fail.\n");
			 * cool = !cool;
			 */
		}
		if (cool) {
			printf("Largest: %d\n", large);
			printf("Smallest: %d\n", small);
		}
	} while (cool); /* Infinite loop - control-c to quit */
		
	return 0;
}
