#include <stdio.h>

#define DEBUG

#include "debug.h"

int main(void)
{
	int i = 1, j = 2, k = 3;
#ifdef DEBUG
	printf("Output if DEBUG is defined:\n");
#else
	printf("Output if DEBUG is not defined:\n");
#endif
	PRINT_DEBUG(i);
	PRINT_DEBUG(j);
	PRINT_DEBUG(k);
	PRINT_DEBUG(i + j);
	PRINT_DEBUG(2 * i + j - k);

	return 0;
}
