/*
  Version: 1.0
  Sensor: TEMT6000 Ambient Light Sensor
  Authur: Asif Mahmood
  Designation: Embedded System Engineer
*/

#include <Arduino.h>

// setting input pin 
const int signalPIN = GPIO_NUM_13;

// function decleration
void lightSensing();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(signalPIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightSensing();
  delay(500);
}

// calculating light falling from source 
void lightSensing(){
  float lightVALUE;
  float light;
  lightVALUE = analogRead(signalPIN); // reading sensor's value (signal)
  light = lightVALUE*0.0976; // calculating light in percentage
  Serial.println(light);
  Serial.print("Light ");
  Serial.print("%:  ");
}