#include<iostream>
#include<string>
#include<cassert>
#include<vector>
#include<conio.h>

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
        double DIEM_TRUNG_BINH = Diem_TB();
        TypeHocLuc HOC_LUC = xepLoaiHL();

        double Diem_TB(){
            return ((DIEM_TOAN + DIEM_LY + DIEM_HOA)/3);
        }
        TypeHocLuc xepLoaiHL(){
            if(DIEM_TRUNG_BINH >= 8) return GIOI;
            else if(DIEM_TRUNG_BINH >= 6.5) return KHA;
            else if(DIEM_TRUNG_BINH >= 5) return TRUNG_BINH;
            else return YEU;
        }
  
    public:
        SinhVien(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa);

        void capNhatThongTinSV(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa);

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
            return HOC_LUC;
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
            return DIEM_TRUNG_BINH;
        }
};


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

        assert((diem_toan >= 0 && diem_toan <= 10) && "Diem toan khong hop le!");
        assert((diem_ly >= 0 && diem_ly <= 10) && "Diem ly khong hop le!");
        assert((diem_hoa >= 0 && diem_hoa <= 10) && "Diem hoa khong hop le!");


}

void SinhVien:: capNhatThongTinSV(string ten, int tuoi, TypeGioiTinh gioi_tinh,
        double diem_toan, double diem_ly, double diem_hoa){
            TEN = ten;
            TUOI = tuoi;
            GIOI_TINH = gioi_tinh;
            DIEM_TOAN = diem_toan;
            DIEM_LY = diem_ly;
            DIEM_HOA = diem_hoa;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void ThemSinhVien(vector<SinhVien> &database){

    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    cout<<"Nhap ten sinh vien: ";
    nhap(TEN, TEN.length()<1);

    cout<<"Nhap tuoi sinh vien: ";
    nhap(TUOI, (TUOI < 18) || (TUOI > 25));

    cout<<"Nhap gioi tinh sinh vien: ";
    do { scanf("%d",&GIOI_TINH);}
    while (GIOI_TINH != 0 && GIOI_TINH != 1);

    cout<<"Nhap diem mon toan: ";
    nhap(DIEM_TOAN, (DIEM_TOAN < 0) || (DIEM_TOAN > 10));

    cout<<"Nhap diem mon ly: ";
    nhap(DIEM_LY, (DIEM_LY < 0) || (DIEM_LY > 10));

    cout<<"Nhap diem mon hoa: ";
    nhap(DIEM_HOA, (DIEM_HOA < 0) || (DIEM_HOA > 10));

    SinhVien sv(TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);
    
    database.push_back(sv);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void capNhatSV(vector<SinhVien> &database, int id) {
    
    string TEN;
    int TUOI;
    TypeGioiTinh GIOI_TINH;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;

    for(int i = 0; i < database.size(); i++){
        if (database[i].getID() == id) {
            cout<<"Nhap lai ten sinh vien: ";
            nhap(TEN, TEN.length()<1);

            cout<<"Nhap lai tuoi sinh vien: ";
            nhap(TUOI, (TUOI < 18) || (TUOI > 25));

            cout<<"Nhap lai gioi tinh sinh vien: ";
             do { scanf("%d",&GIOI_TINH);}
            while (GIOI_TINH != 0 && GIOI_TINH != 1);

            cout<<"Nhap lai diem mon toan: ";
            nhap(DIEM_TOAN, (DIEM_TOAN < 0) || (DIEM_TOAN > 10));

            cout<<"Nhap lai diem mon ly: ";
            nhap(DIEM_LY, (DIEM_LY < 0) || (DIEM_LY > 10));

            cout<<"Nhap lai diem mon hoa: ";
            nhap(DIEM_HOA, (DIEM_HOA < 0) || (DIEM_HOA > 10));

            database[i].capNhatThongTinSV(TEN, TUOI, GIOI_TINH, DIEM_TOAN, DIEM_LY, DIEM_HOA);
            break;
        }
        else{
            printf("\n Sinh vien co ID = %d khong ton tai.", id);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
int xoaSinhVienID(vector<SinhVien> &database, int id){

    int found = 0;
    for(int i = 0; i < database.size(); i++){
        if (database[i].getID() == id){
            found = 1;
            database.erase(database.begin() + i);
            cout << "\n Da xoa SV co ID = " << id;
            break;;
        }
    }
    if (found == 0) {
        printf("\n Sinh vien co ID = %d khong ton tai.", id);
        return 0;
    }else {
        return 1;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
int timKiemTheoTenSV(vector<SinhVien> &database, string ten){
    
    for(int i = 0; i < database.size(); i++){
        if (database[i].getTen() == ten){
            cout <<"\nSTT\tID\tTen\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
            printf("\n %d", i + 1);
            printf("\t%d", database[i].getID());
            printf("\t%s", database[i].getTen());
            printf("\t\t%s", database[i].getGioiTinh());
            printf("\t\t%d", database[i].getTuoi());
            printf("\t%.2f\t%.2f\t%.2f", database[i].getDiemToan(), database[i].getDiemLy(), database[i].getDiemHoa());
            printf("\t%.2f", database[i].getDTB());
            printf("\t%s", database[i].getHocLuc());
            break;;
        }
        else{
            printf("\n Sinh vien co TEN = %s khong ton tai.", ten);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void showStudent(vector<SinhVien> &database){
    
    cout <<"\nSTT\tID\tTen\tGioi tinh\tTuoi\tToan\tLy\tHoa\tDiem TB\tHoc luc";
    for(int i = 0; i < database.size(); i++){
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", database[i].getID());
        printf("\t%s", database[i].getTen());
        printf("\t%s", database[i].getGioiTinh());
        printf("\t%d", database[i].getTuoi());
        printf("\t%.2lf\t%.2lf\t%.2lf", database[i].getDiemToan(), database[i].getDiemLy(), database[i].getDiemHoa());
        printf("\t%.2lf", database[i].getDTB());
        printf("\t%s", database[i].getHocLuc());
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void sapXepTheoDTB(vector<SinhVien> &database) {
    //Sap xep theo DTB tang dan
    vector<SinhVien> tmp;
    for(int i = 0;i < database.size();i++){
        for(int j = i+1; j < database.size();j++){
            if(database[i].getDTB() > database[j].getDTB()){
                tmp[i] = database[i];
                database[i] = database[j];
                database[j] = tmp[i];
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
void sapXepTheoTen(vector<SinhVien> &database) {
     //Sap xep sinh vien theo ten theo thu tu tang dan
    vector<SinhVien> tmp;
    for(int i = 0;i < database.size(); i++) {
        for(int j = i+1; j <database.size(); j++) {
            if((database[i].getTen()).compare(database[j].getTen()) > 0) {
                tmp[i] = database[i];
                database[i] = database[j];
                database[j] = tmp[i];
            }
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){

    vector<SinhVien> database;
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
                    fflush(stdin); getline(cin,ten);
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

    
   
