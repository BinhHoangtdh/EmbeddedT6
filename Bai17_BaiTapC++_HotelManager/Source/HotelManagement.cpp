/*
* File: HotelManagement.cpp
* Author: Binh Hoang
* Date: 23/08/2023
* Description: This is a file used for the hotel management.
*/

#include "HotelManagement.hpp"


/*
* Function: roomManagement()
* Description: This function is used to perform "ROOM MANAGEMENT" program.
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   
*/
int roomManagement(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers){
    while(true){
        cout<<"*********************************"<<endl;
        cout<<"*   ROOM MANAGEMENT PROGRAM     *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        cout<<"*    1. SET-UP ROOMS            *"<<endl;
        cout<<"*    2. ROOM LIST               *"<<endl;
        cout<<"*    3. BOOK ROOM               *"<<endl;
        cout<<"*    4. CHANGE ROOM             *"<<endl;
        cout<<"*    5. RETURN ROOM             *"<<endl;
        cout<<"*    0. EXIT                    *"<<endl;
        cout<<"*********************************"<<endl;
        int chose;
        cout<<"Please choose the program.....";
        cin>>chose; cin.ignore();

        switch(chose) {
            case SETUP_ROOM:
                setRoom(databaseRoom);
                showRoom(databaseRoom);
                pressAnyKey();
                break;
            case ROOM_LIST:
                showRoom(databaseRoom);
                pressAnyKey();
                break;
            case BOOK_ROOM:
                showRoom(databaseRoom);
                BookRoom(databaseRoom, databaseCustomers);
                pressAnyKey();
                break;
            case CHANGE_ROOM:
                showRoom(databaseRoom);
                changeRoom(databaseRoom, databaseCustomers);
                pressAnyKey();
                break;
            case RETURN_ROOM:
                returnRoom(databaseRoom);
                pressAnyKey();
                break;

            case EXIT_ROOM_MANAGEMENT:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }
}

/*
* Function: setRoom()
* Description: This function is used to set the number of room.
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
* Output:
*   Return number of room
*/
void setRoom(vector<Room>&databaseRoom){
    int numberRoom;
    cout<<"Enter the number of room: ";
    cin>>numberRoom;

    for(int i = 1; i <= numberRoom; i++){
        Room room(i);
        databaseRoom.push_back(room);
    }
}

/*
* Function: showRoom()
* Description: This function is used to printf list of rooms and their status
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
* Output:
*   returns list of rooms and their status.
*/
void showRoom(vector<Room>databaseRoom){
    cout <<"\n|Room|\t|Status|";
    for(int i=0; i<databaseRoom.size(); i++){
        printf("\n| %d  |", databaseRoom[i].getRoomNumber());
        if(databaseRoom[i].isAvailable()){
            printf("\t|  %c   |", '0');
        }
        else printf("\t|  %c   |", 'x');
    }
    cout<<endl;
}

/*
* Function: BookRoom()
* Description: This function is used to book a room
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   returns list of rooms, their status and information of customers.
*/
void BookRoom(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers){
    int roomNumber;

    do{
        cout<<"\nPlease select room to check in: ";
        cin>>roomNumber; cin.ignore();
    }
    while(roomNumber<= 0 && roomNumber > databaseRoom[databaseRoom.size()].getRoomNumber());
    for(int i=0; i<databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber() == roomNumber && databaseRoom[i].isAvailable()== true){
            cout<<"You have booked room: "<<roomNumber<<endl;
            databaseRoom[i].bookRoom();
            databaseRoom[i].checkIn();
            showRoom(databaseRoom);
        }
    }
    
    string name;
    string phoneNumber;
    string address;
    
    cout<<"\nEnter name: ";
    cin>>name;cin.ignore();

    cout<<"Enter phone number: ";
    cin>>phoneNumber;cin.ignore();

    cout<<"Enter address: ";
    cin>>address; cin.ignore();

    int day = 0;
    int month = 0;
    int year = 0;

    cout<<"Enter day: ";   cin>>day;    cin.ignore();
    cout<<"Enter month: "; cin>>month;  cin.ignore();
    cout<<"Enter year: ";  cin>>year;   cin.ignore();

    int hour = 0; 
    int minute = 0; 
    int second = 0;

    cout<<"Enter hour: ";   cin>>hour;     cin.ignore();
    cout<<"Enter minute: "; cin>>minute;   cin.ignore();
    cout<<"Enter second: "; cin>>second;   cin.ignore();

    Customer customer(name, phoneNumber, address, (uint8_t)roomNumber);

    inOutHistory inOutDetails;

    inOutDetails.date = {day, month, year};
    inOutDetails.time = {hour, minute, second};

    customer.addInOutHistory(inOutDetails);
    databaseCustomers.push_back(customer);
}

