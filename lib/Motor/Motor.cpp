#include <Arduino.h>
#include "Motor.h"


Motor::Motor(const char *idMotor, int pin1, int pin2, int pinPWM)
    : id(idMotor),
      in1(pin1),
      in2(pin2),
      en(pinPWM),

      velocidad(0)
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(en, OUTPUT);
}

void Motor::avanzar(int nuevaVelocidad)
{
    velocidad = nuevaVelocidad;
    analogWrite(en, velocidad);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void Motor::detenerse()
{
    analogWrite(en, 0);
}

void Motor::mostrarEstado()
{

    Serial.print("Motor: ");
    Serial.println(id);
    Serial.print("In1: ");
    Serial.print(in1);
    Serial.print(", In2: ");
    Serial.println(in2);
    Serial.print("Velocidad: ");
    Serial.println(velocidad);
}