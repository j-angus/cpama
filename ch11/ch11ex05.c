/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

#define THIS_FILE "ch11ex04.c"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/* Write the folowing function:
 * void split_time(long local_sec, int *hr, int *min, int *sec);
 * total_sec is a time represented as the number of seconds since midnight.
 * hr, min, and sec are pointers to variables in which the function will store
 * the equivalent time in hours (0-23), minutes (0-59), and seconds (0-60).
 */

#include <stdbool.h>	 /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* defines */
#define HR_TO_SEC 3600
#define MIN_TO_SEC 60

/* external variables */

/* function prototypes */
long seconds_since_midnight(void);
void split_time(long local_sec, int *hr, int *min, int *sec);

/* main() */
/********************************************************
 * main: implement split_time() function
 ********************************************************/
int main(void)
{

	PRINT_FILE_INFO
	long midnight_seconds = seconds_since_midnight();
	printf("Seconds since midnight: %ld\n", midnight_seconds);
	int hour, min, sec;

	split_time(midnight_seconds, &hour, &min, &sec);

	printf("Time since midnight...\n");
	printf("%02d:%02d:%02d\n", hour, min, sec);

	return 0;
}

/* function definitions */

/**
 * Return the number of seconds since midnight.
 */
long seconds_since_midnight(void)
{
	long seconds = 0; /* stores the number of seconds since midnight */

	time_t current = time(NULL); /* get the current time */
	struct tm *time_ptr = localtime(&current);

	seconds += (time_ptr->tm_hour * 3600);
	seconds += (time_ptr->tm_min * 60);
	seconds += (time_ptr->tm_sec);

	return seconds;
}


void split_time(long local_sec, int *hr, int *min, int *sec)
{
	*hr = local_sec / HR_TO_SEC;
	local_sec %= HR_TO_SEC;
	*min = local_sec / MIN_TO_SEC;
	local_sec %= MIN_TO_SEC;
	*sec = local_sec;

	return;
}
