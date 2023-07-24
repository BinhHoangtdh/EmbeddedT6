#include <iostream>
#include <list>

using namespace std;


int main(int argc, char **argv){
    list <int> array;

    list <int>::iterator it;
    array.push_back(7);
    array.push_back(15);
    array.push_back(5);

    int i = 0;
    for(it=array.begin(); it!=array.end(); it++){
        if(i==1){
            *it = 10 ;
            array.insert(it,40);
        }
        i++;
    }

    for(it=array.begin(); it!=array.end(); it++){
        cout << *it <<endl;
    }

    int a = 10;
    int k = 50;
    int m = 10;

    auto func = [a](int b)-> int{
        return a+b;
    };

    auto func1 = [=](int b)-> int{
        return a+b+k+m;
    };

    cout << func(18) << endl;
    cout << func1(18) << endl;

    return 0;
}