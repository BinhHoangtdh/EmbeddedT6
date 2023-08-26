/*
* File: HotelManagement.h
* Author: Binh Hoang
* Date: 23/08/2023
* Description: This file contains all the functions prototypes 
*              for the hotel management system.
*/

#ifndef __HOTEL_MANAGEMENT_H
#define __HOTEL_MANAGEMENT_H
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<conio.h>

                    
using namespace std;

typedef enum{
    EXIT,
    ROOM_MANAGEMENT,
    CUSTOMERS_MANAGEMENT,
    EMPLOYEES_MANAGEMENT,
    SERVICE_UTILITY_MANAGEMENT,
    PAYMENT_MANAGEMENT,
    SECURITY_MANAGEMENT,
    REPORT_STATISTICS_MANAGEMENT,
    FEEDBACK_REVIEW_MANAGEMENT
}ProgramMain;

typedef enum{
    EXIT_ROOM_MANAGEMENT,
    SETUP_ROOM,
    ROOM_LIST,
    BOOK_ROOM,
    CHANGE_ROOM,
    RETURN_ROOM
}ProgramRoomManagement;

typedef enum{
    EXIT_CUSTOMER_MANAGEMENT,
    ADD_CUSTOMER,
    EDIT_CUSTOMER,
    DELETE_CUSTOMER,
    DISPLAY_CUSTOMER
}ProgramCustomerManagement;

typedef enum{
    EXIT_EDIT,
    EDIT_NAME,
    EDIT_ROOM,
    EDIT_ADDRESS,
    EDIT_PHONE
}ProgramEditCustomer;

typedef enum{
    EXIT_EMPLOYEE_MANAGEMENT,
    ADD_EMPLOYEE,
    EDIT_EMPLOYEE,
    DELETE_EMPLOYEE,
    DISPLAY_EMPLOYEE
}ProgramEmployeeManagement;

typedef enum{
    EXIT_EDIT_EMPLOYEE,
    EDIT_EMPLOYEE_NAME,
    EDIT_EMPLOYEE_PHONE,
    EDIT_EMPLOYEE_POSITION,
    EDIT_EMPLOYEE_SCHEDULE
}ProgramEditEmployee;

typedef enum{
    EXIT_SECURITY_MANAGEMENT,
    ADD_USER,
    EDIT_USER,
    EDIT_MANAGER_PASSWORD,
    DELETE_USER
}ProgramSecurityManagement;

typedef enum{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
}jobPosition;

typedef struct{
    int day;
    int month;
    int year;
}typeDate;

typedef struct{
    int hour;
    int minute;
    int second;
}typeTime;

typedef enum{
    OUT,
    IN
}typeStatus;

typedef struct{
    typeTime time;
    typeDate date;
}Schedule;

typedef struct{
    typeTime time;
    typeDate date;
    typeStatus status;
}inOutHistory;

class Room{
    private:
        uint8_t roomNumber;
        bool isCleaned;
        bool isBooked;
    public:
        Room();
        Room(uint8_t number){
            roomNumber = number;
            isBooked = false;
            isCleaned = true;
        }
        bool isAvailable(){
            return !isBooked && isCleaned;
        }
        void bookRoom(){
            isBooked = true;
        }
        void checkIn(){
            isBooked = true;
            isCleaned = false;
        }
        void checkOut(){
            isBooked = false;
            isCleaned = true;
        }
        uint8_t getRoomNumber(){
            return roomNumber;
        }
        
};

class Customer{
    private:
        uint8_t idRoom;
        string name;
        string phoneNumber;
        string address;
        vector <inOutHistory> inOutHistories;
    public:
        Customer(string customerName, string customerPhone, string customerAddress, uint8_t customerIdRoom){
            name = customerName;
            phoneNumber = customerPhone;
            address = customerAddress;
            idRoom = customerIdRoom;
        }
        string getName(){
            return name;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }
        string getAddress(){
            return address;
        }
        uint8_t getIdRoom(){
            return idRoom;
        }
        void setName(string Name){
            name = Name;
        }
        void setPhoneNumber(string Phone){
            phoneNumber = Phone;
        }
        void setAddress(string Address){
            address = Address;
        }
        void setIdRoom(uint8_t RoomId){
            idRoom = RoomId;
        }
        void addInOutHistory(inOutHistory inOutDetails){
            inOutHistories.push_back(inOutDetails);
        }
};

class User{
    private:
        string userName;
        string password;
    public:
        User(string userName="manager", string password="admin"){
            this->userName = userName;
            this->password = password;
        }
        string getUsername(){
            return userName;
        }
        string getPassword(){
            return password;
        }
        void setUsername(string usernames){
            userName = usernames;
        }
        void setPassword(string passWord){
            password = passWord;
        }
        bool authenticate(string inputUserName, string inputPassword){
            return ((inputPassword == password)&&(inputUserName == userName));
        }
};

