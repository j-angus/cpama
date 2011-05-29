/* stack.h */
/* for cpama ch17ex08, page 454 */
/* implement a stack using linke lists */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* external variables */
struct node {
	int value; /* data stored in the node. */
	struct node *next; /* pointer to the next node */
};

/* the first node in the list is the top of the stack */
struct node *top;

/* function prototypes */

/**
 * make_empty: empties the stack
 */
void make_empty(void);

/**
 * is_empty: test stack for being empty
 *            returns true if stack empty
 */
bool is_empty(void);

/**
 * push: place an integer onto the stack
 */
bool push(int i);

/**
 * pop: retrieve topmost integer from the stack
 */
int pop(void);

/**
 * stack_overflow: displays an error message
 */
void stack_overflow(void);

/**
 * stack_overflow: displays an error message
 */
void stack_underflow(void);

#endif
