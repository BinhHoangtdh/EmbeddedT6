/*
* File: binarySearch.h
* Author: Binh Hoang
* Date: 30/06/2023
* Description: This file contains all the functions prototypes 
*              for the binary search in array.
*/

#ifndef __BINARYSEARCH_H
#define __BINARYSEARCH_H
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_ARRAY 10000

int random_number(int minN, int maxN);
uint16_t *createArray(uint16_t length);
void sort(uint16_t arr[], uint16_t length);
int binarySearch(uint16_t arr[], uint16_t length, uint16_t number);


#endif
