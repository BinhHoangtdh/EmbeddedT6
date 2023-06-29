/*
* File: compare.h
* Author: Binh Hoang
* Date: 27/06/2023
* Description: This file contains all the functions prototypes 
*              for the comparing two strings.
*/

#ifndef __COMPARE_H
#define __COMPARE_H
#include <stdio.h>
#include <stdint.h>

typedef enum {
    BIGGER,
    SMALLER,
    EQUAL,
} compare;

compare isCompareResult(const char arr1[], const char arr2[]);

#endif
