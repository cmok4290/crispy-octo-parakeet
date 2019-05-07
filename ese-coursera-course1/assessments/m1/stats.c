/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <stats.c>
 * @brief <Implementation file for analytics>
 *
 * <Report analytics on the maximum, minimum, mean, and median>
 *
 * @author <Chheany <Mok>
 * @date <04/29/19>
 *
 */



#include <stdio.h>
#include "stats.h"
#include <math.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int max, min, mean, med, sum;

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  print_statistics(test, SIZE);
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */
unsigned int print_array(unsigned char * ptr, int count) {
  int i;

  printf("Array\n");
  printf("[");
  for (i = 0; i < count; i++) {
    printf("%d", ptr[i]);
    if ( i != (count - 1)) {
      printf(", ");
    }
  }
  printf("]\n\n");
}

unsigned int print_statistics(unsigned char * ptr, int count) {
  int i, maximum, minimum, mean, median;
  unsigned char sorted_array[count];

  printf("Statistics\n");
  sort_array(ptr, 0, count-1);

  maximum = find_maximum(ptr, count);
  printf("maximum: %d\n", maximum);

  minimum = find_minimum(ptr, count);
  printf("minimum: %d\n", minimum);

  mean = find_mean(ptr, count);
  printf("mean: %d\n", mean);

  median = find_median(ptr, count);
  printf("median: %d\n", median);
  printf("\n");

  return 0;
}

// helper function to swap two elements
void swap(unsigned char * a, unsigned char * b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// this function takes last element as pivot, places smaller values
// to the right of the pivot and larger values to the left of pivot
int partition(unsigned char * ptr, int low, int high) {
  int pivot = ptr[high];  // pivot
  int i = (low - 1);  // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // check if current element is greater than
    // or equal to pivot
    if (ptr[j] >= pivot) {
      i++; // increment index of smaller element
      swap(&ptr[i], &ptr[j]);
    }
  }
  swap(&ptr[i + 1], &ptr[high]);
  return (i + 1);
}

// this function implements quicksort
void sort_array(unsigned char * ptr, int low, int high) {
  if (low < high) {
    // init partition index
    int pi = partition(ptr, low, high);
    // sort elements before and after partition
    sort_array(ptr, low, pi - 1);
    sort_array(ptr, pi + 1, high);
  }
}

unsigned int find_maximum(unsigned char * ptr, int count) {
  int i;
  int max = ptr[0];
  /*
  for (i = 0; i < count; i++) {
    if (ptr[i] > max) {
      max = ptr[i];
    }
  }
  */
  return max;
}

unsigned int find_minimum(unsigned char * ptr, int count) {
  int i;
  int min = ptr[count-1];
  /*
  for (i = 0; i < count; i++) {
    if (ptr[i] < min) {
      min = ptr[i];
    }
  }
  */
  return min;
}

unsigned int find_mean(unsigned char * ptr, int count) {
  int i;
  int total = 0;

  for (i = 0; i < count; i++) {
    total += ptr[i];
  }

  return total / count;
}

unsigned int find_median(unsigned char * ptr, int count) {
  int i;
  int med = (int) floor(count/2);
  return ptr[med];
}
