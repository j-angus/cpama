/**
 * my_functions.c
 * A compilation of handy non-standard functions
 */

#include "my_functions.h"

int read_line(char str[], int n)
{
	int ch, i = 0;
/*
	if (strlen(str) == n)
		good_str;
	else
		bad_str -> abort function
*/
	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		if (i < n-1) { /* we want to store at max n-1 chars into str[] */
			str[i++] = ch;
		}
		else
			break;
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}
