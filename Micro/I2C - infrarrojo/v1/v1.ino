#include <Wire.h>
#include <PCF8574.h>
// Set i2c address
PCF8574 pcf8574(0x21); //this is according to your address found on i2c_scanner
void setup()
{
  Serial.begin(9600);
  Wire.begin(D2, D1);
  delay(1000);
  // Set pinMode to OUTPUT
  pcf8574.pinMode(P0,INPUT);
  pcf8574.pinMode(P1,INPUT);
  Serial.print("Init pcf8574...");
  if (pcf8574.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }
}
void loop()
{
  int valo = digitalRead(P0);
  int valo1 = digitalRead(P1);
  Serial.print("valo = ");
  Serial.println(valo);
  Serial.print("valo1 = ");
  Serial.println(valo1);
  delay(1000);
  }