/*
* Function: changeRoom()
* Description: This function is used to change a room
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   returns the room changed
*/
void changeRoom(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers){
    int newIdRoom;
    int idRoomCurrent;
    cout<<"Enter idRoom need to change: ";
    cin>>idRoomCurrent; cin.ignore();
    cout<<"\nEnter new idRoom: ";
    cin>>newIdRoom;

    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoomCurrent)  databaseCustomers[i].setIdRoom(newIdRoom);
    }

    for(int i = 0; i < databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber() == idRoomCurrent){
            databaseRoom[i].checkOut();
        }
        if(databaseRoom[i].getRoomNumber() == newIdRoom && databaseRoom[i].isAvailable()== true){
            databaseRoom[i].bookRoom();
            databaseRoom[i].checkIn();
            cout<<"You have successfully changed into the room number: "<<newIdRoom<<endl;
            showRoom(databaseRoom);
        }
    }
}

/*
* Function: returnRoom()
* Description: This function is used to check out room
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
* Output:
*  
*/
void returnRoom(vector<Room>&databaseRoom){
   int roomNumber;

    do{
        cout<<"Please select room to check out: ";
        cin>>roomNumber;
    }
    while(roomNumber<= 0 && roomNumber > databaseRoom[databaseRoom.size()].getRoomNumber());
    for(int i=0; i<databaseRoom.size(); i++){
        if(databaseRoom[i].getRoomNumber() == roomNumber && databaseRoom[i].isAvailable()== false){
            cout<<"You have chosen room: "<<roomNumber<<endl;
            databaseRoom[i].checkOut();
            showRoom(databaseRoom);
        }
    }
}

