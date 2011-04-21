/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp01b.c, page 275"
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
	int ch = 0;
	char message[MAX_LENGTH];
	char *msg_ptr = message;

	printf("Enter a message: ");
/*
	while ((ch = getchar()) != '\n') {
		*(msg_ptr++) = ch;
		if (msg_ptr == (msg_ptr + (MAX_LENGTH - 1)))
			break;
	}
*/
	do {
		if ((ch = getchar()) == '\n')
			break;
		else
			*(msg_ptr++) = ch;
	} while (msg_ptr < (msg_ptr + (MAX_LENGTH - 1)));

	*msg_ptr = '\0';
	printf("You entered: %s\n", message);

	printf("Reversal is: ");
	do {
		printf("%c", *(msg_ptr--));
	} while (msg_ptr >= message);

	return 0;
}

/* function definitions */

