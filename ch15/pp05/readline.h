/* readline.h */
/* cpama ch15pp05, page 375 */

#ifndef READLINE_H
#define READLINE_H


/**
 * readline:  Reads a line of characters ignoring leading whitespace, storing
 *            them in *str
 *            Discards '\n' and appends '\0' to end of text.
 *            Returns the numbers of chars, i, stored in *str
 *            'n' is expected to be the size of the char array pointed to by
 *            *str
 */
int readline(char *str, int n);


#endif