/*
* Function: customersManagement()
* Description: This function is used to perform "CUSTOMER MANAGEMENT" program.
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   
*/
int customersManagement(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers){
    while(true){
        cout<<"*********************************"<<endl;
        cout<<"*  CUSTOMER MANAGEMENT PROGRAM  *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        cout<<"*    1. ADD CUSTOMER            *"<<endl;
        cout<<"*    2. EDIT CUSTOMER           *"<<endl;
        cout<<"*    3. DELETE CUSTOMER         *"<<endl;
        cout<<"*    4. DISPLAY CUSTOMER        *"<<endl;
        cout<<"*    0. EXIT                    *"<<endl;
        cout<<"*********************************"<<endl;
        int chose;
        cout<<"Please choose the program.....";
        cin>>chose;

        switch(chose) {
            case ADD_CUSTOMER:
                displayCustomer(databaseCustomers);
                addCustomer(databaseCustomers);
                pressAnyKey();
                break;
            case EDIT_CUSTOMER:
                editCustomer(databaseRoom, databaseCustomers);
                pressAnyKey();
                break;
            case DELETE_CUSTOMER:
                displayCustomer(databaseCustomers);
                deleteCustomer(databaseCustomers);
                pressAnyKey();
                break;
            case DISPLAY_CUSTOMER:
                displayCustomer(databaseCustomers);
                pressAnyKey();
                break;
            case EXIT_CUSTOMER_MANAGEMENT:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }
}

/*
* Function: addCustomer()
* Description: This function is used to add a customer to the database of customers.
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   Add a customer to the database of customers.
*/
void addCustomer(vector<Customer>&databaseCustomers){
    int idRoom;
    string name;
    string phoneNumber;
    string address;

    cout<<"Enter idRoom: ";
    cin>>idRoom; cin.ignore();

    cout<<"Enter name: ";
    cin>>name; cin.ignore();

    cout<<"Enter phone number: ";
    cin>>phoneNumber;cin.ignore();

    cout<<"Enter address: ";
    cin>>address; cin.ignore();

    int day = 0;
    int month = 0;
    int year = 0;

    cout<<"Enter day: ";   cin>>day;    cin.ignore();
    cout<<"Enter month: "; cin>>month;  cin.ignore();
    cout<<"Enter year: ";  cin>>year;   cin.ignore();

    int hour = 0; 
    int minute = 0; 
    int second = 0;

    cout<<"Enter hour: ";   cin>>hour;     cin.ignore();
    cout<<"Enter minute: "; cin>>minute;   cin.ignore();
    cout<<"Enter second: "; cin>>second;   cin.ignore();

    Customer customer(name, phoneNumber, address, (uint8_t)idRoom);

    inOutHistory inOutDetails;

    inOutDetails.date = {day, month, year};
    inOutDetails.time = {hour, minute, second};

    customer.addInOutHistory(inOutDetails);
    databaseCustomers.push_back(customer);
}

/*
* Function: editCustomer()
* Description: This function is used to perform "EDIT CUSTOMER" program
* Input:
*   vector<Room> : A vector to contain rooms database that have type data Room
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   
*/
int editCustomer(vector<Room>&databaseRoom, vector<Customer>&databaseCustomers){
    while(true){
       
        cout<<"*-------------------------------*"<<endl;
        cout<<"*    1. EDIT NAME               *"<<endl;
        cout<<"*    2. EDIT NO.ROOM            *"<<endl;
        cout<<"*    3. EDIT ADDRESS            *"<<endl;
        cout<<"*    4. EDIT PHONE NUMBER       *"<<endl;
        cout<<"*    0. EXIT                    *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        int chose;
        int idRoomCurren;
        cout<<"Please choose the program.....";
        cin>>chose; 

        switch(chose) {
            case EDIT_NAME:
                displayCustomer(databaseCustomers);
                cout<<"Enter idRoom: ";
                cin>>idRoomCurren; 
                editName(databaseCustomers, idRoomCurren);
                pressAnyKey();
                break;
            case EDIT_ROOM:
                displayCustomer(databaseCustomers);
                cout<<"Enter idRoom: ";
                cin>>idRoomCurren;
                editIdRoom(databaseCustomers, idRoomCurren);
                pressAnyKey();
                break;
            case EDIT_ADDRESS:
                displayCustomer(databaseCustomers);
                cout<<"Enter idRoom: ";
                cin>>idRoomCurren; 
                editAddress(databaseCustomers, idRoomCurren);
                pressAnyKey();
                break;
            case EDIT_PHONE:
                displayCustomer(databaseCustomers);
                cout<<"Enter idRoom: ";
                cin>>idRoomCurren;
                editPhone(databaseCustomers, idRoomCurren);
                pressAnyKey();
                break;
            case EXIT_EDIT:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }
}

/*
* Function: editName()
* Description: This function is used to edit name of customer
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
*   uint8_t idRoomCurrent: room number of customer
* Output:
*   
*/
void editName(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent){
    string newName;
    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoomCurrent){
            cout<<"Enter new name of customer: ";
            cin>>newName;
            databaseCustomers[i].setName(newName);
            cout<<"You have successfully changed the customer name"<<endl;
            break; 
        }
    }
}

/*
* Function: editIdRoom()
* Description: This function is used to edit the room number
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
*   uint8_t idRoomCurrent: room number of customer
* Output:
*   
*/
void editIdRoom(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent){
    int newIdRoom;
    cout<<"Enter new idRoom: ";
    cin>>newIdRoom;

    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoomCurrent)  databaseCustomers[i].setIdRoom(newIdRoom);
        cout<<"You have successfully changed the room number"<<endl;
        break;
    }       
}

