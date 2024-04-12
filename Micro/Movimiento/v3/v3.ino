#include "PCF8574.h"
#include "Arduino.h"

PCF8574 mov(0x21);
int infr_centro;//p1
int infr_derecha;//p2
int infr_izquierda;//p0

void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  mov.pinMode(P0, INPUT_PULLUP);// infrarrojo centra
  mov.pinMode(P1, INPUT_PULLUP);// infrarrojo derecho
  mov.pinMode(P2, INPUT_PULLUP);// infrarrojo izquierdo
  mov.pinMode(P3, OUTPUT);//IN1
  mov.pinMode(P4, OUTPUT);//IN2
  mov.pinMode(P5, OUTPUT);//IN3
  mov.pinMode(P6, OUTPUT);//IN4
  if (mov.begin()) {
    Serial.println("TODO OK");
  } else {
    Serial.println("ERROR");
  }
}

void loop() {
  analogWrite(15, 767);
  infr_centro = mov.digitalRead(P1);
  infr_derecha = mov.digitalRead(P2);
  infr_izquierda = mov.digitalRead(P0);
  if(infr_izquierda == HIGH and infr_centro == LOW and infr_derecha == HIGH){
    Avanzar();
  }else if(infr_izquierda == LOW  and infr_centro == HIGH and infr_derecha == HIGH){
    Izquierda();
  }else if(infr_izquierda == LOW  and infr_centro == LOW and infr_derecha == HIGH){
    Izquierda();
  }else if(infr_izquierda == HIGH and infr_centro == LOW and infr_derecha == LOW){
    Derecha();
  }else if(infr_izquierda == HIGH and infr_centro == HIGH and infr_derecha == LOW){
    Derecha();
  }
  else{
    Detenerse();
  }
  delay(10);
}
void Avanzar(){
  Serial.println("Dentro de pista");
  mov.digitalWrite(P3,LOW);
  mov.digitalWrite(P4,HIGH);
  mov.digitalWrite(P5,LOW);
  mov.digitalWrite(P6,HIGH);
}
void Izquierda(){
  Serial.println("girar a la izquierda");
  mov.digitalWrite(P3,HIGH);
  mov.digitalWrite(P4,LOW);
  mov.digitalWrite(P5,LOW);
  mov.digitalWrite(P6,HIGH);
}
void Derecha(){
  Serial.println("girar a la derecha");
  mov.digitalWrite(P3,LOW);
  mov.digitalWrite(P4,HIGH);
  mov.digitalWrite(P5,HIGH);
  mov.digitalWrite(P6,LOW);
}
void Detenerse(){
  Serial.println("se detiene");
  mov.digitalWrite(P3,LOW);
  mov.digitalWrite(P4,LOW);
  mov.digitalWrite(P5,LOW);
  mov.digitalWrite(P6,LOW);
}
