/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch05pp11.c
 * Write a program that asks the user for a two-digit number then prints the
 * English word for the number.
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN -100
#define MAX  100

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Programming Project 11\n\n");
	
	int num; /* User input */
	int tens, ones; 
	bool cool = true; /* flag: Is user input valid? */

	do {
		printf("\nEnter a two-digit number: ");
		scanf("%d", &num);

		if (num > MIN && num < MAX) {
			
			printf("You entered the number ");
			if (num < 0) {
				printf("minus ");
				num *= -1;
			}
			ones = num % 10;
			tens = num - ones;
			if (num > 10 && num < 20) {
				switch (num) {
					case 11: printf("eleven."); break;
					case 12: printf("twelve."); break;
					case 13: printf("thirteen."); break;
					case 14: printf("fourteen."); break;
					case 15: printf("fifteen."); break;
					case 16: printf("sixteen."); break;
					case 17: printf("seventeen."); break;
					case 18: printf("eighteen."); break;
					case 19: printf("nineteen."); break;
				}
			}
			else if (num == 0)
					printf("zero.");
			else {
				switch (tens) {
					case 10: printf("ten"); break;
					case 20: printf("twenty"); break;
					case 30: printf("thirty"); break;
					case 40: printf("forty"); break;
					case 50: printf("fifty"); break;
					case 60: printf("sixty"); break;
					case 70: printf("seventy"); break;
					case 80: printf("eighty"); break;
					case 90: printf("ninety"); break;
				}
				if (num > 10)
					if (ones != 0)
						printf("-");
					
				switch (ones) {
					case 0: printf("."); break;
					case 1: printf("one."); break;
					case 2: printf("two."); break;
					case 3: printf("three."); break;
					case 4: printf("four."); break;
					case 5: printf("five."); break;
					case 6: printf("six."); break;
					case 7: printf("seven."); break;
					case 8: printf("eight."); break;
					case 9: printf("nine."); break;
				}
			}
		}
		
		else {
			printf("Invalid number dude! You Failed.\n");
			 cool = !cool;
		}

	} while (cool);

	return 0;
}
