/*
* File: reverse.c
* Author: Binh Hoang
* Date: 29/06/2023
* Description: This is a file writed to reverse string
*/

#include "reverse.h"


/*
* Function: length_Array
* Description: This function is used to calculate the length of string
* Input:
*   const char array[] - constant string need to calculate of length
* Output:
*   returns the length of string.
*/
int length_Array(const char array[]){
    int length_arr = 0;
    int i = 0;
    while(array[i] != '\0'){
        i++;
        length_arr++;
    }
    return length_arr;
}

/*
* Function: separation_Word
* Description: This function is used to to reverse string
* Input:
*   const char array[] - constant string need to separate
*   int length - the length of string
* Output:
*   returns the length of word needed separate.
*/
int separate_Word(char array[], int length){

    char *ptr = NULL;
    int i = length - 1;
    int length_Word =0;

    while((array[i] != ' ') && (i>=0)){
            i--;
            length_Word++;
        }

    ptr = &array[i+1];

    for(int j=0; j<length_Word;j++)
    {
        printf("%c", ptr[j]);
    }
    ptr[length_Word]=' ';
    printf("%c", ptr[length_Word]);
    return (length_Word+1);
}