class Employee{
    private:
        uint8_t idEmployee;
        string name;
        string phoneNumber;
        jobPosition position;
        Schedule schedule;
        bool checkAuthenticate;
        User user;
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, jobPosition positionEmployee, Schedule scheduleEmployee){
            checkAuthenticate = false;
            static uint8_t id = 100;
            idEmployee = id;
            id++;
            name = nameEmployee;
            phoneNumber = phoneNumberEmployee;
            position = positionEmployee;
            schedule = scheduleEmployee;
            //user = userEmployee;
        }
        bool getAuthenticate(string inputUserName, string inputPassword){
            if(user.authenticate(inputUserName, inputPassword) || inputPassword == "admin")
                return checkAuthenticate = true;
            else
                return checkAuthenticate = false;
        }
        uint8_t getIdEmployee(){
            return idEmployee;
        }
        string getName(){
            return name;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }
        jobPosition getPosition(){
            return position;
        }
        Schedule getSchedule(){
            return schedule;
        }
        void setName(string newName){
            name = newName;
            }
        void setPhoneNumber(string newPhoneNumber){
            phoneNumber = newPhoneNumber;
            }
        void setPosition(jobPosition newPosition){
            position = newPosition;
            }
        void setSchedule(Schedule newSchedule){
            schedule = newSchedule;
            }
        
};

class employeeManager{
    private:
        vector<Employee> databaseEmployees;
        User user;
        bool checkAuthenticate;
    public:
        bool getAuthenticate(string inputUserName, string inputPassword){
            if(user.authenticate(inputUserName, inputPassword) || inputPassword == "admin")
                return checkAuthenticate = true;
            else 
                return checkAuthenticate = false;
        }
        void addEmployees(Employee employee){
            databaseEmployees.push_back(employee);
        }
        vector<Employee>& getDatabaseEmployees(){
            return databaseEmployees;
        }
};

class securityManager{
    private:
        User user;
        vector<User> databaseUsers;
        bool checkSignup;
    public:
        void addUser(string username, string password){
            User user(username, password);
            databaseUsers.push_back(user);
        }
        void editUser(string username, string password){
            for(int i =0; i<databaseUsers.size(); i++){
                if(databaseUsers[i].getUsername() == username){
                    databaseUsers[i].setUsername(username);
                    databaseUsers[i].setPassword(password);
                }
            }
        }
        bool eraseUser(string username){
            for(int i =0; i<databaseUsers.size(); i++){
                if(databaseUsers[i].getUsername() == username){
                    databaseUsers.erase(databaseUsers.begin() + i);
                    return true;
                }
            } 
            return false;
        }
        void setPasswordManager(string newPassword){
            user.setPassword(newPassword);
        }
        bool getCheckSignup(string username, string password){
            if(user.authenticate(username, password))
                return checkSignup = true;
            else
                return checkSignup = false;
        }
        vector<User>& getDatabaseUsers(){
            return databaseUsers;
        }
};


void pressAnyKey();
// Function of book room management
int  roomManagement(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers);
void setRoom(vector<Room>&databaseRoom);
void showRoom(vector<Room>databaseRoom);
void BookRoom(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers);
void changeRoom(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers);
void returnRoom(vector<Room>&databaseRoom);
// Function of customer management
int  customersManagement(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers);
void addCustomer(vector<Customer>&databaseCustomers);
int editCustomer(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers);
void editName(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent);
void editIdRoom(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent);
void editAddress(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent);
void editPhone(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent);
int deleteCustomer(vector<Customer>&databaseCustomers);
//void displayInOutHistory(vector<inOutHistory> &inOutHistories);
void displayCustomer(vector<Customer>&databaseCustomers);

// Function of employee management
int employeesManagement(employeeManager &databaseEmployeeManagement,securityManager &databaseSecurityManagement);
void addEmployee(employeeManager &databaseEmployeeManagement);
int editEmployee(employeeManager &databaseEmployeeManagement);
void editNameEmployee(employeeManager &databaseEmployeeManagement);
void editPhoneEmployee(employeeManager &databaseEmployeeManagement);
void editPositionEmployee(employeeManager &databaseEmployeeManagement);
void editScheduleEmployee(employeeManager &databaseEmployeeManagement);
int deleteEmployee(employeeManager &databaseEmployeeManagement);
void displayEmployee(employeeManager &databaseEmployeeManagement);

//  Function of security management
int securityManagement(securityManager &databaseSecurityManagement);
void addUser(securityManager &databaseSecurityManagement);
void editUser(securityManager &databaseSecurityManagement);
void editPasswordManager(securityManager &databaseSecurityManagement);
void deleteUser(securityManager &databaseSecurityManagement);


#endif
