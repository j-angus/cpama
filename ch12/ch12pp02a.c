/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch12pp01a.c, page 275"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write a program that reads a message, then checks whether it's a
   palindrome.
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
	int i, ch = 0;
	char message[MAX_LENGTH];

	printf("Enter a message: ");
	for (i = 0; i < MAX_LENGTH -1; ++i) {
		if ((ch = getchar()) != '\n') {
			if (isalpha(ch))
				message[i] = ch;
			else
				--i;
		}
		else break;
	}
	message[i] = '\0';

	/* determine if message is a palindrome */
	bool palindrome = true;
	int head = 0, tail = i - 1;

	/* if just '\n' entered, message only contains '\0' */
	if (message[0]) {
		while (head < tail) {
			printf("message[%d]: %c, message[%d]: %c\n",
					head, message[head],
					tail, message[tail]);

			if (message[head] != message[tail]) {
				palindrome = false;
				break;
			}
			++head, --tail;
		}
		printf("message '%s' is %s a palindrome\n", message,
			palindrome ? "\b" : "not");
	}
	else
		printf("No message entered doofus.\n");
	return 0;
}

/* function definitions */

