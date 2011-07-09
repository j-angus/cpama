/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.					 *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.	 *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */
/* @date 2011-08-09 */
/**
 * Modify 'justify' program from 15.3 by rewriting the line.c file so that it
 * stores the current line in a linked list. Each node in the list will store a
 * single word. The 'line' array will be replaced by a variable that points to
 * the node containing the first word. This variable will store a null pointer
 * whenever the line is empty.
 */

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
	char word[MAX_WORD_LEN+2];
	int word_len;

	//clear_line();
	clear_line_list();

	for (;;) {
		word_len = read_word(word, MAX_WORD_LEN+1);
		if (word_len == 0) {
			//flush_line();
			flush_line_list();
			return 0;
		}
		if (word_len + 1 > space_remaining()) {
			//write_line();
			write_line_list();
			//clear_line();
			clear_line_list();
		}
		//add_word(word);
		add_word_tolist(word);
	}
}
