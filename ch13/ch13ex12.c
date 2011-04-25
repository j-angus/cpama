/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch13ex12.c, page 309"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the following funciton:
 * void get_extension(const char *file_name, char *extension);
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
void get_extension(const char *file_name, char *extension, const int n);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(void)
{	PRINT_FILE_INFO
	char fn[] = "file.txt";
	char ext[LINE_LEN+1];

	get_extension(fn, ext, LINE_LEN);

	printf("File extension of %s is: %s\n", fn, ext);

	return 0;
}

/* function definitions */

void get_extension(const char *file_name, char *extension, const int n)
{
	while (*file_name++) {
		if (*file_name == '.') {
			strncpy(extension, ++file_name, n);
			return;
		}
	}
	*extension = '\0';
	return;
}

/* a less succinct version:
void get_extension(const char *file_name, char *extension, const int n)
{
	char *tail = file_name + strlen(file_name) - 1;

	while (tail >= file_name) {
		if (*tail == '.') {
			strcpy(extension, ++tail);
			break;
		}
		if (tail == file_name)
			*extension = '\0';
		else
			tail++;
	}
	return;
}
*/

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


