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
  

}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("abcdefghijklmnopqrstuvwxyz");

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  
  Serial.println("abcdefghijklmnopqrstuvwxyz");
} 

