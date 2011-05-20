/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/
#define THIS_FILE "ch15pp05.c, page 373"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* For ch15pp05: Incorporate stack functions into stack.c/stack.h files */
/* For ch13pp15: Modify ch10pp06.c to include the function:
 * int evaluate_RPN_expression(const char *expression);
 * The function returns the value of the RPN expression pointed to by
 * 'expression'.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "readline.h"


#define RPNEXP_LENGTH 80 /* max length of user input rpn expression */

/* function prototypes */

int evaluate_RPN_expression(const char *expression);


int main(void)
{	PRINT_FILE_INFO
	char rpn_express[RPNEXP_LENGTH+1]; /* user input RPN expression */

	/* loop until user does not enter a valid expression */
	while(true) {
		printf("Enter an RPN expression: ");
		readline(rpn_express, sizeof(rpn_express));
		printf("Value of expression: %d\n",
					evaluate_RPN_expression(rpn_express));
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