/*
* Function: editAddress()
* Description: This function is used to edit address of customer
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
*   uint8_t idRoomCurrent: room number of customer
* Output:
*   
*/
void editAddress(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent){
    string newAddress;
    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoomCurrent){
            cout<<"Enter new address of customer: ";
            cin>>newAddress;
            databaseCustomers[i].setAddress(newAddress);
            cout<<"You have successfully changed the customer address"<<endl;
            break; 
        }
    }
}

/*
* Function: editPhone()
* Description: This function is used to edit phone number of customer
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
*   uint8_t idRoomCurrent: room number of customer
* Output:
*   
*/
void editPhone(vector<Customer>&databaseCustomers, uint8_t idRoomCurrent){
    string newPhone;
    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoomCurrent){
            cout<<"Enter new phone number of customer: ";
            cin>>newPhone;
            databaseCustomers[i].setPhoneNumber(newPhone);
            cout<<"You have successfully changed the customer phone number"<<endl;
            break; 
        }
    }
}

/*
* Function: deleteCustomer()
* Description: This function is used to delete a customer
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   
*/
int deleteCustomer(vector<Customer>&databaseCustomers){
    int idRoom;
    cout<<"Enter idRoom to delete: ";
    cin>>idRoom;

    for(int i = 0; i < databaseCustomers.size(); i++){
        if(databaseCustomers[i].getIdRoom() == idRoom) {
        databaseCustomers.erase(databaseCustomers.begin()+i);
        cout<<"IdRoom has been removed!"<<endl;
        return 1;
        }
    }
    cout<<"IdRoom has not been found!"<<endl;
    return 0;
}

/*
* Function: displayCustomer()
* Description: This function is used to printf list of customer
* Input:
*   vector<Customer>: A vector to contain customers database that have type data Customer
* Output:
*   
*/
void displayCustomer(vector<Customer>&databaseCustomers){
    cout<<"Information of customer\n|\tIdRoom\t|\tName\t|\tPhoneNumber\t|\tAddress\t\t|\n";
    for(int i=0; i<databaseCustomers.size(); i++){
        printf("|\t%d\t|", databaseCustomers[i].getIdRoom());
        cout<<"\t"<<databaseCustomers[i].getName()<<"\t|";
        cout<<"\t"<<databaseCustomers[i].getPhoneNumber()<<"\t|";
        cout<<"\t"<<databaseCustomers[i].getAddress()<<"\t|\n";
    }
}

