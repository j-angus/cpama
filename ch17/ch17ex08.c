/* ch17ex08.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"
#include "../lib/stack.h"

void read_numbers(void);
void print_list(struct node *list);

int main (void)
{
	read_numbers();
	print_list(top);
	printf("pop(): %d\n", pop());
	print_list(top);
	printf("pop(): %d\n", pop());
	print_list(top);
	make_empty();
	print_list(top);
	printf("pop(): %d\n", pop());
	return 0;
}

void print_list(struct node *list)
{
	if (list == NULL) {
		printf("Empty list.\n");
		return;
	}

	for (; list != NULL; list = list->next) {
		printf("list->value: %d\n", list->value);
	}
	return;
}

void read_numbers(void)
{
	int n;

	printf("Enter a series of integers ( 0 to terminate.): ");
	for(;;) {
		scanf("%d", &n);
		if (n == 0)
			break;
		if (push(n))
			continue;
		else
			break;
	}
}
