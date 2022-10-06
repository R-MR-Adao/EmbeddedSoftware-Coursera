/******************************************************************************
 * Copyright (C) 2022 by Ricardo Adao
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ricardo Adao is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data manipulation operations
 *
 * This header file provides an abstraction of data manipulation operations 
 *
 * @author Ricardo Adao
 * @date 2022-10-06
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Convert from integer to ASCI
 *
 * Integer-to-ASCII: convert data from a standard integer type into an ASCII
 * string
 *
 * @param data Number to convert
 * @param ptr Pointer to destination where converted value should be assigned
 * @param base (2 or 16) base you wish to convert to
 *
 * @return len Length of the converted data including negative sign
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert from ASCI to integer
 *
 * ASCII-to-integer: convert data from an ASCII string to standard integer type
 *
 * @param ptr Pointer to source string location
 * @param digits number of digits in character set passed in as uint8_t integer
 * @param base (2 or 16) base you wish to convert to
 *
 * @return data Converted data
 */
 int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
