#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "binarySearch.h"


int main(int argc, char const *argv[])
{
    uint16_t *array = createArray(SIZE_ARRAY);

    sort(array,SIZE_ARRAY);

    for (uint16_t i = 0; i < SIZE_ARRAY; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
   
    binarySearch(array, SIZE_ARRAY, 10);
    free(array);
    return 0;
}
