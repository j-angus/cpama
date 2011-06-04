/* ch17ex14.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"
#include "../lib/stack.h"

void read_numbers(void);
void print_list(struct node *list);
int count_occurrences(struct node *list, int n);
struct node *find_last(struct node *list, int n);
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);
struct node *delete_from_list(struct node *list, int n);

int main (void)
{
	int num = 5;
	struct node *my_node = malloc(sizeof(struct node));
	my_node->value = num;
	my_node->next = NULL;

	read_numbers();
	printf("my_node add: %p\n", (void *)my_node);
	print_list(top);
	top = insert_into_ordered_list(top, my_node);
	print_list(top);
	print_list(find_last(top, 2));
	print_list(delete_from_list(top, num));

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

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
	struct node *cur = list, *prev = NULL;

	printf("DEBUG: insert_into_ordered_list()\n");

	for (; cur != NULL && (cur->value <= new_node->value);
						prev = cur, cur = cur->next)
		;

	printf("DEBUG: insert_into_ordered_list(), finished while()\n");

	if (prev == NULL) { /* value smaller than first node value */
		new_node->next = list;
		list = new_node;
		} else { /* standard insert */
			prev->next = new_node;
			new_node->next = cur;
	}
	return list;
}

struct node *delete_from_list(struct node *list, int n)
{
	struct node *cur, *prev;

	for (cur = list, prev = NULL;
		cur != NULL && cur->value != n;
		prev = cur, cur = cur->next)
		;

	if (cur == NULL)
		return list; /* n was not found */
	if ( prev == NULL)
		list = list->next; /* n is in the first node */
	else
		prev->next = cur->next; /* n is in some other node */
	free(cur);
	return list;
}
