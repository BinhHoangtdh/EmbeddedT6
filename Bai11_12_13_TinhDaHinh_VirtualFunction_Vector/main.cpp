#include <iostream>
#include <string>
#include "test.cpp"
#include "vector"

using namespace std;

// Khai bao vung nho cho 2 bien 'Teo' nay. 2 Bien nay nam o 2 vung nho khac nhau. 
// Namespace co the chua tat ca moi thu nhu: bien, struct, class, mang,...
namespace conOngA{
    int Teo = 10;

    class ToanHoc1{
    public:
        void Tong(int x, int y){
            cout<<"Tong x va y: "<< x+y <<endl;
        }
        void Tong(float x, float y){
            cout<<"Tong x va y: "<< x+y <<endl;
        }
};
}

namespace conOngB{
    int Teo = 20;
}

class ToanHoc{
    public:
        void Tong(int x, int y){
            cout<<"Tong x va y: "<< x+y <<endl;
        }
        void Tong(float x, float y){
            cout<<"Tong x va y: "<< x+y <<endl;
        }
         void Tong(float x, float y, float z){
            cout<<"Tong x y va z: "<< x+y+z <<endl;
        }
};

template <typename bien, typename bien1>

bien tong(bien a, bien1 b){
    return (bien)(a+b);
}


class SinhVien{
    protected:
    virtual char *comment(){
            return (char*)"class sinh vien\n";
        }
    public:
        void display(){
            printf("%s\n", comment());
        }
};

class HocSinh : public SinhVien{
    private:
        char *comment(){
            return (char*)"class hoc sinh\n";
        }
};

int main(int argc, char **argv){

    ToanHoc th;

    th.Tong(5,6);

    th.Tong((float)5.1, (float)6.1);

    printf("%f\n", tong(5.1,6));

    cout<< "teo con ong A "<< conOngA::Teo<<endl;

    cout<< "teo con ong B "<< conOngB::Teo<<endl;

    conOngA::ToanHoc1 ch;

    ch.Tong(5,7);

    conOngB::Test;

    HocSinh hs;

    hs.display();

    vector <int> array = {1, 4, 7, 5};

    array.push_back(30);

    array.insert(array.begin() + 1, 45);

    array.pop_back();

    for(int i = 0; i < array.size(); i++){
        cout<<array[i]<<endl;
    }

// Vong lap for cai tien trong C++
    for(int item : array){
        cout<<item<<endl;
    }

    auto test = 10.8;

    return 0;
}