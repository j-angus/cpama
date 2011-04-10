/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* ch05ex08.c */
/* Simplify a complicated 'if' statement. */

#include <stdio.h>
#include <stdbool.h> /* for 'true' and 'false' */

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Exercise 8\n\n");
	
	int age;
	bool teenager;

	/* This entire 'if' statement can be replaced by a single assignment */

	age = 15;
	if (age >= 13)
		if (age <= 19)
			teenager = true;
		else
			teenager = false;
	else if (age < 13)
		teenager = false;
	printf("Age: %d. teenager: %s\n", age, teenager ? "true" : "false");
			
	age = 11;
	if (age >= 13)
		if (age <= 19)
			teenager = true;
		else
			teenager = false;
	else if (age < 13)
		teenager = false;
	printf("Age: %d. teenager: %s\n", age, teenager ? "true" : "false");

	/* simplified test for teenager: */
	age = 17;
	teenager = (age > 12 && age < 20 ? true : false);
	printf("Age: %d. teenager: %s\n", age, teenager ? "true" : "false");

	age = 11;
	teenager = (age > 12 && age < 20 ? true : false);
	printf("Age: %d. teenager: %s\n", age, teenager ? "true" : "false");

	return 0;
}
