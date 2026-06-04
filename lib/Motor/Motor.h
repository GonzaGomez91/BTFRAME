#pragma once
#define MOTOR_DEBUG 1

/*
    Motor
    -----
    Módulo encargado de controlar un motor DC individual
    mediante un puente H.

    Responsabilidades:
    - Controlar dirección de giro.
    - Controlar velocidad mediante PWM.
    - Aplicar señales físicas a los pines del puente H.
    - Mantener el estado actual del motor.

    Este módulo representa una capa de bajo nivel.
    NO conoce conceptos de locomoción como:
    - avance del robot
    - giros
    - movimiento diferencial
    - navegación

    Esas responsabilidades pertenecen a módulos superiores
    como DriveController.

    Modelo de velocidad:
    La velocidad utiliza signo para representar
    dirección de giro:

        speed > 0
            Motor avanza.

        speed < 0
            Motor retrocede.

        speed = 0
            Motor detenido.

    El método setSpeed() actualiza el estado interno
    del motor y aplica inmediatamente los cambios
    al hardware mediante update().

    Funcionamiento interno:
    - El signo de speed determina la dirección.
    - El valor absoluto de speed determina el PWM.

    Ejemplo:

        motor.setSpeed(150);

    Resultado:
        El motor gira hacia adelante al ~59% de potencia.

    Ejemplo:

        motor.setSpeed(-255);

    Resultado:
        El motor gira hacia atrás a máxima velocidad.

*/

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
        
    void printStatus();
};



