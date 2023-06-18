#include <stdio.h>
#include <string.h>
#include <stdint.h>

// khai bao kieu STRUCT
typedef struct
{
    uint8_t var1;
    uint16_t var2;
    uint32_t var3;
}StructData;

//khai bao kieu UNION
typedef union
{
    uint8_t var1;
    uint16_t var2;
    uint32_t var3;
}UnionData;

// kieu union co long struct thuong dung de truyen du lieu giua 2 MCU

typedef union
{
    struct
    {
        uint8_t Id[2];
        uint8_t Data[3];
        uint8_t CS[1];
    }data;
    uint8_t array[6];
}DataFrame;


int main(int argc, char const *argv[]){

    StructData data1;
    UnionData data2;

    // Kiem tra dia chi cua bien kieu STRUCT
    printf("Kiem tra dia chi tung member kieu STRUCT\n");
    printf("dia chi %p\n", &data1);
    printf("dia chi %p\n", &data1.var1);
    printf("dia chi %p\n", &data1.var2);
    printf("dia chi %p\n", &data1.var3);

    // Kiem tra dia chi cua bien kieu UNION
    printf("Kiem tra dia chi tung member kieu UNION\n");
    printf("dia chi %p\n", &data2);
    printf("dia chi %p\n", &data2.var1);
    printf("dia chi %p\n", &data2.var2);
    printf("dia chi %p\n", &data2.var3);

    DataFrame dataframe ;

    dataframe.data.Id[0]= 0x01;
    dataframe.data.Id[1]= 0x02;
    
    dataframe.data.Data[0]= 0xC1;
    dataframe.data.Data[1]= 0xC2;
    dataframe.data.Data[2]= 0xC3;

    dataframe.data.CS[0]= 0xC8;

    return 0;
}