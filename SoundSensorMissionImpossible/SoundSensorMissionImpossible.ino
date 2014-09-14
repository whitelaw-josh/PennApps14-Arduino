/*
Code by: Joshua Whitelaw
jnw5211@psu.edu

Help From: arduino.com, seeedstudio.com
*/
#include <Wire.h>
#include "rgb_lcd.h"

#define SOUND_SENSOR A1 //defines the sound sensor in the A1 spot of the Arduino

int GVal = 0; //RGB global variables to vary by sound sensory input
int RVal = 0;
int BVal = 0;
int sensorValue = 0;//use A0 to read the electrical signal

rgb_lcd lcd;

void setup() 
{
    lcd.begin(16,2);
    pins_init();
}
 
void loop() 
{       
        sensorValue = analogRead(SOUND_SENSOR); //Reads in the sensor data value
  
        if(sensorValue < 251) //If it is quiet (GREEN)
        {
          GVal = 255 - sensorValue;
          RVal += sensorValue;  
          BVal = 0;
        }
        
        else if(sensorValue <501) //If it is moderately louder (YELLOW)
        {
          GVal -= (sensorValue - 250);
          RVal = 0;
          BVal = 0;
        }
        
        else //If it is too loud (RED)
        {
          GVal = 0;
          RVal = 255;
          BVal = 0;
        }
        
        lcd.setRGB(RVal, GVal, BVal);  //Prints the color
        
        delay(50);
        lcd.clear();      
}

void pins_init()  //Reads in the snesory data
{
	pinMode(SOUND_SENSOR, INPUT); 
}
