
#include <Wire.h>

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}


void loop()
{
  byte error, address;
  int nDevices;
  const uint8_t _data = 1;

  Serial.println("Scanning...");


  Wire.beginTransmission(0x77);

  delay(10);


  Wire.requestFrom(0x68, 1);

  if(Wire.available()){
    //Serial.println("ack");
  }
  
  //Wire.endTransmission();
  delay(50);           // wait 5 seconds for next scan
}

