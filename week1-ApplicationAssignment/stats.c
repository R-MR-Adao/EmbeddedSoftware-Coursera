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
 * @file stats.c
 * @brief Perform some basic statiscs analysis on a simple dataset
 *
 *  - main() - The main entry point for your program
 *  - print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *  - print_array()   - Given an array of data and a length, prints the array to the screen
 *  - find_median()   - Given an array of data and a length, returns the median value
 *  - find_mean()     - Given an array of data and a length, returns the mean
 *  - find_maximum()  - Given an array of data and a length, returns the maximum
 *  - find_minimum()  - Given an array of data and a length, returns the minimum
 *  - sort_array()    - Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @author Ricardo Adao
 * @date 2022-09-22
 *
 */



#include <stdio.h>
#include <stdint.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


void main() {

  uint8_t test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */

void print_statistics(uint8_t * arr, uint8_t arr_size);

void print_array(uint8_t * arr, uint8_t arr_size);

uint8_t find_median(uint8_t * arr, uint8_t arr_size);

uint8_t find_mean(uint8_t * arr, uint8_t arr_size);

uint8_t find_maximum(uint8_t * arr, uint8_t arr_size);

uint8_t find_minimum(uint8_t * arr, uint8_t arr_size);

uint8_t sort_array(uint8_t * arr, uint8_t arr_size);
