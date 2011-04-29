/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/* from remind.c (Chapter 13, page 294)
 * Prints a one-month reminder list
 * Write the following function:
 * bool test_extension(const char *file_name, const_char *extension);
 * Incorporate the "search for the end of a string" idiom into the function.
 */
#define THIS_FILE "ch13pp02.c, page 311"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);


#include <stdio.h>
#include <string.h>
#include <ctype.h> /* for isspace() function */

#define MAX_REMIND 50	 /* maximum number of reminders */
#define MSG_LEN 60	/* max length of reminder message */
#define DAY_TIME 10	/* max length of day/time string */

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND][MSG_LEN + DAY_TIME];
	char msg_str[MSG_LEN+1];
	int day, i, j, num_remind = 0;
	int  hour = 0, minute = 0; /* reminder msg time */
	char day_time_str[DAY_TIME]; /* string to hold day and time values */

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day, 24-hr time (HHMM), and reminder: ");
		scanf("%2d", &day);
		if (day == 0)
			break;
		else if (day < 0) {
			printf("Error: Negative day entered.\n");
			continue;
		} else if (day > 31) {
			printf("Error: Day entered is larger than 31.\n");
			continue;
		}

		scanf("%2d", &hour);
		if ((hour < 0) || (hour > 23)) {
			printf("Error: Hour must be between 00 and 24.\n");
			hour = 0;
			continue;
		}

		scanf("%2d", &minute);
		if ((minute < 0) || (minute > 59)) {
			printf("Error: Minutes must be between 00 and 59.\n");
			minute = 0;
			continue;
		}
		sprintf(day_time_str, "%02d %02d%02d ", day, hour, minute);

		read_line(msg_str, MSG_LEN);

		/* sort place to store this message into array */
		for (i = 0; i < num_remind; i++)
			if (strcmp(day_time_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j-1]);

		/* store day/time header and message into array */
		strcpy(reminders[i], day_time_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay Time Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

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
