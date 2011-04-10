/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 *********************************************************/

/* derived from sum2.c (Chapter 7, page 131) */
/* Sums a series of numbers (using double variables) */

/* 
 * ch07ex03.c
 * loops. 
 */

#include <stdio.h>

int main(void)
{
  double n, sum = 0;

  printf("This program sums a series of doubles.\n");
  printf("Enter doubles (0 to terminate): ");

  scanf("%lf", &n);
  while (n != 0) {
    sum += n;
    scanf("%lf", &n);
  }
  printf("The sum is: %.3lf\n", sum);

  return 0;
}
