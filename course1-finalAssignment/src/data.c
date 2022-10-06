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
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);