/*
* Function: employeesManagement()
* Description: This function is used to perform "EMPLOYEE MANAGEMENT" program
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
int employeesManagement(employeeManager &databaseEmployeeManagement, securityManager &databaseSecurityManagement){
    cout<<"\n1. Manager\n2. Employee\n0. Exit\nEnter chose: ";
    int key; cin>>key;

    if(key ==1){
        bool checkAuthenticate = false;
        string userName;
        string password;

        cout<<"Enter userName: "; cin>>userName;
        cout<<"Enter password: "; cin>>password;

        checkAuthenticate = databaseEmployeeManagement.getAuthenticate(userName, password);

        if(checkAuthenticate == false) {
            cout<<"Entered information is not valid!";
            return 0;}
        while(true){
            cout<<"*********************************"<<endl;
            cout<<"*  EMPLOYEE MANAGEMENT PROGRAM  *"<<endl;
            cout<<"*-------------------------------*"<<endl;
            cout<<"*    1. ADD EMPLOYEE            *"<<endl;
            cout<<"*    2. EDIT EMPLOYEE           *"<<endl;
            cout<<"*    3. DELETE EMPLOYEE         *"<<endl;
            cout<<"*    4. DISPLAY EMPLOYEE        *"<<endl;
            cout<<"*    0. EXIT                    *"<<endl;
            cout<<"*********************************"<<endl;
            int chose;
            cout<<"Please choose the program.....";
            cin>>chose;

            switch(chose) {
                case ADD_EMPLOYEE:
                    displayEmployee(databaseEmployeeManagement);
                    addEmployee(databaseEmployeeManagement);
                    pressAnyKey();
                    break;
                case EDIT_EMPLOYEE:
                    editEmployee(databaseEmployeeManagement);
                    pressAnyKey();
                    break;
                case DELETE_EMPLOYEE:
                    displayEmployee(databaseEmployeeManagement);
                    deleteEmployee(databaseEmployeeManagement);
                    pressAnyKey();
                    break;
                case DISPLAY_EMPLOYEE:
                    displayEmployee(databaseEmployeeManagement);
                    pressAnyKey();
                    break;
                case EXIT_EMPLOYEE_MANAGEMENT:
                    cout << "You have chosen to exit the program!\n";
                    return 0;
                default:
                    cout << "This function is not available!\n";
                    cout << "\nPlease select the function in the menu box.\n";
                    pressAnyKey();
                    break;
            }

        }
    }
    else if(key == 2){
        string userName;
        string password;
        int check = 0;
        cout<<"Enter userName: "; cin>>userName;
        cout<<"Enter password: "; cin>>password;

        for(int i=0; i<databaseSecurityManagement.getDatabaseUsers().size(); i++) {
            if(databaseSecurityManagement.getDatabaseUsers()[i].getUsername() == userName) {
                check++;
                if(databaseSecurityManagement.getDatabaseUsers()[i].getPassword() == password) break;
                else{
                    cout<<"Password is error!\n";
                    return 0;
                }
            }
        }
        if(check == 0) {
            cout<<"UserName is error\n";
            return 0;
            }
        while(true){
            cout<<"---------------------"<<endl;
            cout<<"1. EDIT PHONE NUMBER "<<endl;
            cout<<"0. EXIT              "<<endl;
            cout<<"---------------------"<<endl;

            typedef enum{
                EXIT,
                EDIT_PHONE
            }AccessEmployee;

            int chose;
            cout<<"Please choose the program.....";
            cin>>chose;
            switch(chose) {
                case EDIT_PHONE:
                    displayEmployee(databaseEmployeeManagement);
                    editPhoneEmployee(databaseEmployeeManagement);
                    pressAnyKey();
                    break;
                case EXIT: 
                    cout << "You have chosen to exit the program!\n";
                    return 1;
                default: 
                    cout << "This function is not available!\n";
                    cout << "\nPlease select the function in the menu box.\n";
                    pressAnyKey();
                    break;
            }
        }
    }
    else return 0;
}

/*
* Function: addEmployee()
* Description: This function is used to add a employee to the database
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void addEmployee(employeeManager &databaseEmployeeManagement){
    
    string name;
    string phoneNumber;
    jobPosition position;

    cout<<"Enter name: ";
    cin>>name;

    cout<<"Enter phoneNumber: ";
    cin>>phoneNumber;

    int chose;
    cout<<"\n0. JANITOR\n1. RECEPTIONIST\n2. LAUNDRY_STAFF\n3. LUGGAGE_STAFF\n4. GARDENER\n";
    cin>>chose;
 
    switch(chose){
        case JANITOR:
            position = JANITOR;
            break;
        case RECEPTIONIST:
            position = RECEPTIONIST;
            break;
        case LAUNDRY_STAFF:
            position = LAUNDRY_STAFF;
            break;
        case LUGGAGE_STAFF:
            position = LUGGAGE_STAFF;
            break;
        case GARDENER:
            position = GARDENER;
            break;
    }

    int day = 0;
    int month = 0;
    int year = 0;

    cout<<"Enter day: ";   cin>>day;    cin.ignore();
    cout<<"Enter month: "; cin>>month;  cin.ignore();
    cout<<"Enter year: ";  cin>>year;   cin.ignore();

    int hour = 0; 
    int minute = 0; 
    int second = 0;

    cout<<"Enter hour: ";   cin>>hour;     cin.ignore();
    cout<<"Enter minute: "; cin>>minute;   cin.ignore();
    cout<<"Enter second: "; cin>>second;   cin.ignore();

    Schedule schedule ;

    schedule.date = {day, month, year};
    schedule.time = {hour, minute, second};

    Employee employee = {name, phoneNumber, position, schedule};
    databaseEmployeeManagement.addEmployees(employee);

}

/*
* Function: editEmployee()
* Description: This function is used to perform "EDIT EMPLOYEE" program.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
int editEmployee(employeeManager &databaseEmployeeManagement){
    while(true){
       
        cout<<"*-------------------------------*"<<endl;
        cout<<"* 1. EDIT EMPLOYEE NAME         *"<<endl;
        cout<<"* 2. EDIT EMPLOYEE PHONE NUMBER *"<<endl;
        cout<<"* 3. EDIT EMPLOYEE POSITION     *"<<endl;
        cout<<"* 4. EDIT EMPLOYEE SCHEDULE     *"<<endl;
        cout<<"* 0. EXIT                       *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        int chose;
        cout<<"Please choose the program.....";
        cin>>chose; 

        switch(chose) {
            case EDIT_EMPLOYEE_NAME:
                displayEmployee(databaseEmployeeManagement);
                editNameEmployee(databaseEmployeeManagement);
                pressAnyKey();
                break;
            case EDIT_EMPLOYEE_PHONE:
                displayEmployee(databaseEmployeeManagement);
                editPhoneEmployee(databaseEmployeeManagement);
                pressAnyKey();
                break;
            case EDIT_EMPLOYEE_POSITION:
                displayEmployee(databaseEmployeeManagement);
                editPositionEmployee(databaseEmployeeManagement);
                pressAnyKey();
                break;
            case EDIT_EMPLOYEE_SCHEDULE:
                displayEmployee(databaseEmployeeManagement);
                editScheduleEmployee(databaseEmployeeManagement);
                pressAnyKey();
                break;
            case EXIT_EDIT_EMPLOYEE:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }

}

/*
* Function: editNameEmployee()
* Description: This function is used to edit name of employees.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void editNameEmployee(employeeManager &databaseEmployeeManagement){
    int idEmployee;
    string newName;
    cout<<"Enter idEmployee: ";
    cin>>idEmployee;

    for(int i = 0; i < databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        if(databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee()==idEmployee){
            cout<<"Enter new name of employee: ";
            cin>>newName;
            databaseEmployeeManagement.getDatabaseEmployees()[i].setName(newName);
            cout<<"You have successfully changed the customer name"<<endl;
            break; 
        }
    }
}

/*
* Function: editPhoneEmployee()
* Description: This function is used to edit phone number of employees.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void editPhoneEmployee(employeeManager &databaseEmployeeManagement){
    int idEmployee;
    string newPhone;
    cout<<"Enter idEmployee: ";
    cin>>idEmployee;

    for(int i = 0; i < databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        if(databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee()==idEmployee){
            cout<<"Enter new phone number of employee: ";
            cin>>newPhone;
            databaseEmployeeManagement.getDatabaseEmployees()[i].setPhoneNumber(newPhone);
            cout<<"You have successfully changed the phone number"<<endl;
            break; 
        }
    }
}

/*
* Function: editPositionEmployee()
* Description: This function is used to edit job position of employees.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void editPositionEmployee(employeeManager &databaseEmployeeManagement){
    int idEmployee;
    jobPosition newPosition;
    cout<<"Enter idEmployee: ";
    cin>>idEmployee;

    for(int i = 0; i < databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        if(databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee()==idEmployee){
            cout<<"Enter new position of employee\n";
            int chose;
            cout<<"\n0. JANITOR\n1. RECEPTIONIST\n2. LAUNDRY_STAFF\n3. LUGGAGE_STAFF\n4. GARDENER\n";
            cin>>chose;
        
            switch(chose){
                case JANITOR:
                    newPosition = JANITOR;
                    break;
                case RECEPTIONIST:
                    newPosition = RECEPTIONIST;
                    break;
                case LAUNDRY_STAFF:
                    newPosition = LAUNDRY_STAFF;
                    break;
                case LUGGAGE_STAFF:
                    newPosition = LUGGAGE_STAFF;
                    break;
                case GARDENER:
                    newPosition = GARDENER;
                    break;
            }
            databaseEmployeeManagement.getDatabaseEmployees()[i].setPosition(newPosition);
            cout<<"You have successfully changed position"<<endl;
            break; 
        }
    }
}

/*
* Function: editScheduleEmployee()
* Description: This function is used to edit schedule of employees.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void editScheduleEmployee(employeeManager &databaseEmployeeManagement){
    int idEmployee;
    Schedule newSchedule;
    cout<<"Enter idEmployee: ";
    cin>>idEmployee;

    for(int i = 0; i < databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        if(databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee()==idEmployee){
            cout<<"Enter new schedule of employee\n";
            uint8_t day = 0;
            uint8_t month = 0;
            uint16_t year = 0;

            cout<<"Enter day: ";   cin>>day;    cin.ignore();
            cout<<"Enter month: "; cin>>month;  cin.ignore();
            cout<<"Enter year: ";  cin>>year;   cin.ignore();

            uint8_t hour = 0; 
            uint8_t minute = 0; 
            uint8_t second = 0;

            cout<<"Enter hour: ";   cin>>hour;     cin.ignore();
            cout<<"Enter minute: "; cin>>minute;   cin.ignore();
            cout<<"Enter second: "; cin>>second;   cin.ignore();

            newSchedule.date = {day, month, year};
            newSchedule.time = {hour, minute, second};
            databaseEmployeeManagement.getDatabaseEmployees()[i].setSchedule(newSchedule);
            cout<<"You have successfully changed the phone number"<<endl;
            break; 
        }
    }
}

/*
* Function: deleteEmployee()
* Description: This function is used to delete a employee.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   Printf the result of deleting employee
*/
int deleteEmployee(employeeManager &databaseEmployeeManagement){
    int idEmployee;
    cout<<"Enter idEmployee to delete: ";
    cin>>idEmployee;

    for(int i = 0; i < databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        if(databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee() == idEmployee){
        databaseEmployeeManagement.getDatabaseEmployees().erase(databaseEmployeeManagement.getDatabaseEmployees().begin()+i);
        cout<<"idEmployee has been removed!"<<endl;
        return 1;
        }
    }
    cout<<"idEmployee has not been found!"<<endl;
    return 0;
}

