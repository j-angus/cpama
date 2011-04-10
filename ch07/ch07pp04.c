/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch07pp04.c
 * Write a program that translates an alphabetic phone number into into
 * numeric form.
 *
 * 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PQRS, 8=TUV, 9=WXYZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	/* int ch; /* user input */
	int p_num; /* user input */
	bool cool = true;

	printf("Enter phone number: ");

	while ((p_num = toupper(getchar())) != '\n') {
		if (p_num >= 'A' && p_num <= 'Z') {
			switch (p_num) {
				case 'A': case 'B': case 'C':
					p_num = '2';
					break;
				case 'D': case 'E': case 'F':
					p_num = '3';
					break;
				case 'G': case 'H': case 'I':
					p_num = '4';
					break;
				case 'J': case 'K': case 'L':
					p_num = '5';
					break;
				case 'M': case 'N': case 'O':
					p_num = '6';
					break;
				case 'P': case 'Q': case 'R': case 'S':
					p_num = '7';
					break;
				case 'T': case 'U': case 'V':
					p_num = '8';
					break;
				case 'W': case 'X': case 'Y': case 'Z':
					p_num = '9';
					break;
			}
		}
		printf("%c", p_num);
	}

	return 0;
}
