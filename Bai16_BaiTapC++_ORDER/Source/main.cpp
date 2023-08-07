#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<conio.h>
#include<stdio.h>
#include "OrderManagement.hpp"
                    
using namespace std;


int main(int argc, char **argv){

    list<Food> database;
    vector<Table> d_table;
    int chose;

    while(true) {
        
        cout << "CHUONG TRINH GOI MON C/C++\n";
        cout << "**************************\n";
        cout << "**  1. Quan ly.         **\n";
        cout << "**  2. Nhan vien.       **\n";
        cout << "**  0. Thoat            **\n";
        cout << "**************************\n";
        cout << "Vui long chon CT:... ";fflush(stdin);
        cin >> chose;
        switch(chose)
        {
            case 1:
                menuQuanLy(database, d_table);
                break;  
            case 2:
                menuNhanVien(database, d_table);
                break;
            case 0:
                cout << "Ban da chon thoat chuong trinh!\n";
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
                }
    }
     return 0;
}






 












