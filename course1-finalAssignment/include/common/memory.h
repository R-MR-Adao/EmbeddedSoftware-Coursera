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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move source location to new memory address
 *
 * This function takes two byte pointers (one source and one destination) and
 * a length of bytes to move from the source location to the destination.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Length of bytes to move from the source to destination
 *
 * @return dst Pointer to destination location
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy data from source location to new memory address
 *
 * This function takes two byte pointers (one source and one destination) and
*  a length of bytes to copy from the source location to the destination.
 *
 * @param src Pointer to source memory location
 * @param dst Pointer to destination memory location
 * @param length Length of bytes to copy from the source to destination
 *
 * @return dst Pointer to destination location
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set all memory bytes to a given input value
 *
 * This functon takes a pointer to a source memory location, a length in bytes
 * and sets all locations of that memory to a given value.
 *
 * @param src Pointer to source memory location
 * @param length Length of bytes to modify the source to destination
 * @param value Value to be assigned
 *
 * @return src Pointer to source location
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Set all memory bytes to zero
 *
 * This function takes a pointer to a source memory location, a length in bytes
 * and sets all locations of that memory to zero.
 *
 * @param src Pointer to source memory location
 * @param length Length of bytes to modify from the source to destination
 *
 * @return src Pointer to source location
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the orther of bytes in a given memory location
 *
 * This function takes a pointer to a memory location and a length in bytes and
 * reverses the order of all of the bytes.
 *
 * @param src Pointer to source memory location
 * @param length Length of bytes to modify from the source to destination
 *
 * @return src Pointer to source location
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocate memory on the heap for new words
 *
 * This function takes a number of words to allocate in dynamic memory.
 *
 * @param length Length of bytes to modify from the source to destination
 *
 * @return src Pointer to source location
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free memory from the heap
 *
 * This function frees a dynamic memory allocation on a given memory location
 *
 * @param length Length of bytes to modify from the source to destination
 *
 * @return src Pointer to source location
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
