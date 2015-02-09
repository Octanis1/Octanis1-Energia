#include <Octanis1.h>
#define tStraight 60 //in seconds
#define tTurn 30


// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU6050.h"
#include <SFE_BMP180.h>


MPU6050 accelgyro;

// You will need to create an SFE_BMP180 object, here called "pressure":
SFE_BMP180 pressure;
double baseline; // baseline pressure

long previousMillis = 0;        // will store last time LED was updated
long interval = 500;

String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete
byte selectedMotor=-1; // from 0 to 7
//const int wheels[8] = {M1_IN1, M1_IN2, M2_IN1, M2_IN2, M3_IN1, M3_IN2, M4_IN1, M4_IN2};
const int motorsEN[8] = {M1_EN, M2_EN, M3_EN, M4_EN, M5_EN, M6_EN, M7_EN, M8_EN};
const int motorsPH[8] = {M1_PH, M2_PH, M3_PH, M4_PH, M5_PH, M6_PH, M7_PH, M8_PH};
boolean mState[8]; //if wheel is turining or not
//const int strutsEN[4] = {
//const int strutsPH[4] = {
//boolean sState[4]; //if strut is turining or not
boolean chargeState=false;
//boolean heatingState=false;


void drive(byte,byte,byte,byte);
void log();
void getPressureTemp(double& T, double& P);


void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();
  accelgyro.initialize();
  pressure.begin();
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  //state variables of the motors. 
  //wheels:
  
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  
  
  for(byte i=0; i<8; i++)
  {
    pinMode(motorsEN[i], OUTPUT); 
    pinMode(motorsPH[i], OUTPUT);
//    pinMode(strutsEN[i], OUTPUT); 
//    pinMode(strutsPH[i], OUTPUT);
  }
  
 // pinMode(M1234_SLEEP, OUTPUT); 
  pinMode(M5678_SLEEP, OUTPUT);
  pinMode(M1234_SLEEP, OUTPUT);
  pinMode(P4_6, OUTPUT); 
  pinMode(P4_7, OUTPUT); 
  
  pinMode(HEAT_BAT, OUTPUT);
  pinMode(BATT_CHG_EN, OUTPUT);
  digitalWrite(BATT_CHG_EN, LOW);
  
  digitalWrite(P4_7, LOW);
  digitalWrite(P4_6, mState[0]); 
 
}

void loop() {
  delay(5000);
  Serial.println("#Start");

  for(int j=0; j<4; j++) // drive a rectangle
  {
    Serial.println("#forward for 1 minute, log every second");
    
    drive(1,1,1,1);
    int i=0;
    while(i<2*tStraight)
    {
      if(millis() - previousMillis > interval) {
        // save the last time you blinked the LED
        previousMillis = millis();  
        log();
        i++;
      }
      else
      {
        delay(5);
      }
    }
    Serial.println("turn for 30 seconds, log every second");
    
    drive(-1,-1,1,1);
    i=0;
    while(i<2*tTurn)
    {
      if(millis() - previousMillis > interval) {
        // save the last time you blinked the LED
        previousMillis = millis();  
        log();
        i++;
      }
      else
      {
        delay(5);
      }
    }
  }





}



void drive(byte w1,byte w2,byte w3,byte w4)
{
  //quick and dirty function for using the H-bridges M5678
  digitalWrite(motorsEN[4],w1!=0);
  digitalWrite(motorsPH[4],w1>0);
  digitalWrite(motorsEN[5],w2!=0);
  digitalWrite(motorsPH[5],w2>0);
  digitalWrite(motorsEN[6],w3!=0);
  digitalWrite(motorsPH[6],w3>0);
  digitalWrite(motorsEN[7],w4!=0);
  digitalWrite(motorsPH[7],w4>0);
  
  if(w1!=0 || w2!=0 || w3!=0 || w4!=0)
  {
    digitalWrite(P4_6, HIGH);
    digitalWrite(M5678_SLEEP, HIGH); //sleep is active low
  }
  else
  {
    digitalWrite(P4_6, LOW);
    digitalWrite(M5678_SLEEP, LOW); //sleep is active low
  }

}

void log()
{
  
  double T,P;
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  //check if heating needed
  getPressureTemp(T,P);
  /*if(T<30)
  {
    heatingState=HIGH;
  }
  else if(T>32)
  {
    heatingState=LOW;
  }
  digitalWrite(HEAT_BAT, heatingState);*/

      
  // display tab-separated accel/gyro x/y/z values
  //Serial.print("a/g/P/T:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.print(gz); Serial.print("\t");
  Serial.print(P); Serial.print("\t");
  Serial.println(T);
  /*if(heatingState)
    Serial.println("h");
  else
    Serial.println("*");*/
}


void getPressureTemp(double& T, double& P)
{
  char status;
  double p0,a;
  // You must first get a temperature measurement to perform a pressure reading.
  // Start a temperature measurement:
  // If request is successful, the number of ms to wait is returned.
  // If request is unsuccessful, 0 is returned.
  status = pressure.startTemperature();
  if (status != 0)
  {
    // Wait for the measurement to complete:
    delay(status);
    // Retrieve the completed temperature measurement:
    // Note that the measurement is stored in the variable T.
    // Use '&T' to provide the address of T to the function.
    // Function returns 1 if successful, 0 if failure.
    status = pressure.getTemperature(T);
    if (status != 0)
    {
    // Start a pressure measurement:
    // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
    // If request is successful, the number of ms to wait is returned.
    // If request is unsuccessful, 0 is returned.
      status = pressure.startPressure(3);
      if (status != 0)
      {
    // Wait for the measurement to complete:
        delay(status);
    // Retrieve the completed pressure measurement:
    // Note that the measurement is stored in the variable P.
    // Use '&P' to provide the address of P.
    // Note also that the function requires the previous temperature measurement (T).
    // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
    // Function returns 1 if successful, 0 if failure.
        status = pressure.getPressure(P,T);
        
        
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
}






