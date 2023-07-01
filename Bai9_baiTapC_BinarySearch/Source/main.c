#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binarySearch.h"


int main(int argc, char const *argv[])
{
    
    uint16_t number;
    uint16_t SIZE_ARRAY;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &SIZE_ARRAY);
    uint16_t *array = createArray(SIZE_ARRAY);

    sort(array,SIZE_ARRAY);

    for (uint16_t i = 0; i < SIZE_ARRAY; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    printf("Nhap gia tri can tim: ");
    scanf("%d", &number);
    int result = binarySearch(array, SIZE_ARRAY, number);
    if(result == -1)
        printf("So %d can tim khong ton tai!\n", number);
    else
        printf("So %d can tim o vi tri: %d\n",number, result);
    free(array);
    return 0;
}
