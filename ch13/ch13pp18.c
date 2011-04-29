/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* Write a program that accepts a date from the user in the form mm/dd/yyyy and
 * then displays it in the form month dd, yyyy.
 */
#include <stdio.h>
#include <ctype.h> /* for isspace() */

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

	printf("Enter a date (dd/mm/yyyy): ");

	scanf("%d/%d/%d", &day, &month, &year);
	if ((day < 1) || (day > 31))
		printf("Error: day out of range (1 - 31)\n");
	else if ((month < 1) || (month > 12))
		printf("Error: month out of range 91 - 12)\n");
	else
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
