#include <stdio.h>

volatile int data_ADC; //khai bao bien volatile
extern int dem;         // Dung extern de truy cap mot BIEN o FILE KHAC (cu the o day la file test.c)
extern void display();  // Dung extern de truy cap mot HAM o FILE KHAC (cu the o day la file test.c)
static int y = 10; // y la bien static trong khai bao bien toan cuc

void Count(){

    static int x =0; // x la bien static trong khai bao bien cuc bo
    x++;
    printf("x= %d\n",x);
}

int main(int argc, char const *argv[]) {
    Count();
    Count();
    Count();
    display();
    dem =10;
    printf("dem= %d\n",dem);
}