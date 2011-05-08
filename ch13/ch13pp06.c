/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition
 * By K. N. King
 *********************************************************/
#define THIS_FILE "ch13pp06c, page 312"
#define PRINT_FILE_INFO \
	printf("C Programming, A Modern Approach: %s\n", THIS_FILE);

/**
 * Improve planet.c (section 13.7) by having it ignore case when comparing
 * command-line arguments with strings in the 'planets' array.
 */
/* based on planet.c (Chapter 13, page 304) */
/* Checks planet names */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <string.h>
#include <ctype.h> /* for tolower() function */

/* defines */
#define NUM_PLANETS 9

/* external variables */

/* function prototypes */
int strcmp_nocase(const char *s1, const char *s2);

/* main() */
/********************************************************
 * main:
 ********************************************************/
int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (strcmp_nocase(argv[i], planets[j]) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

/* function definitions */

/**
 * compares two strings, as per strcmp, but ignores case
 * returns the lexicographical difference between first un-matched chars
 * this is zero if the strings are equal.
 */
int strcmp_nocase(const char *s1, const char *s2)
{
	/* compare each char element of s1 and s2 until one of them is not
	 * equal, or we hit the end of string (\0)
	 */
	while (*s1 && *s2) {
		if (tolower(*s1) != tolower(*s2))
			break;
		else
			++s1, ++s2;
	}
	return *s1 - *s2;
}
