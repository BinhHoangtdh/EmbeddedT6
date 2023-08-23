#include<iostream>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

class Wheel{
    private:
        float speed;
    public:
        float getSpeed(){
            return speed;
        }
        void setSpeed(float Speed){
            speed = Speed;
        }
};

class Car{
    private:
        Wheel wheel;
        float weightCar = 1000;
    public:
        float getWeightCar(){
            return weightCar;
        }
        void setWeightCar(float weight_car){
            weightCar = weight_car;
        }
        void addWeightPassenger(float weight_passenger){
            weightCar += weight_passenger;
        }
        Wheel& getWheel(){
            return wheel;
        }
};

class ABS{
    private:
        Car car;
    public:
        void control_ABS(){
            if(car.getWheel().getSpeed() < 10.0){
                cerr<<"ABS system actived!";
            }
        }
        Car& getCar(){
            return car;
        }
};

int main(int argc, char** argv){
     ABS abs;
     float speed = 0.0;
     float weight_passenger = 0.0;

        cout<<"Enter weight of passenger: ";
        cin>>weight_passenger;
        abs.getCar().addWeightPassenger(weight_passenger);

        cout<<"Enter speed of car: ";
        cin>>speed;
        abs.getCar().getWheel().setSpeed(speed);

        abs.control_ABS();
    return 0;
}