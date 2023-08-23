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
        float getCurrent(){
            return current_max;
        }
};

class FeedbackSystem{
    private:
        float temperature = 45;
        DCMotor motor;
    public:
        bool overloadDetected(){
            if( motor.getCurrent() > 5) cerr<<"Alarm: Motor overloading";
            return true;
        }
        bool overheatDetected(){
            if( temperature > 45) cerr<<"Alarm: Motor overheating";
            return true;
        }
};

class DCMotorController{
    private:
        DCMotor motor;
        FeedbackSystem feedback;
    public:
        void controlStopError(){
            if(feedback.overloadDetected()==true || feedback.overheatDetected()==true){
                motor.stop();
            }
        }
        void controlStop(){
            motor.stop();
        }
        void controlStar(){
            if(feedback.overloadDetected()==false && feedback.overheatDetected()==false){
                motor.start();
            }
        }
        void controlDirection(typeDirection direction){
            motor.setDirection(direction);
        }
        void controlSpeed(float speed){
            motor.setSpeed(speed);
        }
};

int main(int argc, char** argv){
    DCMotorController controller;

    controller.controlDirection(CLOCKWISE);
    controller.controlSpeed(100);

    controller.controlStar();
    controller.controlStopError();
    controller.controlStop();

    return 0;
}