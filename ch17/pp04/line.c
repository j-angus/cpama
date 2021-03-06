/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define WORD_LEN 20

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

struct a_word {
	char word[WORD_LEN+1]; /* fixed size string array */
	char *dyn_word; /* this needs to be allocted memory dynamically */
	struct a_word *next;
};

struct a_word *first_word = NULL;
struct a_word *cur_word = NULL;

void clear_line(void)
{
	/* Delete all nodes in array */
	struct a_word *temp;
	while (first_word != NULL) {
		temp = first_word;
		first_word = first_word->next;
		free(temp);
	}

  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0)
		++line_len;  /* count spaces after words */

	if (first_word == NULL) { /* adding first word to first_word */
		first_word = malloc(sizeof(struct a_word));
		if (first_word != NULL) {
			strcpy(first_word->word, word);
			/* first_word->dyn_word = malloc(sizeof(word)+1);
			 * strcpy(first_word->dyn_word, word);
			 */
			strcpy(first_word->word, word);
			first_word->next = NULL;
			cur_word = first_word;
		} else {
			printf("ERROR: Unable to allocate memory for word.\n");
			exit(1);
		}
	} else {
		struct a_word *temp = malloc(sizeof(struct a_word));
		if (temp != NULL) {
			strcpy(temp->word, word);
			/* temp->dyn_word = malloc(sizeof(word)+1);
			 * strcpy(temp->dyn_word, word);
			 */
			strcpy(temp->word, word);
			temp->next = NULL;
			cur_word->next = temp;
			cur_word = temp;
		} else {
			printf("ERROR: Unable to allocate memory for word.\n");
			exit(1);
		}
	}
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
	int extra_spaces, spaces_to_insert, i;

	extra_spaces = MAX_LINE_LEN - line_len;
	struct a_word *line_out = first_word;
	for ( ; line_out != NULL; line_out = line_out->next) {
		printf("%s", line_out->word);
		if (line_out->next != NULL) {
			putchar(' ');
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (i = 0 ; i < spaces_to_insert; i++) {
				putchar(' ');
			}
			extra_spaces -= spaces_to_insert;
			--num_words;
		}
	}
	printf("\n");
}

void flush_line(void)
{
  if (line_len > 0) {
	struct a_word *line_out = first_word;
	for ( ; line_out != NULL; line_out = line_out->next) {
		printf("%s\n", line_out->word);
	}
  }
}
