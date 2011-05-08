/**
 * my_functions.c
 * A compilation of handy non-standard functions
 */

/**
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