/*
* Function: displayEmployee()
* Description: This function is used to printf employees in the database.
* Input:
*   employeeManager &databaseEmployeeManagement: input parameter is a class that have type data of employeeManager
* Output:
*   
*/
void displayEmployee(employeeManager &databaseEmployeeManagement){
    cout<<"Information of employee\n|\tIdEmployee\t|\tName\t|\tPhoneNumber\t|\tPosition\t|\tSchedule\t\t|\n";
    for(int i=0; i<databaseEmployeeManagement.getDatabaseEmployees().size(); i++){
        printf("|\t%d\t\t|", databaseEmployeeManagement.getDatabaseEmployees()[i].getIdEmployee());
        cout<<"\t"<<databaseEmployeeManagement.getDatabaseEmployees()[i].getName()<<"\t|";
        cout<<"\t"<<databaseEmployeeManagement.getDatabaseEmployees()[i].getPhoneNumber()<<"\t|";
        cout<<"\t"<<databaseEmployeeManagement.getDatabaseEmployees()[i].getPosition()<<"\t\t|";
        printf("\t%d.%d.%d %d:%d:%d\t|\n", databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().date.day,
                databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().date.month,
                databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().date.year,
                databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().time.hour,
                databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().time.minute,
                databaseEmployeeManagement.getDatabaseEmployees()[i].getSchedule().time.second);
    }
}

