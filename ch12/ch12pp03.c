/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp01b.c, page 275"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write a program that reads a msg then prints it in reverse.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define MSG_LEN 80

/* external variables */

/* function prototypes */

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{
	PRINT_FILE_INFO
	char msg[MSG_LEN], *msg_ptr;

	printf("Enter a msg: ");
	for (msg_ptr = msg; msg_ptr < (msg + (MSG_LEN-1)); ++msg_ptr) {
		if ((*msg_ptr = getchar()) == '\n')
			break;
	}
	*msg_ptr = '\0'; /* null terminate msg[] to make it a string */

	printf("You entered: %s\n", msg);

	printf("Reversal is: ");
	for (--msg_ptr; msg_ptr >= msg; --msg_ptr) {
		putchar(*msg_ptr);
	}
	printf("\n");
	for (int i = 0; msg[i] != '\0'; ++i)
		printf("msg[%02d]: %3d\n", i, msg[i]);
	printf("'\\n': %d\n", '\n');
	return 0;
}

/* function definitions */

