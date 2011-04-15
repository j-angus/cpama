/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch10pp07.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* write a program that prompts the user for a number then displays the
 * number, using characters to simulate a 7-segment display.
 *
 * 		   0_
 * 		 5|6_| 1
 * 		 4|__| 2
 * 		   3
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGIT 10

/* external variables */
int digit[MAX_DIGIT]; /* user supplied numbers to display */
const char segment_parts[7] = {'_', '|', '|', '_', '|', '|', '_'};
/*
	{" __ ", "    ", " __ ", " __ ", "    ", " __ ", "    ", " __ ", " __ ", " __ "},
	{"|  |", "   |", " __|", " __|", "|__|", "|__ ", "|__ ", "   |", "|__|", "|__|"},
	{"|__|", "   |", "|__ ", " __|", "   |", " __|", "|__|", "   |", "|__|", "   |"}
};
*/
const int segments[MAX_DIGIT][7] =
{
	{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {0,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1}, {1,1,1,0,0,1,1}
};

/* function prototypes */
/* converts a single int digit char to a string */
bool char_digit_tostr (int ch, char digit_str[]);
void clear_digit_array(void);
void process_digit(int digit, int position);
void print_digit_array(void);

/********************************************************
 * main: Read a number input from the user.
 * 	calls: clear_digit_array(), process_digit(),
 * 		print_digit_array()
 ********************************************************/
int main(void)
{
	int num = 0; /* loop counter, array index to digit[] */
	int ch; /* user input */
	char digit_str[2]; /* holds user digits converted from char to str */
	PRINT_FILE_INFO


	/* get user input */
	printf("Enter a number : ");
	while ((ch = getchar()) != '\n' && num < MAX_DIGIT) {
		if (char_digit_tostr(ch, digit_str)) {
			digit[num] = atoi(digit_str);
			++num;
		}
	}

	for (int i = 0; i < num; ++i)
		for (int j = 0; j < 7; ++j)
			printf("%d%s",  segments[i][j],
					j == (7 - 1) ? "\n" : "");


	/* first row segments */
	for (int i = 0; i < num; ++i) {
		printf(" %c ", segments[digit[i]][0] ? segment_parts[06] : ' ');
		printf(" ");
	}
	printf("\n");
	/* second row segments */
	for (int i = 0; i < num; ++i) {
		printf("%c", segments[digit[i]][5] ? segment_parts[5] : ' ');
		printf("%c", segments[digit[i]][6] ? segment_parts[6] : ' ');
		printf("%c", segments[digit[i]][1] ? segment_parts[1] : ' ');
		printf(" ");
	}
	printf("\n");
	/* third row segments */
	for (int i = 0; i < num; ++i) {
		printf("%c", segments[digit[i]][4] ? segment_parts[4] : ' ');
		printf("%c", segments[digit[i]][3] ? segment_parts[3] : ' ');
		printf("%c", segments[digit[i]][2] ? segment_parts[2] : ' ');
		printf(" ");
	}
	printf("\n");
	return 0;
}

/* convert a single int digit char to a string */
bool char_digit_tostr (int ch, char digit_str[])
{
	bool is_digit = false;
	if (isdigit(ch)) {
		digit_str[0] = ch;
		digit_str[1] = '\0';
		is_digit = true;
	}

	return is_digit;
}
