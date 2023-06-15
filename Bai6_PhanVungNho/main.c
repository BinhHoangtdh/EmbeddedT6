#include <stdio.h>

const a = 12; // text segment
int n = 10; // data segment
static int m = 15 ; // data segment
int i ; // bss segment
static int k ; // bss segment


void tong(){
    int j = 1; // stack segment
    static int i; // bss segment
}
int main(int argc, char const * argv[]){
    int cout = 0; // stack segment
    
    int *array = (int*)malloc(sizeof(int)*4); // Automatic Memory allocation 

    array = (int*)realloc(array, sizeof(int)*6); // Automatic Memory allocation, tăng vùng nhớ lên cho array
    
    for(int i = 0; i <6; i++){

        array[i] = 2*i;
    }
    for(int i = 0; i <6; i++){

        printf("%d\n", array[i]);
    }

    free(array); // Giai phong bo nho
    return 0;
}