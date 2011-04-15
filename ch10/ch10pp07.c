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
 * 		 4|3_| 2
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define MAX_SEGMENTS 7
#define ROWS 3

/* external variables */
int digit[MAX_DIGITS]; /* user supplied numbers to display */
const int segments[MAX_DIGITS][MAX_SEGMENTS] =
{
	{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {0,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1}, {1,1,1,0,0,1,1}
};

char digits[ROWS][MAX_DIGITS * 4];

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

	clear_digit_array();

	/* get user input */
	printf("Enter a number : ");
	while ((ch = getchar()) != '\n' && num < MAX_DIGITS) {
		if (char_digit_tostr(ch, digit_str)) {
			digit[num] = atoi(digit_str);
			++num;
		}
	}
	/* place numbers into array in seven segment format */
	for (int i = 0; i < num; ++i)
		process_digit(digit[i], i);

	print_digit_array();

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

/* fill digit array with space: ' ' */
void clear_digit_array(void)
{
	for (int i = 0; i < MAX_DIGITS; ++i)
		for (int j = 0; j < MAX_DIGITS * 4; ++j)
			digits[i][j] = ' ';

}

/* digit is an index into segments[],
 * position is an offset into digits[ROWS][position * 4]
 */
void process_digit(int digit, int position)
{
	int offset = position * 4; /* computed offset into digits[][] column */

	for (int i = 0; i < ROWS; ++i) {
		switch (i) {
			case 0:
				if (segments[digit][0])
					digits[i][offset + 1] = '_';
				break;
			case 1:
				if (segments[digit][5])
					digits[i][offset]     = '|';
				if (segments[digit][6])
					digits[i][offset + 1] = '_';
				if (segments[digit][1])
					digits[i][offset + 2] = '|';
				break;
			case 2:
				if (segments[digit][4])
					digits[i][offset]     = '|';
				if (segments[digit][3])
					digits[i][offset + 1] = '_';
				if (segments[digit][2])
					digits[i][offset + 2] = '|';
				break;
		}
	}

}

void print_digit_array(void)
{
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < MAX_DIGITS * 4; ++j)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}
