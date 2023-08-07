/*
* File: OrderManagement.cpp
* Author: Binh Hoang
* Date: 07/08/2023
* Description: This is a file used for the order management.
*/

#include "OrderManagement.hpp"


/*
* Function: menuQuanLy()
* Description: This function is used to perform "Quan ly" program.
* Input:
*   list<Food> : A list to contain foods that have type data Food
*   vector<Table>: A vector to contain tables that have type data Table
* Output:
*   
*/
int menuQuanLy(list<Food> &database, vector<Table> &d_table){
    int chose;
    while(true){
        cout << "QUAN LY\n";
        cout << "1. Set so ban.\n";
        cout << "2. Them mon.\n";
        cout << "3. Sua mon.\n";
        cout << "4. Xoa mon.\n";
        cout << "5. Danh sach mon.\n";
        cout << "0. Quay lai.\n";
        cout << "Vui long chon CT:... ";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1: 
                cout << "---SET SO BAN---.\n";
                setSoBan(d_table);
                printf("Set so ban thanh cong!\n");
                pressAnyKey();
                break;
            case 2: 
                cout << "---THEM MON---.\n";
                showDanhSachMon(database);
                themMon(database);
                printf("Them mon thanh cong!\n");
                pressAnyKey();
                break;
            case 3:
                cout << "---SUA MON---.\n";
                showDanhSachMon(database);
                if(database.size() > 0){
                    int id;
                    cout << "Nhap ID mon: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    suaMon(database, id);
                }
                else{
                    cout << "Danh sach mon trong!\n";
                }
                pressAnyKey();
                break;
            case 4: 
                cout << "---XOA MON---.\n";
                showDanhSachMon(database);
                if(database.size() > 0) {
                    int id;
                    cout << "Nhap ID mon: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    if (xoaMon(database, id) == 1){
                        printf("Mon co ID = %d da bi xoa.\n", id);
                    }
                }
                else{
                    cout << "Danh sach mon trong!\n";
                }
                pressAnyKey();
                break;
            case 5: 
                cout << "---DANH SACH MON---.\n";
                if(database.size() > 0){
                    showDanhSachMon(database);
                }
                else{
                    cout << "Danh sach mon trong!\n";
                }
                pressAnyKey();
                break;
            case 0: 
                cout << "Ban da thoat khoi CT Quan Ly!.\n";
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
        }
    }
}

/*
* Function: setSoBan()
* Description: This function is used to perform "Quan ly" program.
* Input:
*   vector<Table>: A vector to contain tables that have type data Table
* Output:
*   Return a vector contain the number of tables and status of them (occupied: true, unoccupied: false)
*/
void setSoBan(vector<Table> &d_table){
    int SO_LUONG_BAN = 0;
    int SO_BAN;
    cout<<"Nhap so luong ban: ";
    cin>>SO_LUONG_BAN;

    for(SO_BAN=1; SO_BAN<= SO_LUONG_BAN; SO_BAN++){
        Table table(SO_BAN, false);
        d_table.push_back(table);
    }
}
/*
* Function: themMon()
* Description: This function is used to add food/drinks
* Input:
*   list<Food> : A list to contain foods that have type data Food
* Output:
*   returns the food/drinks in the list.
*/
int themMon(list<Food> &database){
    int chose;
    string TEN_MON;
    double GIA;
    while(true){
        cout << "1. Them mon moi.\n";
        cout << "0. Quay lai\n";
        cout << "Vui long chon CT:... ";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1:
                cout<<"Nhap ten mon: ";
                cin >> TEN_MON;
                cout<<"Nhap gia mon: ";
                cin >> GIA;
                {Food food(TEN_MON,GIA);
                database.push_back(food);}
                break;
            case 0:
                cout<<"Ban da chon thoat tinh nang them mon!\n";
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
        }
    }
 }

