/*
* File: QuanLySinhVien.h
* Author: Binh Hoang
* Date: 30/07/2023
* Description: This is a file writed for the management in student list.
*/

#include "QuanLySinhVien.hpp"


/*
* Function: SinhVien(): Constructor function of class "SinhVien"
*/
SinhVien::SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa){

        static int id = 1000;
        ID = id;
        id++;
        TEN = ten;
        TUOI = tuoi;
        GIOI_TINH = gioi_tinh;
        DIEM_TOAN = diem_toan;
        DIEM_LY = diem_ly;
        DIEM_HOA = diem_hoa;
}
/*
* Function: ThemSinhVien()
* Description: This function is used to add student
* Input:
*   list<SinhVien> : A list to contain student that have type data SinhVien
* Output:
*   returns a student in the list.
*/
void ThemSinhVien(list<SinhVien> &database){

    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    cout<<"Nhap ten sinh vien (it nhat 2 ky tu): ";
    nhap(TEN, LengthString(TEN)<2);

    cout<<"Nhap tuoi sinh vien (18 - 25 tuoi): ";
    nhap(TUOI, (TUOI < 18) || (TUOI > 25));

    cout<<"Nhap gioi tinh sinh vien (0:Nu, 1: Nam): ";
    do { scanf("%d",&GIOI_TINH);}
    while (GIOI_TINH != 0 && GIOI_TINH != 1);

    cout<<"Nhap diem mon toan (0 - 10 diem): ";
    nhap(DIEM_TOAN, (DIEM_TOAN < 0) || (DIEM_TOAN > 10));

    cout<<"Nhap diem mon ly (0 - 10 diem): ";
    nhap(DIEM_LY, (DIEM_LY < 0) || (DIEM_LY > 10));

    cout<<"Nhap diem mon hoa (0 - 10 diem): ";
    nhap(DIEM_HOA, (DIEM_HOA < 0) || (DIEM_HOA > 10));

    SinhVien sv(TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);
    
    database.push_back(sv);
}

