/*
  Version: 2.1, Dated: 13/6/2023
  Sensor: TEMT6000 Ambient Light Sensor
  Authur: Asif Mahmood
  Designation: Embedded System Engineer
*/

#include <Arduino.h>

// setting input pin 
const int signalPIN = GPIO_NUM_13;

// function decleration
void lightPercent();
void lightLux();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(signalPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if x is true then light will be calculated in percentage else in lux

  bool x = false; // x can be true or false
  if(x){
    lightPercent();
    delay(500);
  }
  else{
    lightLux();
    delay(500);
  }
}

// calculating light falling from source 

// light in percentage
void lightPercent(){  
  float voltage;
  float percent;
  voltage = (analogRead(signalPIN)/1024.0); // reading sensor's value (signal)
  percent = voltage * 100; // calculating light in percentage
  Serial.print("Light ");
  Serial.print(percent);  
  Serial.print(" %\n");
}

// light in lux
void lightLux(){
  float volts = (analogRead(GPIO_NUM_13) * 5.0) / 1024.0; // converting analog values b/w 1-5 volts
  float mAmps = (volts/10000)*1000000; //  calculating mAmps I = (V/R)*1000000
  float lux = mAmps * 2.0; // calculating lux
  Serial.print(lux);
  Serial.print(" lux\n");
}