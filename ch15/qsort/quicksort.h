
/* quicksort.h */
/* cpama ch15pp3, page 375 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

/**
 * quicksort: implements a quicksort algorithm on integers
 *            This is a recursive function.
 */
void quicksort(int a[], int low, int high);

/**
 * split: called by quicksort, split returns the middle element of an array
 */
int split(int a[], int low, int high);

#endif
