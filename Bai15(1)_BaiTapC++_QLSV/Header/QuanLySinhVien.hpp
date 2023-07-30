/*
* File: QuanLySinhVien.h
* Author: Binh Hoang
* Date: 30/07/2023
* Description: This file contains all the functions prototypes 
*              for the management in student list.
*/

#ifndef __QLSV_H
#define __QLSV_H
#include<iostream>
#include<string>
#include<cassert>
#include<list>
#include<conio.h>
#include<stdio.h>
#define nhap(x,y) do { cin>> x;}\
                    while (y);
                    
using namespace std;

typedef enum{
    NU,
    NAM
}TypeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU
}TypeHocLuc;

class SinhVien{
    private:
        int ID;
        string TEN;
        int TUOI;
        TypeGioiTinh GIOI_TINH;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;

        double TinhDTB(double dtoan, double dly, double dhoa){
            return (dtoan + dly + dhoa)/3;
        }
        TypeHocLuc xepLoaiHL(double dtb){
            if( dtb>= 8) return GIOI;
            else if(dtb >= 6.5) return KHA;
            else if(dtb >= 5) return TRUNG_BINH;
            else return YEU;
        }
    public:
        SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa);

        string setTen(string ten){
            return TEN = ten;
        }

        int setTuoi(int tuoi){
            return TUOI = tuoi;
        }

        TypeGioiTinh setGioiTinh(TypeGioiTinh gioi_tinh){
            return GIOI_TINH = gioi_tinh;
        }

        double setDiemToan(double diem_toan){
            return DIEM_TOAN = diem_toan;
        }
        double setDiemLy(double diem_ly){
            return DIEM_LY = diem_ly;
        }
        double setDiemHoa(double diem_hoa){
            return DIEM_HOA = diem_hoa;
        }

        string getTen(){
            return TEN;
        }

        int getTuoi(){
            return TUOI;
        }

        TypeGioiTinh getGioiTinh(){
            return GIOI_TINH;
        }

        int getID(){
            return ID;
        }

        TypeHocLuc getHocLuc(){
            return xepLoaiHL(getDTB());
        }
        double getDiemToan(){
            return DIEM_TOAN;
        }
        double getDiemLy(){
            return DIEM_LY;
        }
        double getDiemHoa(){
            return DIEM_HOA;
        }
        
        double getDTB(){
            return TinhDTB(DIEM_TOAN, DIEM_LY, DIEM_HOA);
        }
};

void ThemSinhVien(list<SinhVien> &database);
int capNhatSV(list<SinhVien> &database, int id);
int xoaSinhVienID(list<SinhVien> &database, int id);
int timKiemTheoTenSV(list<SinhVien> &database, string ten);
void sapXepTheoDTB(list<SinhVien> &database);
void sapXepTheoTen(list<SinhVien> &database);
void showStudent(list<SinhVien> &database);
void pressAnyKey();
int isCompareResult(string arr1, string arr2);
int LengthString(string arr);


#endif
