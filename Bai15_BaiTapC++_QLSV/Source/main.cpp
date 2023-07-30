#include<iostream>
#include<string>
#include<cassert>
#include<list>
#include<conio.h>
#include<stdio.h>
#include "QuanLySinhVien.hpp"


int main(int argc, char const *argv[]){

    list<SinhVien> database;
    int chose;

    
    while(true) {
        
        cout << "CHUONG TRINH QUAN LY SINH VIEN C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sinh vien.                               **\n";
        cout << "**  2. Cap nhat thong tin sinh vien boi ID.          **\n";
        cout << "**  3. Xoa sinh vien boi ID.                         **\n";
        cout << "**  4. Tim kiem sinh vien theo ten.                  **\n";
        cout << "**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n";
        cout << "**  6. Sap xep sinh vien theo ten.                   **\n";
        cout << "**  7. Hien thi danh sach sinh vien.                 **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1:
                cout << "1. Them sinh vien.\n";
                ThemSinhVien(database);
                printf("Them sinh vien thanh cong!\n");
                pressAnyKey();
                break;
            case 2:
                if(database.size() > 0) {
                    int id;
                    cout << "2. Cap nhat thong tin sinh vien.\n";
                    cout << "Nhap ID: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    capNhatSV(database, id);
                }else{
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
                break;
            case 3:
                if(database.size() > 0) {
                    int id;
                    cout << "3. Xoa sinh vien.\n";
                    cout << "Nhap ID: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    if (xoaSinhVienID(database, id) == 1){
                        printf("Sinh vien co ID = %d da bi xoa.\n", id);
                    }
                }
                else{
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
                break;
            case 4:
                if(database.size() > 0){
                    cout << "4. Tim kiem sinh vien theo ten.\n";
                    string ten;
                    cout << "Nhap ten de tim kiem: "; 
                    fflush(stdin); cin>>ten;
                    cout<< endl;
                    timKiemTheoTenSV(database, ten);
                }
                else{
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
                break;
            case 5:
                if(database.size() > 0) {
                    cout << "5. Sap xep sinh vien theo diem trung binh (GPA).\n";
                    sapXepTheoDTB(database);
                    showStudent(database);
                }
                else{
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
                break;
            case 6:
                if(database.size() > 0) {
                    cout << "6. Sap xep sinh vien theo ten.\n";
                    sapXepTheoTen(database);
                    showStudent(database);
                } 
                else {
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
                break;
            case 7:
                if(database.size() > 0){
                    cout << "7. Hien thi danh sach sinh vien.\n";
                    showStudent(database);
                }
                else{
                    cout << "Danh sach sinh vien trong!\n";
                }
                pressAnyKey();
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

