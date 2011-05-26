/* ch17ex02.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"

char *duplicate(char* str);

int main (void)
{
	char str1[MAX_LEN+1], *dupstr;

	printf("Enter a string: ");
	read_line(str1, sizeof str1);

	dupstr = duplicate(str1);

	if (dupstr == NULL)
		printf("ERROR: duplicate failed to copy string.\n");
	else
		printf("dupstr: %s\n", dupstr);

	free(dupstr);

	return 0;
}

char *duplicate(char* str)
{
	char *dupstr = malloc(strlen(str) + 1);

	return dupstr == NULL ? dupstr : strcpy(dupstr, str);
}
