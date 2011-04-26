/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex17.c, page 310"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the following function:
 * bool test_extension(const char *file_name, const_char *extension);
 * Incorporate the "search for the end of a string" idiom into the function.
 */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

/* defines */
#define LINE_LEN 80

/* external variables */

/* function prototypes */
int read_line(char str[], int n);
bool test_extension(const char *file_name, const char *extension);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char file_name[] = "memo.txt";
	char extension[] = "TXT";

	printf("Is %s the file extension of %s? %s\n", extension, file_name,
			test_extension(file_name, extension) ? "Yes" : "No");
	return 0;
}

/* function definitions */

bool test_extension(const char *file_name, const char *extension)
{
	bool match = false;
	const char *e = extension;

	/* search backwards from end of file_name and extension,
	 * comparing chars. Any non-matches fails check.
	 * If no period found in file_name, search fails.
	 */
	 if (strlen(extension) < (strlen(file_name) + 1)) {
		/* Locate the end of file_name */
		while (*file_name)
			file_name++;
		/* Locate the end of extension */
		while (*e)
			e++;
		while (toupper(*file_name) == toupper(*e)) {
			if (e == extension && *(file_name - 1) == '.')
				match = true;
			--file_name, --e;
		}
	}
	return match;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0) /* skip leading whitespace */
			if (isspace(ch))
				continue;
		if (i < n) {
			str[i++] = ch;
		}
	}
	str[i] = '\0'; /* terminate string */

	return i; /* number of char stored in str[] */
}


