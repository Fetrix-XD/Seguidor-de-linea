/*
  miliohm.com test PCF8574 input
*/
#include "Arduino.h"
#include "PCF8574.h"
// Set i2c address
PCF8574 first(0x21);
int infr_1;
int infr_2;
void setup()
{
  Serial.begin(115200);
  delay(1000);
  // Set pinMode to OUTPUT
  first.pinMode(P0, INPUT_PULLUP);
  first.pinMode(P1, INPUT_PULLUP);
  Serial.print("Init pcf8574...");
  if (first.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }
}
void loop()
{
  if (first.digitalRead(P0) == LOW) {
     infr_1 = 0;
  }else{
    infr_1 = 1;
  }
  if (first.digitalRead(P1) == LOW){
    infr_2 = 0;
  }
  else{
    infr_2 = 1;
  }
  if(infr_1 == 0 and infr_2 == 0){
    Serial.println("Fuera de pista");  
  }else if(infr_1 == 1 and infr_2 == 1){
    Serial.println("Dentro de pista");
  }else if(infr_1 == 0 and infr_2 == 1){
    Serial.println("girar izquierda");
  }else if(infr_1 == 1 and infr_2 == 0){
    Serial.println("girar derecha");
  }
  
  delay(500);
}
