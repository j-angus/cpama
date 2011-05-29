/* stack.c */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void make_empty(void)
{
	for (; top != NULL; top = top->next)
		free(top);
	return;
}

bool is_empty(void)
{
	return top == NULL;
}

bool push(int i)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		stack_overflow();
		return false;
	}

	new_node->value = i;
	new_node->next = top;
	top = new_node;

	return true;
}

int pop(void)
{
	struct node *p;

	if (is_empty()) {
		stack_underflow();
		exit(1);
	}

	int i = top->value;
	p = top;
	top = top->next;
	free(p);
	return i;
}

void stack_overflow(void)
{
	printf("ERROR: stack_overflow, not enough memory.\n");
	exit(1);
}

void stack_underflow(void)
{
	printf("ERROR: stack_underflow, Stack empty.\n");
	exit(1);
}
