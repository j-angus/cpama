/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex07.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the folowing function:
 * void split_date(int day_of_year, int year, int *month, int *day);
 * day_of_year is an integer between 1 and 366, specifying a particular day
 * within the year. month and day point to variables in which the function will
 * store the equivalent month (1-12) and day within the month (1-31).
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define EPOCH 1900	/* the beginning of struct tm.tm_year time */

/* external variables */

/* function prototypes */
void get_year_day(int *year, int *day_of_year);
void split_date(int day_of_year, int year, int *month, int *day);

/* main() */
/********************************************************
 * main: implement split_date() function
 ********************************************************/
int main(void)
{

	PRINT_FILE_INFO

	int year, day_of_year;
	int month, day;

	get_year_day(&year, &day_of_year);
	split_date(day_of_year, year, &month, &day);

	printf("day / month / year: %d / %d / %d\n", day, month, year);

	return 0;
}

/* function definitions */

/**
 * Get the current year and day of the year.
 */
void get_year_day(int *year, int *day_of_year)
{
	time_t current = time(NULL); /* get the current time */
	struct tm *time_ptr = localtime(&current);

	*year = time_ptr->tm_year + EPOCH;
	*day_of_year = time_ptr->tm_yday;

	return;
}

/**
 * Calculate current month and day of month from given year and day of year.
 */
void split_date(int day_of_year, int year, int *month, int *day)
{
	int hour_of_year = day_of_year * 24;
	struct tm t;
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = hour_of_year;
	t.tm_mday = 1;
	t.tm_mon = 0;
	t.tm_year = year - EPOCH;
	t.tm_isdst = -1;

	mktime(&t);

	*month = t.tm_mon + 1;
	*day = t.tm_mday;

	return;
}