/*
* Function: securityManagement()
* Description: This function is used to perform "SECURITY MANAGEMENT" program
* Input:
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
int securityManagement(securityManager &databaseSecurityManagement){
    bool checkSignup = false;
    string userName;
    string password;

    cout<<"Enter userName: "; cin>>userName;
    cout<<"Enter password: "; cin>>password;

    checkSignup = databaseSecurityManagement.getCheckSignup(userName, password);

    if(checkSignup == false) {
        cout<<"Entered information is not valid!";
        return 0;}
    while(true){
        cout<<"*********************************"<<endl;
        cout<<"*  SECURITY MANAGEMENT PROGRAM  *"<<endl;
        cout<<"*-------------------------------*"<<endl;
        cout<<"*    1. ADD USER                *"<<endl;
        cout<<"*    2. EDIT USER               *"<<endl;
        cout<<"*    3. EDIT MANAGER PASSWORD   *"<<endl;
        cout<<"*    4. DELETE USER             *"<<endl;
        cout<<"*    0. EXIT                    *"<<endl;
        cout<<"*********************************"<<endl;
        int chose;
        cout<<"Please choose the program.....";
        cin>>chose;

        switch(chose) {
            case ADD_USER:
                addUser(databaseSecurityManagement);
                pressAnyKey();
                break;
            case EDIT_USER:
                editUser(databaseSecurityManagement);
                pressAnyKey();
                break;
            case EDIT_MANAGER_PASSWORD:
                editPasswordManager(databaseSecurityManagement);
                pressAnyKey();
                break;
            case DELETE_USER:
                deleteUser(databaseSecurityManagement);
                pressAnyKey();
                break;
            case EXIT_SECURITY_MANAGEMENT:
                cout << "You have chosen to exit the program!\n";
                return 0;
            default:
                cout << "This function is not available!\n";
                cout << "\nPlease select the function in the menu box.\n";
                pressAnyKey();
                break;
        }

    }
}

/*
* Function: addUser()
* Description: This function is used to add user to the list
* Input:
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
void addUser(securityManager &databaseSecurityManagement){
    string userName;
    string password;

    cout<<"Enter userName: "; cin>>userName;
    cout<<"Enter password: "; cin>>password;

    databaseSecurityManagement.addUser(userName, password);
    cout<<"Add user successfully";
}

/*
* Function: editUser()
* Description: This function is used to edit user to the list
* Input:
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
void editUser(securityManager &databaseSecurityManagement){
    string NewUserName;
    string NewPassword;
    string userName;
    
    cout<<"Enter userName of user need to change: ";
    cin>>userName;

    cout<<"Enter new userName: "; cin>>NewUserName;
    cout<<"Enter new password: "; cin>>NewPassword;

    for(int i=0; i<databaseSecurityManagement.getDatabaseUsers().size(); i++){
        if(databaseSecurityManagement.getDatabaseUsers()[i].getUsername()==userName){
            databaseSecurityManagement.editUser(NewUserName, NewPassword);
            cout<<"User changed successfully";
            break;
        }
    }     
}

/*
* Function: editPasswordManager()
* Description: This function is used to edit password of manager
* Input:
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
void editPasswordManager(securityManager &databaseSecurityManagement){
    string password;
    string passwordAgain;

    while(true){
    cout<<"Enter new password: "; cin>>password;
    cout<<"Enter new password again: "; cin>>passwordAgain;
    if(password != passwordAgain) cout<<"Password again incorrect, please enter again!";
    else break;
    }
    databaseSecurityManagement.setPasswordManager(password);
    cout<<"Password changed successfully";

}

/*
* Function: deleteUser()
* Description: This function is used to delete user to the list
* Input:
*   securityManager &databaseSecurityManagement: input parameter is a class that have type data of securityManager
* Output:
*   
*/
void deleteUser(securityManager &databaseSecurityManagement){
    string userName;
    
    cout<<"Enter userName to delete: ";
    cin>>userName;

    bool result = databaseSecurityManagement.eraseUser(userName);
    if(result != true) cout<<"Error deleting user";
    else cout<<"User deleted successfully";
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

