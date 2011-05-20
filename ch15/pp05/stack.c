/* stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

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
