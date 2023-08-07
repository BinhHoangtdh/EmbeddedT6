/*
* File: OrderManagement.h
* Author: Binh Hoang
* Date: 07/08/2023
* Description: This file contains all the functions prototypes 
*              for the order management system.
*/

#ifndef __ORDER_H
#define __ORDER_H
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<conio.h>
#include<stdio.h>

                    
using namespace std;

class Food{
    private:
        int ID;
        string TEN_MON;
        double GIA;
        int SO_LUONG = 0;
        
    public:
        Food(string ten_mon, double gia){
            static int id = 100;
            ID = id;
            id++;
            TEN_MON = ten_mon;
            GIA = gia;
        }
        
        string setTen(string ten_mon){
            return TEN_MON = ten_mon;
        }
        double setGIA(double gia){
            return GIA = gia;
        }
        int setSoLuong(int so_luong){
                    return SO_LUONG = so_luong;
        }

        int getID(){
            return ID;
        }
        double getGia(){
            return GIA;
        }
         int getSoLuong(){
            return SO_LUONG;
        }
        string getTenMon(){
            return TEN_MON;
        }
};

class Table{
    private:
        int SO_BAN;
        bool STATUS = false;
    public:

        Table(int so_ban, bool status){
            SO_BAN = so_ban;
            STATUS = status;
        }

        bool setStatus(int status) {
            return STATUS == status;
        }
        bool getStatus(){
            return STATUS;
        }
        int getSoBan(){
            return SO_BAN;
        }

};

int menuQuanLy(list<Food> &database, vector<Table> &d_table);
void setSoBan(vector<Table> &d_table);
int themMon(list<Food> &database);
int suaMon(list<Food> &database, int id);
int xoaMon(list<Food> &database, int id);
void showDanhSachMon(list<Food> &database);


int menuNhanVien(list<Food> &database, vector<Table> &d_table);
void showBan(vector<Table> &d_table);
int chonBan(vector<Table> &d_table);
int themMonTaiBan(list<Food> &database);
int suaMonTaiBan(list<Food> &database, int id);
void showDanhSachMonTaiBan(list<Food> &database);
int thanhTien(list<Food> &database, vector<Table> &d_table, int so_ban_da_chon);

void pressAnyKey();
void printLine(int n);

#endif
