/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* Write a program that accepts a date from the user in the form mm/dd/yyyy and
 * then displays it in the form month dd, yyyy.
 */
#include <stdio.h>
#include <ctype.h> /* for isspace() */
#include <stdbool.h>

/* defines */
#define THIS_FILE "ch13pp18.c, page 313"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);
#define MONTHS 12
/* external variables */
char *month_str[MONTHS] =
	{"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"};

/* function prototypes */
int read_line(char str[], int n);

int main(int argc, char **argv)
{	PRINT_FILE_INFO
	int day, month, year;
	bool valid_date = false;
	bool leap_year = false;

	printf("Enter a date (dd/mm/yyyy): ");

	scanf("%d/%d/%d", &day, &month, &year);

	/* check entered date values are within valid ranges */
	switch (month) {
		case 2: /* february has 28 days, 29 in a leap year */
			leap_year = ((year % 400) ?
					((year % 100) ? ((year % 4) ?
						false : true) : false) : true);
			if (!leap_year) {
				if ((day < 1) || (day > 28))
					printf("Error: day value out of range (1 - 28).\n");
				else
					valid_date = true;
			}
			else if ((day < 1) || (day > 29))
				printf("Error: day value out of range (1 - 29).\n");
			else
				valid_date = true;
			break;

		case 4: case 6: case 9: case 11:
			if ((day < 1) || (day > 30))
				printf("Error: day value out of range (1 - 30)\n");
			else
				valid_date = true;
			break;

		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if ((day < 1) || (day > 31))
				printf("Error: day value out of range (1 - 31)\n");
			else
				valid_date = true;
			break;

		default: /* month out of range */
			printf("Error: month value out of range (1 -12)\n");
			break;
	}

	if (valid_date)
		printf("%s %02d, %04d\n", month_str[month-1], day, year);

	return 0;
}

/* function definitions */

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		/* skip leading whitespace */
		if (i == 0) {
			if (isspace(ch))
				continue;
		}
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}
