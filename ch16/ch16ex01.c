/* ch16ex01.c */

#include <stdio.h>


void main (void)
{
	struct { int x, y; } y;
	struct { int x, y; } x;
	
	printf("struct x.x: %d, x.y: %d\n", x.x, x.y);
	printf("struct y.x: %d, y.y: %d\n", y.x, y.y);

	return;
}