/*
* Function: suaMon()
* Description: This function is used to update price information of food/drinks in list
* Input:
*   list<Food>:  A list to contain Food that have type data Food
*   id: ID of a food
* Output:
*   returns price informations of a food that had changed .
*/
int suaMon(list<Food> &database, int id) {
    
    double GIA;
    int chose;

    list<Food>::iterator it;

    for(it = database.begin(); it != database.end(); it++){
        if (it->getID() == id) {
            while(true) {
                cout << "1. Thay doi gia.\n";
                cout << "0. Quay lai\n";
                cout << "Vui long chon CT:...";fflush(stdin);
                cin >> chose;
                switch(chose){
                case 1:
                    cout<<"Nhap lai gia: ";
                    cin>>GIA;
                    it->setGIA(GIA);
                    cout<<endl<<"Ban da cap nhat gia thanh cong!"<<endl;
                    pressAnyKey();
                    break;
                case 0:
                    cout << "Ban da chon thoat tinh nang sua mon!\n";
                    return 1;
                default:
                    cout << "Khong co chuc nang nay!\n";
                    cout << "\nHay chon chuc nang trong hop menu.\n";
                    pressAnyKey();
                    break;
                }
            }
    }
}
     printf("\n Mon an co ID = %d khong ton tai!", id);
     return 0;
}

/*
* Function: xoaMon()
* Description: This function is used to delete a food/drinks in list
* Input:
*   list<Food>:  A list to contain Food that have type data Food
*   id: ID of a food
* Output:
*   returns the list that have a deleted food/drinks with id above
*/
int xoaMon(list<Food> &database, int id){
    int chose;
    list<Food>::iterator it;
    
    for(it = database.begin(); it != database.end(); it++){
        if (it->getID() == id){
             while(true) {
                cout << "1. Xoa mon.\n";
                cout << "0. Quay lai\n";
                cout << "Vui long chon CT:...";fflush(stdin);
                cin >> chose;
                switch(chose){
                    case 1:
                        database.erase(it);
                        cout<<endl<<"Ban da xoa mon thanh cong!"<<endl;
                        pressAnyKey();
                        break;
                    case 0:
                        cout << "Ban da chon thoat tinh nang xoa mon!\n";
                        return 1;
                    default:
                        cout << "Khong co chuc nang nay!\n";
                        cout << "\nHay chon chuc nang trong hop menu.\n";
                        pressAnyKey();
                        break;
                }
             }
        }
    }
    printf("\n Mon co ID = %d khong ton tai!", id);
    return 0;
}

/*
* Function: showDanhSachMon()
* Description: This function is used to print all foods/drinks in list
* Input:
*   list<Food>:  A list to contain Food that have type data Food
* Output:
*   Printf all foods/drinks in list.
*/
void showDanhSachMon(list<Food> &database){
    
    list<Food>::iterator it;
    int i = 0;
    cout<<"Thong tin mon:";
    cout <<"\nSTT\tID\tTenMon\tGia";
    for(it = database.begin(); it != database.end(); it++){
        printf("\n%d", i + 1);
        printf("\t%d", it->getID());
        cout<<"     "<<it->getTenMon();
        printf("\t%.3lf", it->getGia());
        i++;
    }
    printLine(30);
}

