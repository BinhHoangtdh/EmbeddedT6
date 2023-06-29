/*
* File: compare.c
* Author: Binh Hoang
* Date: 27/06/2023
* Description: This is a file writed to compare two strings
*/

#include "compare.h"

/*
* Function: compare_string
* Description: This function is used to compare two strings
* Input:
*   const char arr1[] - constant string 1
*   const char arr2[] - constant string 2
* Output:
*   returns the comparing result of two string.
*   Data type is compare (user-defined data type).
*/
compare isCompareResult(const char arr1[], const char arr2[])
{

    uint8_t i=0;
    while (arr1[i] == arr2[i])
    {
        if(arr1[i]== '\0'){
            printf("equal\n");
            return EQUAL;
        }
        i++;
    }
    if (arr1[i] > arr2[i])
    {
        printf("bigger\n");
        return BIGGER;
    }
    else{
        printf("smallerl\n");
        return SMALLER;
    }

}