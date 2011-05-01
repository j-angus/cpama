/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* Modify ch05pp11.c so that it uses arrays ccontaining pointers to
 * strings instead of switch statements. Use digits as indexes into the
 * array to print the corresponding text.
 * ch05pp11.c
 * Write a program that asks the user for a two-digit number then prints the
 * English word for the number.
 */

#include <stdio.h>
#include <stdbool.h>

/* defines */
#define THIS_FILE "ch13pp18.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);
#define MIN -100
#define MAX  100
#define ONES 10 /* number of elements in ones[] array */
#define TEENS 10 /* those difficult numbers between 10 and 19 */
#define TENS 10 /* number of elements in tens[] array */

/* external variables */
char *ones[ONES] = {"zero", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine"};
char *teens[TEENS] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
			"fifteen", "sixteen", "seventeen",
			"eighteen", "nineteen"};
char *tens[TENS] = {"", "ten", "twenty", "thirty", "forty", "fifty",
			"sixty", "seventy", "eighty", "ninety"};

int main(void)
{	PRINT_FILE_INFO
	int num; /* User input */
	int tens_idx, ones_idx; /* offsets into char arrays */
	bool cool = true; /* flag: Is user input valid? */

	while (cool) {
		printf("\nEnter a two-digit number: ");
		scanf("%d", &num);
		if (num > MIN && num < MAX) {
			printf("You entered the number ");
			if (num < 0) {
				printf("minus ");
				num *= -1;
			}
			ones_idx = num % 10;
			tens_idx = num / 10;
			/* num between 10 and 19 */
			if (9 < num && num < 20) {
				printf("%s\n", teens[ones_idx]);
				continue; /* no further processing required */
			}
			/* num between 20 and 99 */
			else if (num > 19) {
				printf("%s%c", tens[tens_idx],
						(num % 10) ? '-' : '\n');
				if (ones_idx)
					printf("%s\n", ones[ones_idx]);
			}
			/* num between 0 and 9 */
			if (num < 10)
				printf("%s\n", ones[ones_idx]);
		}
		else {
			cool = !cool;
			printf("Error: Number not between %d and %d.\n",
				MIN, MAX);
		}
	}
	return 0;
}
