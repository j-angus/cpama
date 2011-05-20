/* stack.h */
/* cpama ch15pp05, page 375 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

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
 * is_full: test stack for being full
 *          returns true if stack full
 */
bool is_full(void);

/**
 * push: place an integer onto the stack
 */
void push(int i);

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
