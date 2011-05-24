/* ch16ex05.c */

#include <stdio.h>

struct time {
	int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main (void)
{
	/* this year - 1970 * 60 * 60 * 24 * 365 */
	/* this is obviously rough, not taking into account leap years, etc. */
	long time_in_seconds = ((2011 - 1970) * 60 * 60 * 24 * 365 + 72);
	struct time my_time = split_time(time_in_seconds);

	printf("my_time.hours: %d\n", my_time.hours);
	printf("my_time.minutes: %d\n", my_time.minutes);
	printf("my_time.seconds: %d\n", my_time.seconds);

	return 0;
}

struct time split_time(long total_seconds)
{
	struct time t;

	t.hours = total_seconds / (60 * 60);
	total_seconds %= (60 * 60);
	t.minutes = total_seconds / 60;
	t.seconds = total_seconds % 60;
	return t;
}

