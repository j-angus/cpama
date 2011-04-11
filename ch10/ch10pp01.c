/**********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition  *
 * By K. N. King					  *
 *********************************************************/

#define THIS_FILE "ch10pp01.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Implement a stack to check correct nesting of parentheses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define STACK_SIZE 100
#define LINE_MAX 99
/* external (global) variables */
char contents[STACK_SIZE];
int top = 0;
/* function prototypes */

void stack_overflow(void);
void stack_underflow(void);

/* function definitions */
void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char ch)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = ch;
}


char pop(void)
{
	if (is_empty()) {
		stack_underflow();
		exit(1);
	}
	else
		return contents[--top];
}


/* main loop
 *
 */
int main(void)
{
	PRINT_FILE_INFO
	char ch;
	char line[LINE_MAX];

	printf("Enter parentheses and/or braces: ");
	scanf("%99s", line);
	for (int i = 0; i <= strlen(line); ++i) {
		printf("line[%d]: %c\n", i, line[i]);
		switch(line[i]) {
		case '(': case '{':
			push(line[i]);
			break;
		case ')':
			if ((ch = pop()) != '(') {
				printf("Bad bracing, better luck next time.\n");
				exit(1);
			}
			break;
		case '}':
			if ((ch = pop()) != '{') {
				printf("Bad bracing, better luck next time.\n");
				exit(1);
			}
			break;
		case '\0':
			if (is_empty()) {
				printf("Parentheses/braces correctly nested.\n");
				break;
			} else {
				printf("Bad bracing, better luck next time.\n");
				exit(1);
			}
			break;
		default:
			printf("ERROR: Bad input, program terminating.\n");
			exit(1);
			break;
		}
	}
	return 0;
}

/* function definitions */
void stack_overflow(void)
{
	printf("ERROR: Stack overflow!\n");
	exit(1);
}

void stack_underflow(void)
{
	printf("Stack is empty, this is bad!\n");
}
