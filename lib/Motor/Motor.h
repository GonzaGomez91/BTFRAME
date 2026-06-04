#pragma once
#define MOTOR_DEBUG 1


class Motor
{
private:
    const char* const id;
    const int in1;
    const int in2;
    const int en;
    
    int speed;
    
    void update();

public:
    
    Motor(const char* idMotor, int pin1, int pin2, int pinPWM); //Constructor

    void setSpeed(int newSpeed);
    
    void stop();
    
    void printStatus();
};



