/* ch17ex12.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"
#include "../lib/stack.h"

void read_numbers(void);
void print_list(struct node *list);
int count_occurrences(struct node *list, int n);
struct node *find_last(struct node *list, int n);


int main (void)
{
	int num = 5;

	read_numbers();
	print_list(top);
	printf("%d found at: %p\n", num, (void *)find_last(top, num));

	return 0;
}

void print_list(struct node *list)
{
	if (list == NULL) {
		printf("Empty list.\n");
		return;
	}

	for (; list != NULL; list = list->next) {
		printf("list address: %p\n", (void *)list);
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
	return;
}

int count_occurrences(struct node *list, int n)
{
	int found = 0;
	for (; list != NULL; list = list->next)
		if (list->value == n)
			++found;
	return found;
}

struct node *find_last(struct node *list, int n)
{
	struct node *last = NULL;

	for (; list != NULL; list = list->next)
		if (list->value == n)
			last = list;
	return last;

}
