#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<conio.h>
#include "HotelManagement.hpp"
                    
using namespace std;

int main(int argc, char **argv){
    vector<Room> databaseRoom;
    employeeManager databaseEmployeeManagement;
    vector<Customer> databaseCustomers;
    securityManager databaseSecurityManagement;
    while(true){
        
        cout<<"*********************************"<<endl;
        cout<<"*   HOTEL MANAGEMENT PROGRAM    *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        cout<<"*    1. ROOMS MANAGEMENT        *"<<endl;
        cout<<"*    2. CUSTOMERS MANAGEMENT    *"<<endl;
        cout<<"*    3. EMPLOYEES MANAGEMENT    *"<<endl;
        cout<<"*    6. SECURITY MANAGEMENT     *"<<endl;
        cout<<"*    0. EXIT                    *"<<endl;
        cout<<"*********************************"<<endl;

        int chose;
        cout<<"Please choose the program.....";
        cin>>chose; cin.ignore();

        switch(chose) {
            case ROOM_MANAGEMENT:
                roomManagement(databaseRoom, databaseCustomers);
                pressAnyKey();
                break;
            case CUSTOMERS_MANAGEMENT:
                customersManagement(databaseRoom, databaseCustomers);
                pressAnyKey();
                break;
            case EMPLOYEES_MANAGEMENT:
                employeesManagement(databaseEmployeeManagement,databaseSecurityManagement);
                pressAnyKey();
                break;
            case SECURITY_MANAGEMENT:
                securityManagement(databaseSecurityManagement);
                pressAnyKey();
                break;
            case EXIT:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }
    return 0;
}






 