/*
* Function: capNhatSV()
* Description: This function is used to update information of student in list
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
*   id: ID of a student
* Output:
*   returns informations of a student that had changed .
*/
int capNhatSV(list<SinhVien> &database, int id) {
    
    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;
    int chose;

    list <SinhVien>::iterator it;

    for(it = database.begin(); it != database.end(); it++){
        if (it->getID() == id) {

        while(true) {
            
            cout << "*************************MENU**************************\n";
            cout << "**  1. Cap nhat lai TEN.                             **\n";
            cout << "**  2. Cap nhat lai TUOI.                            **\n";
            cout << "**  3. Cap nhat lai GIOI TINH.                       **\n";
            cout << "**  4. Cap nhat lai DIEM TOAN.                       **\n";
            cout << "**  5. Cap nhat lai DIEM LY.                         **\n";
            cout << "**  6. Cap nhat lai DIEM HOA.                        **\n";
            cout << "**  0. Thoat                                         **\n";
            cout << "*******************************************************\n";
            cout << "Nhap tuy chon: ";fflush(stdin);
            cin >> chose;
            switch(chose){
            case 1:
                cout<<"Nhap lai ten sinh vien: ";
                nhap(TEN, TEN.length()<1);
                it->setTen(TEN);
                cout<<endl<<"Ban da cap nhat TEN thanh cong!"<<endl;
                pressAnyKey();
                break;

            case 2:
                cout<<"Nhap lai tuoi sinh vien: ";
                nhap(TUOI, (TUOI < 18) || (TUOI > 25));
                it->setTuoi(TUOI);
                cout<<endl<<"Ban da cap nhat TUOI thanh cong!"<<endl;
                pressAnyKey();
                break;

            case 3:
                cout<<"Nhap lai gioi tinh sinh vien: ";
                do { scanf("%d",&GIOI_TINH);}
                while (GIOI_TINH != 0 && GIOI_TINH != 1);
                it->setGioiTinh(GIOI_TINH);
                cout<<endl<<"Ban da cap nhat GIOI TINH thanh cong!"<<endl;
                pressAnyKey();
                break;

            case 4:
                cout<<"Nhap lai diem mon toan: ";
                nhap(DIEM_TOAN, (DIEM_TOAN < 0) || (DIEM_TOAN > 10));
                it->setDiemToan(DIEM_TOAN);
                cout<<endl<<"Ban da cap nhat DIEM TOAN thanh cong!"<<endl;
                pressAnyKey();
                break;

            case 5:
                cout<<"Nhap lai diem mon ly: ";
                nhap(DIEM_LY, (DIEM_LY < 0) || (DIEM_LY > 10));
                it->setDiemLy(DIEM_LY);
                cout<<endl<<"Ban da cap nhat DIEM LY thanh cong!"<<endl;
                pressAnyKey();
                break;

            case 6:
                cout<<"Nhap lai diem mon hoa: ";
                nhap(DIEM_HOA, (DIEM_HOA < 0) || (DIEM_HOA > 10));
                it->setDiemHoa(DIEM_HOA);
                cout<<endl<<"Ban da cap nhat DIEM HOA thanh cong!"<<endl;
                pressAnyKey();
                break;
            case 0:
                cout << "Ban da chon thoat tinh nang cap nhat thong tin sv!\n";
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
     printf("\n Sinh vien co ID = %d khong ton tai!", id);
     return 0;
}

/*
* Function: xoaSinhVienID()
* Description: This function is used to delete a student in list
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
*   id: ID of a student
* Output:
*   returns the list that have a deleted student with id above
*/
int xoaSinhVienID(list<SinhVien> &database, int id){

    list<SinhVien>::iterator it;
    
    for(it = database.begin(); it != database.end(); it++){
        if (it->getID() == id){
            database.erase(it);
            return 1;
        }
    }
    printf("\n Sinh vien co ID = %d khong ton tai!", id);
    return 0;
    
}

/*
* Function: timKiemTheoTenSV()
* Description: This function is used to find a student in list by name
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
*   ten: ten of a student needed to find
* Output:
*   Printf the student was found or not found.
*/
int timKiemTheoTenSV(list<SinhVien> &database, string ten){
    
    list<SinhVien>::iterator it;
    int i = 0;
    for(it = database.begin(); it != database.end(); it++){
        if (it->getTen() == ten){
            cout <<"\nSTT\tID\tTen\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\t\tHoc luc";
            printf("\n %d", i + 1);
            printf("\t%d", it->getID());
            cout<<"    "<<it->getTen();
            printf("\t\t%d", it->getGioiTinh());
            printf("\t%d", it->getTuoi());
            printf("\t%.2lf\t%.2lf\t%.2lf", it->getDiemToan(), it->getDiemLy(), it->getDiemHoa());
            printf("\t%.2lf", it->getDTB());
            printf("\t\t%d", it->getHocLuc());
            return 1;
        }
        else{
            i++;
        }
    }
    cout<<endl<<"Sinh vien co ten "<<ten<<" khong ton tai!"<<endl;
    return 0;
}

/*
* Function: showStudent()
* Description: This function is used to printf all students that have in list
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
* Output:
*   Printf all students in list.
*/
void showStudent(list<SinhVien> &database){
    
    list<SinhVien>::iterator it;
    int i = 0;

    cout <<"\nSTT\tID\tTen\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\t\tHoc luc";
    for(it = database.begin(); it != database.end(); it++){
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", it->getID());
        cout<<"    "<<it->getTen();
        printf("\t\t%d", it->getGioiTinh());
        printf("\t%d", it->getTuoi());
        printf("\t%.2lf\t%.2lf\t%.2lf", it->getDiemToan(), it->getDiemLy(), it->getDiemHoa());
        printf("\t%.2lf", it->getDTB());
        printf("\t\t%d", it->getHocLuc());
        i++;
    }
}

/*
* Function: sapXepTheoDTB()
* Description: This function is used to sort all the students in the list in ascending GPA order
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
* Output:
*   Printf all students in list.
*/
void sapXepTheoDTB(list<SinhVien> &database) {
    //Sap xep theo DTB tang dan
    list<SinhVien>::iterator it;
    list<SinhVien>::iterator jt;
    list<SinhVien>::iterator temp;
    

    for(it = database.begin(); it != database.end(); it++){
        temp =it;
        temp++;
        for(jt = temp; jt != database.end();jt++){
            if(it->getDTB() > jt->getDTB()){
                auto tmp = *it;
                *it = *jt;
                *jt = tmp;
            }
        }
    }
}

/*
* Function: sapXepTheoTen()
* Description: This function is used to sort all the students in the list in ascending name order
* Input:
*   list<SinhVien>:  A list to contain student that have type data SinhVien
* Output:
*   Printf all students in list.
*/
void sapXepTheoTen(list<SinhVien> &database) {
     //Sap xep sinh vien theo ten theo thu tu tang dan
    list<SinhVien>::iterator it;
    list<SinhVien>::iterator jt;
    list<SinhVien>::iterator temp;
    
    for(it = database.begin(); it != database.end(); it++){
        temp =it;
        temp++;
        for(jt = temp; jt != database.end();jt++){
            auto ten1 = it->getTen();
            auto ten2 = jt->getTen();
            if(isCompareResult(ten1,ten2) > 0){
                auto tmp = *it;
                *it = *jt;
                *jt = tmp;
            }
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
* Function: isCompareResult()
* Description: This function is used to compare two strings
* Input:
*   string arr1 -  string 1
*   string arr1 -  string 2
* Output:
*   returns the comparing result of two string.
*/
bool isCompareResult(string arr1, string arr2)
{

    int i=0;
    while (arr1[i] == arr2[i])
    {
        if(arr1[i] == '\0'){
            return 0;
        }
        i++;
    }
    if (arr1[i] > arr2[i])
    {
        return 1;
    }
    else{
        return -1;
    }
}

/*
* Function: LengthString()
* Description: This function is used to find length of a string
* Input:
*   string arr
* Output:
*   returns length of the string.
*/
int LengthString(string arr){
    int i = 0;
    while(arr[i] != '\0'){
        i++;
    }
    return i;
}