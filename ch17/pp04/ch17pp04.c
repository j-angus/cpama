/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 *********************************************************/

/* ch17pp04.c */
/**
 * Rewrite line.c so that it stores the current line in a linked list. Each
 * node in the list will store a single word. The 'line[]' array will be
 * replaced by a variable that points to the node containing the first word.
 * This variable will store a null pointer whenever the line is empty.
 */
/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
  char word[MAX_WORD_LEN+2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }
}
