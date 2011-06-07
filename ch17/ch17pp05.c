/* ch17pp05.c */
/* Write a program that sorts a series of words entered by the user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD_LEN 20 /* word length */
#define MAX_WORD 20 /* number of words to store in array */

int compare(const void *s1, const void *s2);
int read_line(char str[], int n);

int main(void)
{
	int i, j;
	char *temp_str; /* temporarily store user entered string */
	char word[WORD_LEN+1]; /* store user entered word */
	char *w_array[MAX_WORD];

	for (i =0; i < MAX_WORD; ++i) {
		printf("Enter word: ");
		if (read_line(word, sizeof(word))) {
			/* store word in dynamic string */
			temp_str = malloc(strlen(word)+1);
			strcpy(temp_str, word);
			/* add string to array */
			w_array[i] = temp_str;
		} else {
			break;
		}
	}

	/* sort array of user entered words */
	/* qsort does not work with an array of pointers
	 */
	qsort(w_array, i, sizeof(w_array[0]), compare);

	/* print sorted array */
	printf("In sorted order: ");
	for (j = 0; j < i; ++j)
		printf("%s%c", w_array[j], j < (i - 1) ? ' ' : '\0');

	/* free array of allocated pointers to strings */
	for (j = 0; j < i; ++j) {
		/*
		printf("w_array[%d] address: %p\n", j, w_array[j]);
		*/
		free(w_array[j]);
		/*
		printf("w_array[%d]: %s\n", j, w_array[j]);
		*/
	}

	 return 0;
}

int compare(const void *s1, const void *s2)
{
	/*
	printf("s1: %p, s2: %p\n", *(const char **)s1, *(const char **)s2);
	*/
	return strcmp(*(const char **)s1, *(const char **)s2);
}

int read_line(char str[], int n)
{
	int ch, i = 0;

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
