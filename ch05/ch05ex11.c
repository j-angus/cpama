/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* 
 * ch05ex11.c
 * write a switch statement to return the city matching a user entered
 * telephone area code or "Area code not recognised." for unknown codes. 
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	printf("From C PROGRAMMING: A MODERN APPROACH, 2nd Edition\n"
		"Chapter 5, Exercise 11\n\n");
	
	int area_code;
	bool found = true;
	do {
		printf("Enter three digit area code: ");
		scanf("%3d", &area_code);
	
		printf("\nArea code %d is: ", area_code);
	
		switch (area_code) {
			case 229: 
				printf("Albany.\n"); 
				break;
			case 404: case 470: case 678: case 770:
				printf("Atlanta.\n"); 
				break;
			case 478:
				printf("Macon.\n"); 
				break;
			case 706: case 762:
				printf("Columbus.\n"); 
				break;
			case 912:
				printf("Savannah.\n"); 
				break;
			default:
				printf("Area code not recognised.\n");
				found = false;
				break;
		}
	} while (found);
		
	return 0;
}
