#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  0    //rst D3
#define SS_PIN  2   //Pin 2 SDA D4
//SCK(D5)/MOSI(D7)/MISO(D6)
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

void setup() {
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso:");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Planta1[4]= {0x3A, 0xBB, 0xF3, 0x66} ; //código del usuario 1
byte Planta2[4]= {0x86, 0x39, 0x98, 0xF7} ; //código del usuario 2
byte Planta3[4]= {0x36, 0xC5, 0x82, 0xF7} ; //código del usuario 3
byte Planta4[4]= {0xE6, 0xAF, 0xA0, 0xF7} ; //código del usuario 4
void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {  
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.print("     ");                 
                  //comparamos los UID 
                  if(compareArray(ActualUID,Planta1))
                    Serial.println("Planta 1 detectada");
                    //para motores, preguntar bbdd si se necesita riego si o no
                  else if(compareArray(ActualUID,Planta2))
                    Serial.println("Planta 2 detectada");
                    //para motores, preguntar bbdd si se necesita riego si o no
                  else if(compareArray(ActualUID,Planta3))
                    Serial.println("Planta 3 detectada");
                    //para motores, preguntar bbdd si se necesita riego si o no
                  else if(compareArray(ActualUID,Planta4))
                    Serial.println("Planta 4 detectada");
                    //para motores, preguntar bbdd si se necesita riego si o no
                  else
                    Serial.println("Erro de lectura o tarjeta no registrada");
                  
                  // Terminamos la lectura de la tarjeta
                  mfrc522.PICC_HaltA();
          
            }
      
  }
  
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
