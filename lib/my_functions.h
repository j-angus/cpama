/**
 * my_functions.h
 * A compilation of handy non-standard library functions
 */

#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 80

/**
 * read_line:
 *
 * Reads a line of characters ignoring leading whitespace, storing them in str[]
 * Discards '\n' and appends '\0' to end of text.
 * n is the size of str[]
 * Returns the numbers of chars, i, stored in str[]
 *
 * IDEA: If str[] is initialised with data and NUL terminated prior to passing
 * to the function, we can test that it is a valid str and its length should
 * be equal to n... Relies on function user correctly setting up string first,
 * but that is there problem, we can abort the function if str[] is not found
 * to be valid.
 */
int read_line(char str[], int n);

#endif
