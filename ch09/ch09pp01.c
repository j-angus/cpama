/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King					 *
 *********************************************************/

/*
 * ch09pp01.c
 *
 * Write a program that asks the user to enter a series of integers (which it 
 * stores in an array), then sorts the integers by calling the function 
 * selection_sort. When given an array of n elements, selection_sort must do 
 * the following:
 *
 * 1. Search the array to find the largest element, then move it to the last 
 *	position in the array.
 *
 * 2. Call itself recursively to sort the first n-1 elements of the array.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 10 /* Max size of array */

void selection_sort(int n, int num[n]);

int main(void)
{
  int size = SIZE; /* user input */
	int number[SIZE]; /* array to store entered words */
	int i; /* array index */

	for (i = 0; i < SIZE; ++i) {
	  printf("Enter Integer: ");
	  scanf("%d", &number[i]);
	}
	
	selection_sort(size, number);
	
	printf("number[");
	for(i = 0; i < SIZE; ++i) 
	  printf("%d%s", number[i], i < (SIZE - 1) ? ", " : "]\n");
	  
	return 0;
}

void selection_sort(int n, int num[n])
{
  int high = num[0]; /* stores the highest number found in array */
  int high_index = 0; /* index of high value */
  int temp; /* for swapping numbers in the array */

  printf("DEBUG: selection_sort()\n");
  
  for(int i = 1; i < n; ++i) {
    if (high < num[i]) {
      high = num[i];
      high_index = i;
    }
  }

    if (high != num[n - 1]) {
      temp = num[n - 1];
      num[n - 1] = high;
      num[high_index] = temp;
    }
   
    if (n > 1)
      selection_sort(n - 1, num);
	
    return; 
}
