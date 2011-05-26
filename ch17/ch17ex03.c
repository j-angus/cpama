/* ch17ex03.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"

int *create_array(int n, int initial_value);

int main (void)
{
	char input[MAX_LEN+1];
	int size = 0, init_val = 0;
	int *dyn_array;

	printf("Enter size of array: ");
	read_line(input, sizeof input);
	size = atoi(input);

	printf("Enter initial value of array elements: ");
	read_line(input, sizeof input);
	init_val = atoi(input);

	dyn_array = create_array(size, init_val);

	if (dyn_array) {
		for (int i = 0; i < size; ++i)
			printf("dyn_array[%d]: %d\n", i, dyn_array[i]);
		free(dyn_array);
	}
	else
		printf("ERROR: Unable to create dynamic array.\n");

	return 0;
}

int *create_array(int n, int initial_value)
{
	int *array = malloc(n * sizeof(int));
	if (array != NULL)
		for (int i = 0; i < n; ++i)
			array[i] = initial_value;

	return array;
}
