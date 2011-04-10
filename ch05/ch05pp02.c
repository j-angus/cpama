/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch05pp02.c
 * Write a program that asks the user for a 24-hour time, then dispays
 * the time in 12-hour form.
 */

#include <stdio.h>
#include <stdbool.h>

#define MIN 0
#define MAX_HR 23
#define MAX_MIN 60

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Programming Project 2\n\n");
	
	int in_hr, in_min; /* User input */
	bool cool = true; /* flag: Is user input valid? */
	bool pm = false; /* Is it morning or afternoon? */
	do {
		printf("\nEnter a 24-hour time (HH:MM): ");
		scanf("%d:%d", &in_hr, &in_min);

		if ((in_hr >= MIN && in_hr <= MAX_HR ) &&
			(in_min >= MIN && in_min <= MAX_MIN)) {
			printf("Valid 24-hour time entered.\n");
			if (in_hr > 11) {
				if (in_hr > 12)
					in_hr -= 12;
				pm = true;
			}
			else
				pm = false;
			printf("Equivalent 12-hour time: %2d:%.2d %s\n",
				in_hr, in_min, pm ? "PM" : "AM");
		}
		else {
			printf("Invalid 24-hour time entered!\n");
			cool = false;
		}
	} while (cool);
		
	return 0;
}
