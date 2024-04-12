
#include "Arduino.h"
#include "PCF8574.h"

PCF8574 mov(0x21);
int infr_1;//infrarrojo 1
int infr_2;//infrarrojo 2
int infr_3;//infrarrojo 2
void setup()
{
  Serial.begin(115200);
  delay(1000);
  // Set pinMode to OUTPUT
  mov.pinMode(P0, INPUT_PULLUP);// infrarrojo centra
  mov.pinMode(P1, INPUT_PULLUP);// infrarrojo derecho
  mov.pinMode(P2, INPUT_PULLUP);// infrarrojo izquierdo
  mov.pinMode(P3, OUTPUT);//IN1
  mov.pinMode(P4, OUTPUT);//IN2
  mov.pinMode(P5, OUTPUT);//IN3
  mov.pinMode(P6, OUTPUT);//IN4
  pinMode(15, OUTPUT);
  Serial.print("Detectando pcf8574...");
  if (mov.begin()) {
    Serial.println("TODO OK");
  } else {
    Serial.println("ERROR");
  }
}
void loop()
{
  if (mov.digitalRead(P0) == LOW) {
     infr_1 = 1;
  }else{
    infr_1 = 0;
  }
  if (mov.digitalRead(P1) == LOW){
    infr_2 = 1;
  }
  else{
    infr_2 = 0;
  }
  if (mov.digitalRead(P2) == LOW){
    infr_3 = 0;
  }
  else{
    infr_3 = 1;
  }
  analogWrite(15, 150);
  if(infr_1 == 0 and infr_2 == 0 and infr_3 == 0){
    Serial.println("Fuera de pista");  
    mov.digitalWrite(P3,LOW);
    mov.digitalWrite(P4,LOW);
    mov.digitalWrite(P5,LOW);
    mov.digitalWrite(P6,LOW);
  }else if(infr_1 == 1 and infr_2 == 0 and infr_3 == 0){
    Serial.println("Dentro de pista");
    mov.digitalWrite(P3,LOW);
    mov.digitalWrite(P4,HIGH);
    mov.digitalWrite(P5,LOW);
    mov.digitalWrite(P6,HIGH);
  }else if(infr_1 == 1 and infr_2 == 1 and infr_3 == 0){
    Serial.println("girar izquierda");
    mov.digitalWrite(P3,LOW);
    mov.digitalWrite(P4,HIGH);
    mov.digitalWrite(P5,LOW);
    mov.digitalWrite(P6,LOW);
  }else if(infr_1 == 1 and infr_2 == 0 and infr_3 == 1){
    Serial.println("girar derecha");
    mov.digitalWrite(P3,LOW);
    mov.digitalWrite(P4,LOW);
    mov.digitalWrite(P5,LOW);
    mov.digitalWrite(P6,HIGH);
  }
  delay(10);
}
