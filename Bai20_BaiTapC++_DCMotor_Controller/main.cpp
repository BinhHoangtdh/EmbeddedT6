#include<iostream>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

typedef enum{
    CLOCKWISE,
    COUNTERCLOCKWISE
}typeDirection;

class DCMotor{
    private:
        float voltage;
        float current_max;
        float speed;
        typeDirection direction;
        bool isRunning = false;
    public:
        void setSpeed(float Speed){
            speed = Speed;
        }
        void setDirection(typeDirection Direction){
            direction = Direction;
        }
        void start(){
            if(isRunning == false) {
                setVoltage(110);
                isRunning = true;
            }
        }
        void stop(){
            if(isRunning == true) {
                setVoltage(0);
                isRunning = false;
                }
        }
        void setVoltage(float Voltage){
            voltage = Voltage;
        }
        void setCurrent(float Current){
            current_max = Current;
        }
        float getCurrent(){
            return current_max;
        }
};

class FeedbackSystem{
    private:
        float temperature;
        DCMotor motor;
    public:
        bool overloadDetected(){
            if( motor.getCurrent() > 5) {
                cerr<<"\nAlarm: Motor overloading";
                return true;
            }
            return false;
        }
        bool overheatDetected(){
            if( temperature > 45) {
                cerr<<"\nAlarm: Motor overheating";
                return true;
            }
            return false;
        }
        void setTemperature(float Temperature){
            temperature = Temperature;
        }
         DCMotor& getDCMotor(){
            return motor;
        }
};

class DCMotorController{
    private:
        FeedbackSystem feedback;
    public:
        void controlStopError(){
            if(feedback.overloadDetected()==true || feedback.overheatDetected()==true){
                feedback.getDCMotor().stop();
            }
        }
        void controlStop(){
            feedback.getDCMotor().stop();
        }
        void controlStar(){
            feedback.getDCMotor().start();
        }
        void controlDirection(typeDirection direction){
            feedback.getDCMotor().setDirection(direction);
        }
        void controlSpeed(float speed){
            feedback.getDCMotor().setSpeed(speed);
        }
        FeedbackSystem& getFeedbackSystem(){
            return feedback;
        }
};

int main(int argc, char** argv){
    DCMotorController controller;
    float speed;
    typeDirection direction;
    float temperature;
    float current;

    cout<<"Enter speed of motor: ";
    cin>>speed;

    cout<<"Enter direction of motor: ";
    scanf("%d", &direction);

    cout<<"Enter temperature read from sensor: ";
    cin>> temperature;
    controller.getFeedbackSystem().setTemperature(temperature);

    cout<<"Enter current read from sensor: ";
    cin>> current;
    controller.getFeedbackSystem().getDCMotor().setCurrent(current);


    controller.controlDirection(direction);
    controller.controlSpeed(speed);

    controller.controlStar();
    controller.controlStopError();
    controller.controlStop();

    return 0;
}