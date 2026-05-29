#include <Arduino.h>
#include "Motor.h"

Motor motorIzquierdo("OrugaIzq",8,9,5);
Motor motorDerecho("OrugaDer",11,10,6);

void setup() {
  Serial.begin(9600);
  Serial.println("BT-01 iniciado desde PlatformIO");

  
  motorIzquierdo.avanzar(150);
  motorIzquierdo.mostrarEstado();
  delay(2000);
  motorIzquierdo.detenerse();
  
  motorDerecho.avanzar(150);
  motorDerecho.mostrarEstado();
  delay(2000);
  motorDerecho.detenerse();

  motorDerecho.avanzar(150);
  motorIzquierdo.avanzar(150);

  delay(5000);
  motorDerecho.detenerse();
  motorIzquierdo.detenerse();



}

void loop() {
}