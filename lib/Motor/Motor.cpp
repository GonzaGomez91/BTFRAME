#include <Arduino.h>
#include "Motor.h"


Motor::Motor(const char *idMotor, int pin1, int pin2, int pinPWM)
    : id(idMotor),
      in1(pin1),
      in2(pin2),
      en(pinPWM),
      speed(0)
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(en, OUTPUT);

    update();
}


void Motor::setSpeed(int newSpeed)
{
    speed = constrain(newSpeed, -255, 255);
    update();
}

void Motor::stop()
{
    setSpeed(0);
}

void Motor::update()
{
    int pwm = abs(speed);
    if (speed > 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(en, pwm);
    }
    else if (speed < 0) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        analogWrite(en, pwm);
    }

    else
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(en, 0);
    }
}
    



void Motor::printStatus()
{
    Serial.print("Motor: ");
    Serial.println(id);

    Serial.print("Speed: ");
    Serial.println(speed);

    Serial.print("Estado: ");

    if (speed > 0) {
        Serial.println("ADELANTE");
    }
    else if (speed < 0) {
        Serial.println("ATRAS");
    }
    else {
        Serial.println("DETENIDO");
    }
}
