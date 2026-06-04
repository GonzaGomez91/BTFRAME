#pragma once
#include "Motor.h"

/*
    DriveController
    ----------------
    Módulo encargado de controlar la locomoción del frame.

    Responsabilidades:
    - Coordinar ambos motores del sistema diferencial.
    - Convertir velocidad lineal y angular en velocidades
      individuales para cada motor.
    - Aplicar trims/calibraciones para compensar diferencias
      mecánicas entre motores.

    Este módulo NO controla hardware directamente.
    Toda la interacción física con el puente H y los pines
    es responsabilidad de la clase Motor.

    Funcionamiento:
    - linearSpeed:
        Controla avance y retroceso.
        Valores positivos avanzan.
        Valores negativos retroceden.

    - angularSpeed:
        Controla rotación.
        Valores positivos giran a la derecha.
        Valores negativos giran a la izquierda.

    El método update() calcula las velocidades finales
    de cada motor utilizando mezcla diferencial:

        leftSpeed  = linearSpeed - angularSpeed
        rightSpeed = linearSpeed + angularSpeed

    Luego aplica trims y actualiza los motores.

    Ejemplo de uso:

        drive.setLinearSpeed(150);
        drive.setAngularSpeed(0);
        drive.update();

    Resultado:
        El frame avanza recto.

*/

 
class DriveController
{
private:
    Motor& leftMotor;
    Motor& rightMotor;

    int linearSpeed; // Speed in the forward/backward direction
    int angularSpeed; // Speed for turning (positive for right, negative for left)
    float leftTrim; // Trim value for left motor
    float rightTrim; // Trim value for right motor
    
    int applyTrim(int speed, float trim);
    
public:
    DriveController(Motor& leftMotor, Motor& rightMotor); //Constructor
    
    void setLinearSpeed(int speed);
    void setAngularSpeed(int speed);

    void stop();

    void setTrim(float leftTrim, float rightTrim);


    void update();
};

