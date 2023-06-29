#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"


int main()
{
    char array[] = "Du bao thoi tiet hom nay Da Nang troi nang nong cuc bo .";
    printf("CHUOI BAN DAU LA:\n");
    printf("%s\n",array);
    printf("CHUOI SAU KHI DAO NGUOC LA:\n");
    int length = 0;
    length = length_Array(array);

    while(length != 0){
    length = length - separate_Word(array, length);
    }

    return 0;
}
