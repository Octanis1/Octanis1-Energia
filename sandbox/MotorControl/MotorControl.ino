/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and 
  clears it.

  A good test for this is to try it with a GPS receiver 
  that sends out NMEA 0183 sentences. 

  Created 9 May 2011
  by Tom Igoe
  Modified 24 April 2013
  by Sean Alvarado

  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  
  This example code is in the public domain.

*/
#include <Octanis1.h>

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

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  //state variables of the motors. 
  //wheels:
  
  
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
  
  digitalWrite(P4_7, LOW);
  digitalWrite(P4_6, mState[0]); 
 
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    //get string length:
    byte nchar=inputString.length();
    for(byte i=0; i<nchar-1; i=i+2)
    {
      selectedMotor=byte(inputString[i]-49);
      Serial.println(selectedMotor);
      if (selectedMotor<0 || selectedMotor>7)
      {
        
        if(inputString[i]=='c')
        {
          chargeState=!chargeState;
          digitalWrite(BATT_CHG_EN,chargeState);
        }
        else if(inputString[i]=='h') //start heating
        {
          digitalWrite(HEAT_BAT, HIGH);
        }
        else if(inputString[i]=='k') //stop heating
        {
          digitalWrite(HEAT_BAT,LOW);
        }      
        
        //next character.
          
        i=i-1; //only increase by 1
        continue;
        
      }

      if(inputString[i+1]=='f')
      {      
        Serial.println("forward");
        mState[selectedMotor]=true; 
        digitalWrite(motorsEN[selectedMotor],HIGH);
        digitalWrite(motorsPH[selectedMotor],LOW);
      }
      else if(inputString[i+1]=='b')
      {
        mState[selectedMotor]=true; 
        digitalWrite(motorsEN[selectedMotor],HIGH);
        digitalWrite(motorsPH[selectedMotor],HIGH);
      }
      else
      {
        mState[selectedMotor]=false; 
        digitalWrite(motorsEN[selectedMotor],LOW);
        digitalWrite(motorsPH[selectedMotor],LOW);
      }
      
      digitalWrite(P4_6, LOW); //led off by default
      if(mState[0] || mState[1] || mState[2] || mState[3])
      {
        
        digitalWrite(P4_6, HIGH);
        //digitalWrite(M1234_SLEEP, HIGH); //sleep is active low
        digitalWrite(M1234_SLEEP, HIGH); //sleep is active low
        
      }
      else
      {
       
       // digitalWrite(M1234_SLEEP, LOW); //sleep is active low
        digitalWrite(M1234_SLEEP, LOW); //sleep is active low
      }
      
      if(mState[5] || mState[6] || mState[7] || mState[4])
      {
        
        digitalWrite(P4_6, HIGH);
        //digitalWrite(M1234_SLEEP, HIGH); //sleep is active low
        digitalWrite(M5678_SLEEP, HIGH); //sleep is active low
        
      }
      else
      {
       
       // digitalWrite(M1234_SLEEP, LOW); //sleep is active low
        digitalWrite(M5678_SLEEP, LOW); //sleep is active low
        

      }
        
    }

    
    
    Serial.println(inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX. This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
    stringComplete = true;
    } 
  }
}


