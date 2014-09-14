/*
Code by: Joshua Whitelaw
jnw5211@psu.edu

Help From: arduino.com, seeedstudio.com
*/
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() 
{
    lcd.begin(16, 2); //Sets the columns and rows for the text
    lcd.print("DANCE PARTY!!!!!");  //Print statement
    delay(1000);
}

void loop() 
{
    lcd.setCursor(0, 1);    //Starts at column 0  row 1  
    
    //Change color as time progresses
    lcd.setRGB(255, 0, 0);
    delay(100);
    
    lcd.setRGB(0, 255, 0);
    delay(100);
    
    lcd.setRGB(0, 0, 255);
    delay(100);
      
    lcd.setRGB(100, 100, 0);
    delay(100);
    
    lcd.setRGB(0, 100, 100);
    delay(100);
    
    lcd.setRGB(100, 0, 100);  
    delay(100);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
