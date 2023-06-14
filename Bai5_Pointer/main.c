#include <stdio.h>
#include <string.h>

void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d = %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich %d va %d = %d\n", a, b, a*b);
}

double thuong(int a, int b){
    return (double)a/b;
}

void toanHoc(void (*ptr)(int, int), int a, int b){
    printf("Chuong trinh tinh toan\n");
    ptr(a,b);
}

int main(int argc, char const *argv[]){

    //void (*ptr)(int, int);
    //void *ptr = &tong;
    // ((void (*)(int, int))ptr)(4,7);
    // ptr(7,4);
    // ptr = &hieu;
    // ptr(7,4);
    // ptr = &tich;
    // ptr(7,4);

    // double (*ptrD)(int, int) =&thuong;
    // printf("thuong: %f\n",ptrD(1,2));
    double d= 10.3;
    char string[] = "Hello world!";
    void *array[] = {&toanHoc, &d, string};

    // IN RA toanhoc Tong
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tong,4,7);
    
    // IN RA toanhoc Hieu
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&hieu,7,4);
    
    // IN RA toanhoc tich
    ((void (*)(void (*ptr)(int, int),int, int))array[0])(&tich,7,4);
    
    // IN RA toanhoc Thuong
    printf("Phep thuong: %f\n",((double (*)(double (*ptr)(int, int),int, int))array[0])(&thuong,7,4));

    // IN RA d
    printf("Gia tri cua d la: %f\n", *(double*)array[1]);
    
    // IN RA string
    printf("Gia tri cua string la: %s\n", (char*)array[2]);

    return 0;
}