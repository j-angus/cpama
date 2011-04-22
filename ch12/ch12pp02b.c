/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp02b.c, page 276"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write a program that reads a message, then checks whether it's a
   palindrome. Use pointers to process char array.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

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
	char *msg_ptr = &message[0];

	printf("Enter a message: ");
	while (msg_ptr < (message + MAX_LENGTH -1) &&
			(ch = getchar()) != '\n') {
		if (isalpha(ch))
			*(msg_ptr++) = ch;
	}
	*msg_ptr = '\0';

	/* determine if message is a palindrome */
	bool palindrome = true;
	char *head = message;

	/* if just '\n' entered, message only contains '\0' */
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
		printf("message '%s' is %s a palindrome\n", message,
			palindrome ? "\b" : "not");
	}
	else
		printf("No message entered doofus.\n");
	return 0;
}

/* function definitions */