/*
* Function: menuNhanVien()
* Description: This function is used to perform "Nhan Vien" program.
* Input:
*   list<Food> : A list to contain foods that have type data Food
*   vector<Table>: A vector to contain tables that have type data Table
* Output:
*   
*/
int menuNhanVien(list<Food> &database, vector<Table> &d_table){
    int chose;
    int so_ban;
    showBan(d_table);
    so_ban = chonBan(d_table);
    while(true){
        cout <<"BAN "<<so_ban<<endl;
        cout << "1. Them mon.\n";
        cout << "2. Sua mon.\n";
        cout << "3. Xoa mon.\n";
        cout << "4. Danh sach mon.\n";
        cout << "5. Thanh toan.\n";
        cout << "0. Quay lai.\n";
        cout << "Vui long chon CT:... ";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1: 
                cout << "---THEM MON TAI BAN---.\n";
                showDanhSachMon(database);
                showDanhSachMonTaiBan(database);
                themMonTaiBan(database);
                printf("Them mon thanh cong!\n");
                pressAnyKey();
                break;
            case 2:
                cout << "---SUA MON TAI BAN---.\n";
                showDanhSachMonTaiBan(database);
                if(database.size() > 0) {
                    int id;
                    cout << "Nhap ID mon: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    suaMonTaiBan(database, id);
                }else{
                    cout << "Danh sach mon trong!\n";
                }
                pressAnyKey();
                break;
            case 3: 
                cout << "---XOA MON TAI BAN.---\n";
                showDanhSachMonTaiBan(database);
                if(database.size() > 0) {
                    int id;
                    cout << "Nhap ID mon: ";fflush(stdin);
                    cin >> id;
                    cout<< endl;
                    if (xoaMon(database, id) == 1){
                        printf("Mon co ID = %d da bi xoa.\n", id);
                    }
                }
                else{
                    cout << "Danh sach mon trong!\n";
                }
                pressAnyKey();
                break;
            case 4: 
                cout << "---DANH SACH MON TAI BAN.---\n";
                if(database.size() > 0){
                    showDanhSachMonTaiBan(database);
                }
                else{
                    cout << "Danh sach mon tai ban trong!\n";
                }
                pressAnyKey();
                break;
            case 5: 
                cout << "---THANH TOAN.---\n";
                showDanhSachMonTaiBan(database);
                thanhTien(database, d_table, so_ban);
                pressAnyKey();
                break;
            case 0: 
                cout << "Ban da thoat khoi CT Nhan Vien!.\n";
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
        }
    }
}

/*
* Function: showBan()
* Description: This function is used to print all tables with status in the vector.
* Input:
*   vector<Table>:  A vector to contain tables that have type data Table
* Output:
*   Printf all tables with status of them.
*/
void showBan(vector<Table> &d_table){

    cout <<"\nSo Ban\tStatus";
    for(int i=0; i<d_table.size(); i++){
        printf("\n%d", d_table[i].getSoBan());
        printf("\t%d", d_table[i].getStatus());
    }
    printLine(30);
}

/*
* Function: chonBan()
* Description: This function is used to chose a unoccupied table
* Input:
*   vector<Table>:  A vector to contain tables that have type data Table
* Output:
*   Printf selected table number.
*/
int chonBan(vector<Table> &d_table){
    int SO_BAN;

    while(true){
        cout<<"Vui long chon Ban: ";
        cin>>SO_BAN;
        if(SO_BAN>0 && SO_BAN<= d_table.size()){
            for(int i=0; i<d_table.size(); i++){
                if(d_table[i].getSoBan()==SO_BAN && d_table[i].getStatus()== false){
                    d_table[i].setStatus(true);
                    return SO_BAN;
                }
            }
        }
    }
}

/*
* Function: themMonTaiBan()
* Description: This function is used to enter quantity food/drinks
* Input:
*   list<Food> : A list to contain foods that have type data Food
* Output:
*   returns the quantity of food/drinks in the list.
*/
int themMonTaiBan(list<Food> &database){
    int chose;
    int SO_LUONG;
    int ID;
    list<Food>::iterator it;
    while(true){
        cout << "1. Goi them mon .\n";
        cout << "0. Quay lai\n";
        cout << "Vui long chon CT:... ";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1:
                cout<<"Nhap ID mon: ";
                cin >> ID;
                cout<<"Nhap so luong: ";
                cin >> SO_LUONG;
                for(it = database.begin(); it != database.end(); it++){
                    if(it->getID() == ID) it->setSoLuong(SO_LUONG);
                }
                break;
            case 0:
                cout<<"Ban da chon thoat tinh nang goi them mon!\n";
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
        }
    }
}

