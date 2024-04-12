#include <SPI.h>
#include <MFRC522.h>
#include <PCF8574.h>
#include <LiquidCrystal_I2C.h>  
#include <ESP8266WiFi.h>

#define redSSID "Linksys00516"
#define redPASS "12345678"
#define RST_PIN  0    //rst D3
#define SS_PIN  2   //Pin 2 SDA D4
//SCK(D5)/MOSI(D7)/MISO(D6)


LiquidCrystal_I2C lcd(0x27, 16, 2);
PCF8574 mov(0x21);
int infr_centro;//p1
int infr_derecha;//p2
int infr_izquierda;//p0

byte Plantactual[4]; //almacenará el código de llavero
byte Planta1[4]= {0x3A, 0xBB, 0xF3, 0x66} ; //código del planta 1
byte Planta2[4]= {0x86, 0x39, 0x98, 0xF7} ; //código del planta 2
byte Planta3[4]= {0x36, 0xC5, 0x82, 0xF7} ; //código del planta 3
byte Planta4[4]= {0xE6, 0xAF, 0xA0, 0xF7} ; //código del planta 4


MFRC522 rfid(SS_PIN, RST_PIN); //Creamos el objeto para el RC522
int contp1 = 0;
int contp2 = 0;
int contp3 = 0;
int contp4 = 0;
int water1; 
int water;

void setup(){

  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  rfid.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso:");
  pinMode(15, OUTPUT);
  mov.pinMode(P0, INPUT_PULLUP);// infrarrojo centra
  mov.pinMode(P1, INPUT_PULLUP);// infrarrojo derecho
  mov.pinMode(P2, INPUT_PULLUP);// infrarrojo izquierdo
  mov.pinMode(P3, OUTPUT);//IN1
  mov.pinMode(P4, OUTPUT);//IN2
  mov.pinMode(P5, OUTPUT);//IN3
  mov.pinMode(P6, OUTPUT);//IN4
  pinMode(D0, OUTPUT);//LED
  if (mov.begin()) {
    Serial.println("TODO OK");
  } else {
    Serial.println("ERROR");
  }
  lcd.init();
  lcd.backlight();
  lcd.clear();
  WiFi.begin(redSSID,redPASS);
  Serial.print("conectando...");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  
}
#define SERVER "192.168.1.108"
#define SOCKET 1409

void loop(){
  if (rfid.PICC_IsNewCardPresent()){
    Detenerse();
    Identificacion();
  }else{
    lcd.noDisplay();
    lcd.noBacklight();
    lcd.clear();
    int water1 = analogRead(A0);
    int water = (water1*100)/760;
    if(water < 30){
        lcd.display();
        lcd.backlight();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Se recomienda:");
        lcd.setCursor(0,1);
        lcd.print("Llenar estanque");
        
      }
    lcd.clear();
    analogWrite(15, 200);
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
}
void Identificacion(){  
  if ( rfid.PICC_ReadCardSerial()){
    lcd.noDisplay();
    lcd.noBacklight();
    lcd.clear();
    // Enviamos serialemente su UID
    Serial.print(F("Card UID:"));
    for (byte i = 0; i < rfid.uid.size; i++) {  
      Plantactual[i]=rfid.uid.uidByte[i];} 
    Serial.print("     ");                 
    //comparamos los UID 
    if(compareArray(Plantactual,Planta1)){
      if(contp1 < 1){
        Detenerse();
        contp1 = contp1 +1;
        contp2 = 0;
        contp3 = 0;
        contp4 = 0;
        lcd.display();
        lcd.backlight();
        Serial.println("Planta 1 detectada");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Se identifico:");
        lcd.setCursor(0,1);
        lcd.print("Planta 1");
        WiFiClient cliente;
        if(cliente.connect(SERVER,SOCKET)){
          cliente.println("$p_1_regada");
        }else{
          Serial.println("error de conexion");
       }
       cliente.stop();
       digitalWrite(D0,HIGH);
       delay(3000);
       digitalWrite(D0,LOW);
        }
      
      }
      //para motores, preguntar bbdd si se necesita riego si o no
    else if(compareArray(Plantactual,Planta2)){
      if(contp2 < 1){
        Detenerse();
        contp2 = contp2+1;
        contp1 = 0;
        contp3 = 0;
        contp4 = 0;
        lcd.display();
        lcd.backlight();
        Serial.println("Planta 2 detectada");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Se identifico:");
        lcd.setCursor(0,1);
        lcd.print("Planta 2");
        WiFiClient cliente;
        if(cliente.connect(SERVER,SOCKET)){
          cliente.println("$p_2_regada");
        }else{
           Serial.println("error de conexion");
        }
        cliente.stop();
        digitalWrite(D0,HIGH);
        delay(3000);
        digitalWrite(D0,LOW);
        }}
      //para motores, preguntar bbdd si se necesita riego si o no
    else if(compareArray(Plantactual,Planta3)){
      if(contp3 <1){
        Detenerse();
        contp3 = contp3+1;
        contp1 = 0;
        contp2 = 0;
        contp4 = 0;
        lcd.display();
        lcd.backlight();
        Serial.println("Planta 3 detectada");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Se identifico:");
        lcd.setCursor(0,1);
        lcd.print("Planta 3");
        WiFiClient cliente;
        if(cliente.connect(SERVER,SOCKET)){
          cliente.println("$p_3_regada");
        }else{
          Serial.println("error de conexion");
        }
        cliente.stop();
        digitalWrite(D0,HIGH);
        delay(3000);
        digitalWrite(D0,LOW);
        }
      }
      //para motores, preguntar bbdd si se necesita riego si o no
    else if(compareArray(Plantactual,Planta4)){
      if(contp4 <1){
        Detenerse();
        contp4 = contp4+1;
        contp1 = 0;
        contp2 = 0;
        contp3 = 0;
        lcd.display();
        lcd.backlight();
        Serial.println("Planta 4 detectada");
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Se identifico:");
        lcd.setCursor(0,1);
        lcd.print("Planta 4");
        WiFiClient cliente;
        if(cliente.connect(SERVER,SOCKET)){
           cliente.println("$p_4_regada");
        }else{
           Serial.println("error de conexion");
          }
        cliente.stop();
        digitalWrite(D0,HIGH);
        delay(3000);
        digitalWrite(D0,LOW);
        }
      }
      //para motores, preguntar bbdd si se necesita riego si o no
    else{
      Serial.println("Error de lectura o tarjeta no registrada");
      lcd.display();
      lcd.backlight();
      // Terminamos la lectura de la tarjeta
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("ERROR DE LECTURA");
      delay(2000);
      rfid.PICC_HaltA();
      }}
      return;
     
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
boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
