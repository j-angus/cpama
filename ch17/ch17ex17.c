/* ch17ex17.c */

#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int g(int x);

int main (void)
{
	int i = 1, j = 10;

	printf("Sum of range %d - %d\n", i, j);
	sum(g, i, j)
	;
	return 0;
}

int sum(int (*f)(int), int start, int end)
{
	int total = 0;

	for (; start <= end; ++start) {
		printf("total = %d + %d\n", total, g(start));
		total += g(start);
		printf("total = %d\n", total);
	}
	return total;
}

int g(int x)
{
	return x;
}
