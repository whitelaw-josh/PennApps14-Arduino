/*
Code by: Joshua Whitelaw, Tyler Storr
jnw5211@psu.edu
trs5293@psu.edu

Help From: arduino.com, seeedstudio.com
*/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

#define X_Sensor A0 //X Sensor in pin A0
#define Y_Sensor A1 //...
#define Z_Sensor A2 //...

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pins_init();
}

void loop() {
  Serial.println("X-Axis ");
  Serial.print( analogRead(X_Sensor) );
  
  Serial.println(" Y-Axis ");
  Serial.print( analogRead(X_Sensor) );
  
  Serial.println(" Z-Axis ");
  Serial.print( analogRead(X_Sensor) );
  
  delay(100);
}

void pins_init() //Reads in X,Y, Z input sensory values
{
  pinMode(X_Sensor, INPUT);
  pinMode(Y_Sensor, INPUT);
  pinMode(Z_Sensor, INPUT);
}
