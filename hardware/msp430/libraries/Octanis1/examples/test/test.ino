#include <Octanis1.h>

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
  
  
}

void loop()
{
  // put your main code here, to run repeatedly:
 
  
   // put your main code here, to run repeatedly:
  Serial.println("abcdefghijklmnopqrstuvwxyz");

  digitalWrite(ledPin, HIGH);
  delay(500);

  
 
  
  digitalWrite(ledPin, LOW);
  delay(500);
  


}
