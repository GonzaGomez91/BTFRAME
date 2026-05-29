#include <Arduino.h>
#include "Motor.h"
#include "SerialConsole.h"

Motor motorIzquierdo("OrugaIzq", 8, 9, 5);
Motor motorDerecho("OrugaDer", 11, 10, 6);

void setup() {
    Serial.begin(9600);
    initSerialConsole();
}

void loop() {
    processSerialCommands();
}