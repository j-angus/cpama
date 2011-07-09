/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.					 *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.	 *
 *********************************************************/

/* line.c (Chapter 15, page 364) */
/* @date 2011-08-09 */
/**
 * Modify 'justify' program from 15.3 by rewriting the line.c file so that it
 * stores the current line in a linked list. Each node in the list will store a
 * single word. The 'line' array will be replaced by a variable that points to
 * the node containing the first word. This variable will store a null pointer
 * whenever the line is empty.
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* for malloc, free */
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20
char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

/**
 * node: used to create a linked list of words
 */
struct word_node {
	char word[MAX_WORD_LEN+1];
	struct word_node *next;
};

struct word_node *line_list_head = NULL; /* point to head of line list */
struct word_node *line_list_tail = NULL; /* point to tail of line list */

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

/** delete words in line_list
 */
void clear_line_list(void)
{
	struct word_node *temp;

	while (line_list_head) {
		temp = line_list_head;
		line_list_head = line_list_head->next;
		free (temp);
	}
	line_list_tail = line_list_head;
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len+1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

void add_word_tolist(char *new_word)
{
	if (strlen(new_word) > MAX_WORD_LEN) { /* truncate long words */
		new_word[MAX_WORD_LEN-1] = '*';
		new_word[MAX_WORD_LEN] = '\0';
	}

	if (!line_list_head) { /* no words in the list */
		line_list_head = malloc(sizeof(struct word_node));
		if (!new_word) {
			printf("Error: in add_word_tolist, malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(line_list_head->word, new_word);
		line_list_head->next = NULL;
		line_list_tail = line_list_head;
	}
	else { /* create a new node for the list */
		struct word_node *new_node = malloc(sizeof(struct word_node));
		if (!new_node) {
			printf("Error: in add_word_tolist, malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(new_node->word, new_word);
		/* this next line has to update line_list_head->next as well...
		 * check to make sure that this will work!
		 * ie, initially, when line_list_tail == line_list_head
		 * will line_list_tail->next = new_node also update
		 * line_list_head->next to point to new_node???
		 * YES! this does work correctly.
		 */
		new_node->next = NULL;
		line_list_tail->next = new_node;
		line_list_tail = new_node;
	}
	/* increment chars in line, + 1 for whitespace not counted by strlen */
	line_len += strlen(new_word); // + 1;
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len - num_words;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			spaces_to_insert = extra_spaces / (num_words - 1);
			if ((extra_spaces > 1) && (num_words % 2))
				++spaces_to_insert;
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}

void write_line_list(void)
{
	int extra_spaces, spaces_to_insert, i;
	/* we add 1 to work out extra_spaces because we don't want to add a
	 * space after the last word */
	extra_spaces = MAX_LINE_LEN - line_len - num_words + 1;

	while (line_list_head) {
		printf("%s", line_list_head->word);
		if (line_list_head->next) {
			putchar(' ');
			spaces_to_insert = extra_spaces / (num_words-1);
			/* following logic attempts to spread spaces more
			 * evenly along the length of the long. Otherwise
			 * smaller spaces consistantly occur on the left, and
			 * larger spaces appear on thje right */
			if ((extra_spaces > 1) && (num_words % 2))
				++spaces_to_insert;
			for (i = 0; i < spaces_to_insert; ++i)
				putchar(' ');
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
		line_list_head = line_list_head->next;
	}
	putchar('\n');
	return;
}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}

void flush_line_list(void)
{
	if (line_list_head)
		write_line_list();
}
