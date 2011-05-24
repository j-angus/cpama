/* ch16ex05.c */

#include <stdio.h>

struct date {
	int year, month, day;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main (void)
{
	struct date d1 = {1972, 3, 16}, d2 = {1972, 3, 16};

	printf("d1.day: %d\n", day_of_year(d1));

	printf("compare_dates(d1, d2): %d\n", compare_dates(d1, d2));

	return 0;
}

/* duh, you're sposed to return the DAY OF YEAR, not d.day, so that...*/
int day_of_year(struct date d)
{
	return d.day;
}

/* ...we can call day_of_year() to determine which date is earlier*/
int compare_dates(struct date d1, struct date d2)
{
	int comparison;

	if (d1.year < d2.year)
		comparison = -1;
	else if (d1.year == d2.year) {
		if (d1.month < d2.month)
			comparison = -1;
		else if (d1.month == d2.month) {
			if (d1.day < d2.day)
				comparison = -1;
			else if (d1.day == d2.day)
				comparison = 0;
			else /* d1.day > d2.day */
				comparison = 1;
		}
		else /* d1.month > d2.month */
			comparison = 1;
	}
	else /* d1.year > d2.year */
		comparison = 1;

	return comparison;
}
