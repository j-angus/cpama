/* ch17ex07.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/my_functions.h"

struct node {
	int value; /* data stored in the node. */
	struct node *next; /* pointer to the next node */
};

struct node *add_to_list(struct node *list, int n);
struct node *read_numbers(void);
struct node *delete_from_list(struct node *list, int n);
struct node * delete_list(struct node *list);
void print_list(struct node *list);

int main (void)
{
	struct node *anode = NULL;

	anode = read_numbers();
	print_list(anode);
	anode = delete_from_list(anode, 20);
	print_list(anode);
	anode = delete_list(anode);
	print_list(anode);
	return 0;
}

struct node *add_to_list(struct node *list, int n)
{
	struct node *new_node;

	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("ERROR : malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->next = list;

	return new_node;
}

void print_list(struct node *list)
{
	if (list == NULL) {
		printf("Empty list.\n");
		return;
	}

	for (; list != NULL; list = list->next) {
		printf("list->value: %d\n", list->value);
		/*
		if (list->next)
			printf("list->next->value: %d\n", list->next->value);
		*/
	}
	return;
}

struct node *read_numbers(void)
{
	struct node *first = NULL;
	int n;

	printf("Enter a series of integers ( 0 to terminate.): ");
	for(;;) {
		scanf("%d", &n);
		if (n == 0)
			return first;
		first = add_to_list(first, n );
	}
}

struct node *delete_from_list(struct node *list, int n)
{
	struct node *first = list, *found;

	if (list == NULL) {
		printf("Nothing in list.\n");
		return list;
	}

	if (list->value == n) { /* n in first node */
		printf("'%d' found in first node.\n", n);
		found = list;
		list = list->next;
		free(found);
		return list;
	}

	if (list->next) { /* have more than one node */
		printf("More than one node.\n");
		for (; list->next != NULL; list = list->next) {
			if (list->next->value == n) {
				printf("found %d.\n", list->next->value);
				found = list->next;
				list->next = list->next->next;
				free(found);
				return first;
			}
		}

	}
	/* n not found */
	printf("'%d' not found.\n", n);
	return first;
}

struct node *delete_list(struct node *list)
{
	struct node *p = list, *q;

	for (; p != NULL; p = p->next) {
		printf("Before free(), p: %p, p->next: %p\n", p, p->next);
		if (p->next)
			printf("p->value: %d, p->next->value: %d\n", p->value, p->next->value);
		printf("Freeing node p: %p\n", p);
		free(p);
		printf("After free(), p: %p, p->next: %p\n", p, p->next);
		if (p->next)
			printf("p->value: %d, p->next->value: %d\n", p->value, p->next->value);
	}
	/*
	while (p != NULL) {
		q = p;
		p = p->next;
		printf("Before free(), p: %p, q: %p\n", p, q);
		printf("Freeing node q: %p\n", q);
		free(q);
		printf("After free(), p: %p, q: %p\n", p, q);
	}
*/
	return p;
}