/*
* Function: suaMonTaiBan()
* Description: This function is used to update quantity information of food/drinks in list
* Input:
*   list<Food>:  A list to contain Food that have type data Food
*   id: ID of a food
* Output:
*   returns quantity informations of a food that had changed .
*/
int suaMonTaiBan(list<Food> &database, int id){
       
    int SO_LUONG;
    int chose;

    list<Food>::iterator it;

    for(it = database.begin(); it != database.end(); it++){
        if (it->getID() == id) {
            while(true) {
                cout << "1. Thay doi so luong.\n";
                cout << "0. Quay lai\n";
                cout << "Vui long chon CT:...";fflush(stdin);
                cin >> chose;
                switch(chose){
                case 1:
                    cout<<"Nhap lai so luong: ";
                    cin>>SO_LUONG;
                    it->setSoLuong(SO_LUONG);
                    cout<<endl<<"Ban da cap nhat lai so luong thanh cong!"<<endl;
                    pressAnyKey();
                    break;
                case 0:
                    cout << "Ban da chon thoat tinh nang sua mon!\n";
                    return 1;
                default:
                    cout << "Khong co chuc nang nay!\n";
                    cout << "\nHay chon chuc nang trong hop menu.\n";
                    pressAnyKey();
                    break;
                }
            }
    }
}
     printf("\n Mon an co ID = %d khong ton tai!", id);
     return 0;
}

/*
* Function: showDanhSachMonTaiBan()
* Description: This function is used to print all foods/drinks in list
* Input:
*   list<Food>:  A list to contain Food that have type data Food
* Output:
*   Printf all foods/drinks in list.
*/
void showDanhSachMonTaiBan(list<Food> &database){
    list<Food>::iterator it;
    int i = 0;
    cout<<"Danh sach mon tai ban:"<<endl;
    cout <<"\nSTT\tID\tTenMon\tGia\tSoLuong";
    for(it = database.begin(); it != database.end(); it++){
        printf("\n%d", i + 1);
        printf("\t%d", it->getID());
        cout<<"     "<<it->getTenMon();
        printf("\t%.3lf", it->getGia());
        printf("\t%d", it->getSoLuong());
        i++;
    }
    printLine(30);
}

/*
* Function: ThanhTien()
* Description: This function is used to print the amount of money to be paid
* Input:
*   list<Food>:  A list to contain Food that have type data Food
*   vector<Table>: A vector to contain tables that have type data Table
*   int so_ban_da_chon: selected table number.
* Output:
*   Print the amount of money to be paid.
*/
int thanhTien(list<Food> &database, vector<Table> &d_table, int so_ban_da_chon){
    double sum = 0.000;
    list<Food>::iterator it;
    for(it = database.begin(); it != database.end(); it++){
        sum += (it->getGia()) * (it->getSoLuong());
        it->setSoLuong(0);
    }
    printf("Tong: %0.3lf VND\n",sum);
    for(int i=0; i<d_table.size(); i++){
        if(d_table[i].getSoBan() == so_ban_da_chon && d_table[i].getStatus()== true){
        
        d_table[i].setStatus(false);
        }
    }
     while(true) {
        int chose;
        cout << "1. Thanh toan.\n";
        cout << "0. Quay lai\n";
        cout << "Vui long chon CT:...";fflush(stdin);
        cin >> chose;
        switch(chose){
            case 1: 
                cout<<"Ban da chon thanh toan! Xin cam on Quy khach!"<<endl;
                return 1;
            case 0:
                cout<<"Ban da chon thoat CT thanh toan"<<endl;
                return 0;
            default:
                cout << "Khong co chuc nang nay!\n";
                cout << "\nHay chon chuc nang trong hop menu.\n";
                pressAnyKey();
                break;
        }
     }
}
/*
* Function: pressAnyKey()
* Description: This function is used to wait for any character to be entered from the keyboard
* Input:
*  
* Output:
*   Clear the console screen.
*/
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
/*
* Function: printLine()
* Description: This function is used to print many character "-"
* Input:
*   int n: number of characters "-"
* Output:
*   print n character "-".
*/
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}