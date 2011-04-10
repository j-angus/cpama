/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch08pp15.c
 * Encrypt a sentence with the caeser cypher.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 80
#define MAX_SHIFT 25
int main(void)
{
	int ch; /* user input */
	char sentence[MAX_LEN]; /* array to store user entered sentence */
	int i; /* array index */
	int shift; /* cypher shift entered by user */
	for (i = 0; i < MAX_LEN; ++i)
		sentence[i] = '\0';
		
	printf("Enter message to be encrypted: ");
	for (i = 0; i < MAX_LEN; ++i) {
		ch = getchar();
		if (ch == '\n') {
			break;
		}
		else
			sentence[i] = ch;
	}

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	
	if (0 < shift && shift <= MAX_SHIFT)
		;
	else {
		printf("\nERROR: you failed, legal shift amount between 1 and "
			"%d. Loser.\n", MAX_SHIFT);
		exit(1);
	}
	
	for (i = 0; i < MAX_LEN; ++i) {
		if (isalpha(sentence[i])) {
			if (isupper(sentence[i])) {
				sentence[i] = 
					((sentence[i] - 'A') + shift) % 26 + 'A';
			}
			else {
				sentence[i] = 
					((sentence[i] - 'a') + shift) % 26 + 'a';
			}	
		}
	}
	
	for (i = 0; i < MAX_LEN; ++i)
		printf("%c", sentence[i]);
	printf("\n");		
	return 0;
}
