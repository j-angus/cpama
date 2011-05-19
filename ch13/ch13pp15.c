/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
#define THIS_FILE "ch13pp15.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Modify ch10pp06.c to include the function:
 * int evaluate_RPN_expression(const char *expression);
 * The function returns the value of the RPN expression pointed to by
 * 'expression'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100
#define RPNEXP_LENGTH 80 /* max length of user input rpn expression */
/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* function prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int evaluate_RPN_expression(const char *expression);
int read_line(char *str, int n);

int main(void)
{	PRINT_FILE_INFO
	char rpn_express[RPNEXP_LENGTH+1]; /* user input RPN expression */

	/* loop until user does not enter a valid expression */
	while(true) {
		printf("Enter an RPN expression: ");
		read_line(rpn_express, sizeof(rpn_express));
		printf("Value of expression: %d\n", evaluate_RPN_expression(rpn_express));
	}
	return 0;
}

/* function definitions */

/**
 * Evaluates an RPN expression.
 * *expression is a NUL terminated string
 * returns the result of the expression
 * only evaluates single integer digits, 0 - 9
 */
int evaluate_RPN_expression(const char *expression)
{
	char in_str[2] = {'\0', '\0'}; /* store char converted to string */
	int val1, val2; /* store popped values */

	while (*expression) {
		*in_str = *expression;
		if (isdigit(*expression)) {
			push(atoi(in_str));
		}
		else {
			switch(*expression) {
			case '+':
				push(pop() + pop());
				break;
			case '-':
				val1 = pop();
				val2 = pop();
				push(val2 - val1);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				val1 = pop();
				val2 = pop();
				push(val2 / val1);
				break;
			case '=':
				return pop();
			default:
				/* not a valid operator */
				break;
			}
		}
		++expression;
	}
	printf("ERROR: expression did not end with '='\n");
	exit(-1); /* error, not a valid expression */
}

void make_empty(void)
{
	top = 0;
	return;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

int pop(void)
{
	if (is_empty()) {
		stack_underflow();
		exit(1);
	}
	return contents[--top];
}

void stack_overflow(void)
{
	printf("ERROR: stack_overflow, Expression is too complex.\n");
	exit(1);
}

void stack_underflow(void)
{
	printf("ERROR: stack_underflow, Not enough operands in expression.\n");
	exit(1);
}

/**
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * Returns the numbers of chars, i, stored in *str
 * 'n' is expected to be the size of the char array pointed to by *str
 */
int read_line(char *str, int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		/* we want to store at max n-1 chars into str[] */
		if (i < n-1) {
			str[i++] = ch;
		}
		else
			break;
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}
