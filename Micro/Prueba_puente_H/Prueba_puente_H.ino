int IN1 = 5;  // Input4 conectada al pin 4
int IN2 = 4;  // Input3 conectada al pin 5
int IN3 = 6;  // Input4 conectada al pin 4
int IN4 = 7;  // Input3 conectada al pin 5
 
void setup()
{
pinMode(IN4, OUTPUT);  // Input4
pinMode(IN3, OUTPUT);  // Input3
pinMode(IN2, OUTPUT);  // Input2
pinMode(IN1, OUTPUT);  // Input1

}
 
void loop()
{
// Motor 1 gira en un sentido
digitalWrite(IN2, HIGH);
digitalWrite(IN1, LOW);
delay(4000);
// Motor1 no gira
digitalWrite(IN2, LOW);
delay(500);
// Motor1 gira en sentido inverso
digitalWrite(IN1, HIGH);
delay(4000);
// Motor1 no gira
digitalWrite(IN1, LOW);
delay(5000);

// Motor 2 gira en un sentido
digitalWrite(IN4, HIGH);
digitalWrite(IN3, LOW);
delay(4000);
// Motor2 no gira
digitalWrite(IN4, LOW);
delay(500);
// Motor2 gira en sentido inverso
digitalWrite(IN3, HIGH);
delay(4000);
// Motor2 no gira
digitalWrite(IN3, LOW);
delay(5000);
}
