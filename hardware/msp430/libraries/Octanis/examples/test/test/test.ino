#include <Octanis.h>

const int ledPin =  P4_6;      // the number of the LED pin
const int ledGnd = P4_7;       //the minus pole of led

void setup()
{
  
   // set the digital pin as output:
  pinMode(ledPin, OUTPUT);   
  pinMode(ledGnd, OUTPUT);
  digitalWrite(ledGnd, LOW);
  Serial.begin(4800);  
  Serial.print("test");
  // put your setup code here, to run once:
  pinMode(M5678_SLEEP, OUTPUT);
  pinMode(M8_IN1, OUTPUT); 
  pinMode(M8_IN2, OUTPUT); 
  digitalWrite(M5678_SLEEP, HIGH); //sleep enable is active low!
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(M8_IN1, HIGH);
  digitalWrite(M8_IN2, HIGH);
  
   // put your main code here, to run repeatedly:
  Serial.println("abcdefghijklmnopqrstuvwxyz");

  digitalWrite(ledPin, HIGH);
  delay(5000);

  
  digitalWrite(M8_IN1, LOW);
  digitalWrite(M8_IN2, LOW);
  
  digitalWrite(ledPin, LOW);
  delay(5000);
  


}
