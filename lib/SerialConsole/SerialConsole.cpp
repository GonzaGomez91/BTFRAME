#include <Arduino.h>
#include "SerialConsole.h"
#include "Motor.h"
#include "DriveController.h"

extern DriveController drive;
extern Motor motorIzquierdo;
extern Motor motorDerecho;

static void showHelp();
static void controlLeftMotor();
static void controlRightMotor();
static void controlBothMotors();
static void stopMotors();

void initSerialConsole() {
    Serial.println("BTFRAME iniciado");
    showHelp();

    motorIzquierdo.setSpeed(0);
    motorDerecho.setSpeed(0);
}

void processSerialCommands() {
    if (Serial.available() <= 0) {
        return;
    }

    char command = Serial.read();

    switch (command) {
        case 'f':{
            int speed = Serial.parseInt();
            drive.setLinearSpeed(speed);
            drive.setAngularSpeed(0);
            drive.update();
            break;
        }

        case 'b':{
            int speed = Serial.parseInt();
            drive.setLinearSpeed(-speed);
            drive.setAngularSpeed(0);
            drive.update();
            break;
        }

        case 'l':{
            int speed = Serial.parseInt();
            drive.setLinearSpeed(0);
            drive.setAngularSpeed(speed);
            drive.update();
            break;
        }

        case 'r':{
            int speed = Serial.parseInt();
            drive.setLinearSpeed(0);
            drive.setAngularSpeed(-speed);
            drive.update();
            break;
        }

        case 'c':{
            int linear = Serial.parseInt();
            int angular = Serial.parseInt();
            drive.setLinearSpeed(linear);
            drive.setAngularSpeed(angular);
            drive.update();
            break;
        }
        case 's':{
            drive.stop();
        }
            
        
        case 'i':
            controlLeftMotor();
            break;

        case 'd':
            controlRightMotor();
            break;

        case 'a':
            controlBothMotors();
            break;


        case 'e':
            motorIzquierdo.printStatus();
            motorDerecho.printStatus();
            break;

        case '\n':
        case '\r':
        case ' ':
            break;

        default:
            Serial.println("Comando no reconocido");
            showHelp();
            break;
    }
}

static void showHelp() {
    Serial.println("=== Comandos ===");
    Serial.println("i <speed>  -> motor izquierdo");
    Serial.println("d <speed>  -> motor derecho");
    Serial.println("a <speed>  -> ambos motores");
    Serial.println("s          -> detener ambos");
    Serial.println("e          -> estado motores");
}

static void controlLeftMotor() {
    int speed = Serial.parseInt();
    motorIzquierdo.setSpeed(speed);
    
}

static void controlRightMotor() {
    int speed = Serial.parseInt();
    motorDerecho.setSpeed(speed);
   
}

static void controlBothMotors() {
    int speed = Serial.parseInt();
    motorIzquierdo.setSpeed(speed);
    motorDerecho.setSpeed(speed);
  
}

static void stopMotors() {
    motorIzquierdo.setSpeed(0);
    motorDerecho.setSpeed(0);
    Serial.println("Motores detenidos");
}