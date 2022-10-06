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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print array statistics
 *
 * A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 */
void print_statistics(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Print array data
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 */
void print_array(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Find array median
 *
 * Given an array of data and a length, returns the median value.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 *
 * @return median the median of the array.
 */
uint8_t find_median(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Find array mean
 *
 * Given an array of data and a length, returns the mean value.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 *
 * @return mean the mean of the array.
 */
uint8_t find_mean(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Find array maximum
 *
 * Given an array of data and a length, returns the maximum value.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 *
 * @return max the maximum of the array.
 */
uint8_t find_maximum(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Find array minimum
 *
 * Given an array of data and a length, returns the minimum value.
 *
 * @param[in] arr the input array.
 * @param[in] arr_size the size of the array.
 *
 * @return min the minimum of the array.
 */
uint8_t find_minimum(uint8_t * arr, uint8_t arr_size);

/**
 * @brief Descending sort array
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 *
 * @param[in/out] arr the array to be sorted.
 * @param[in] arr_size the size of the array.
 */
void sort_array(uint8_t * arr, uint8_t arr_size);


#endif /* __STATS_H__ */
