/**
 * file: rev_digits.c
 * gcc -Wall -o rev_digits rev_digits.c
 * 
 * Displays reversed digits entered by the user.
 *  
 */


#include <stdio.h>

/**
 * Reverses a two digit integer. 
 */
int rev_int(int num)
{
	return (num % 10) * 10 + (num / 10);
}

int main (int argc, char **argv)
{
	int num; /* the number entered by the user */
	
	printf("Please enter a positive two digit number: ");
	scanf("%d", &num);
	printf("You entered: %d\n", num);
	
	if (num < 10) {
		printf("That was a crap number!\n");
		printf("You're supposed to enter a positive two digit "
			"number dude.\n");
	}
	else
		printf("Digits reversed: %02d\n", rev_int(num));
	
	int i, j, k;
	i = j = k = 1;
	i += j += k;
	printf("i: %d, j: %d, k: %d\n", i, j, k);
	i = 1; j = 2; k = 3;
	i -= j -= k;
	printf("i: %d, j: %d, k: %d\n", i, j, k);
	i = 2; j = 1; k = 0;
	i *= j *= k;
	printf("i: %d, j: %d, k: %d\n", i, j, k);
	i = 7;
	j = 6 + (i = 2.5);
	printf("i: %d, j: %d\n", i, j);
	i = 2; j = 8;
	j = (i = 6) + (j = 3);
	printf("i: %d, j: %d\n", i, j);
	i = 1;
	printf("i: %d\n", i++ -1);
	printf("i: %d\n", i);
	i = 10; j = 5;
	printf("%d\n", i++ - ++j);
	printf("i: %d, j: %d\n", i, j);
	return 0;
}
