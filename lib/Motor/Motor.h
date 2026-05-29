#pragma once

class Motor
{
private:
    /* data */
    const char* const id;
    const int in1;
    const int in2;
    const int en;
    int velocidad;

public:
    Motor(const char* idMotor, int pin1, int pin2, int pinPWM); //Constructor

    void avanzar(int nuevaVelocidad);

    void detenerse();

    void mostrarEstado();
};



