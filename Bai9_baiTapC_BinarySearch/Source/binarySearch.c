/*
* File: binarySearch.h
* Author: Binh Hoang
* Date: 30/06/2023
* Description: This is a file writed for binary search in array
*/

#include "binarySearch.h"

/*
* Function: random_number
* Description: This function is used to create a random number
* Input:
*   int minN, int maxN : A lower and upper limit
* Output:
*   returns a random number in the range minN - maxN.
*/
int random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

/*
* Function: createArray
* Description: This function is used to create a array
* Input:
*   uint16_t length: The length of array
* Output:
*   returns a pointer that contain the array address .
*/
uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 10000);
    }
    return ptr; 
}

/*
* Function: sort
* Description: This function is used to sort elements of array
* Input:
*   uint16_t arr[] - Array need to be sorted
*   uint16_t length - The length of array
* Output:
*   returns the Array is sorted
*/
void sort(uint16_t arr[], uint16_t length){

    for (uint16_t i = length - 1; i > 0; i--){
        for(uint16_t j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                uint16_t temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
* Function: binarySearch
* Description: This function is used to binary search the element position in array
* Input:
*   uint16_t arr[] - Array need to be sorted
*   uint16_t length - The length of array
*   uint16_t number - Number need to find position in array
* Output:
*   returns the position of "number".
*/
uint16_t binarySearch(uint16_t arr[], uint16_t length, uint16_t number){

    uint16_t left_pos = 0;
    uint16_t right_pos = length - 1;

    while(left_pos <= right_pos){
        uint16_t middle_pos = (left_pos + right_pos)/2;
        if( arr[middle_pos] == number){
            return middle_pos;
        }
        else if( arr[middle_pos] > number){
            right_pos = middle_pos - 1;
        }
        else left_pos = middle_pos + 1;
    }

    
    return -1 ;

}
