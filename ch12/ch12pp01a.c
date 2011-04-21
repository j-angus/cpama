/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp01a.c, page 275"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write a program that reads a message then prints it in reverse.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define MAX_LENGTH 80

/* external variables */

/* function prototypes */

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	int i, ch = 0;
	char message[MAX_LENGTH];

	printf("Enter a message: ");
	for (i = 0; i < MAX_LENGTH -1; ++i){
		if ((ch = getchar()) != '\n')
			message[i] = ch;
		else break;
	}
	message[i] = '\0';


	printf("Reversal is: ");
	for (; i-- >= 0;){
		printf("%c", message[i]);
	}

	return 0;
}

/* function definitions */

