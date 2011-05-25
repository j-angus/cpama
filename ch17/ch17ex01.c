/* ch17ex01.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"

void *my_malloc(int n);
char *concat(const char *s1, const char *s2);

int main (void)
{
	char str1[MAX_LEN+1], str2[MAX_LEN+1], *str3;

	printf("Enter string 1: ");
	read_line(str1, sizeof str1);

	printf("Enter string 2: ");
	read_line(str2, sizeof str2);

	str3 = concat(str1, str2);
	printf("concat(str1, str2): %s\n", str3);

	free(str3);

	return 0;
}

void *my_malloc(int n)
{
	void *m_block = NULL;

	if ((m_block = malloc(n)) == NULL) {
		printf("Error: malloc unable to allocate required memory\n");
		exit(EXIT_FAILURE);
	}
	return m_block;
}

char *concat(const char *s1, const char *s2)
{
	char *s3; /* = *s1 + *s2 */

	s3 = my_malloc(strlen(s1) + strlen(s2) + 1);
	strcpy(s3, s1);
	strcat(s3, s2);

	return s3;
}
