/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp04.c, page 276"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write a program that reads a msg, then checks whether it's a
   palindrome. Use pointers to process char array.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

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
		else if (!isalpha(*msg_ptr))
			--msg_ptr;
	}
	*msg_ptr = '\0';

	/* determine if msg is a palindrome */
	bool palindrome = true;
	char *head = msg;

	/* if just '\n' entered, msg only contains '\0' */
	if (head < msg_ptr) {
		--msg_ptr; /* point to char before last char: \0 */
		while (head < msg_ptr) {
			printf("*head: %c, *msg_ptr: %c\n", *head, *msg_ptr);

			if (*head != *msg_ptr) {
				palindrome = false;
				break;
			}
			++head, --msg_ptr;
		}
		printf("msg '%s' is %s a palindrome\n", msg,
			palindrome ? "\b" : "not");
	}
	else
		printf("No msg entered doofus.\n");
	return 0;
}

/* function definitions */

