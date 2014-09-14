/*
Code by: Joshua Whitelaw
jnw5211@psu.edu

Help From: arduino.com, seeedstudio.com
*/
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int a;
float temperature;
int B=3975;                  //value of the thermistor
float resistance;

void setup()
{
    lcd.begin(16, 2); 
}

void loop()
{
    a=analogRead(0);
    resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
    temperature=(-1)*(1/(log(resistance/10000)/B+1/298.15)-273.15)*(9/5)+32;//convert to temperature via datasheet ;=
   
    lcd.print("Current temp: ");
    lcd.setCursor(0,2);  //Start second line of string temperature readings
    lcd.print(temperature);
    lcd.print(" ");
    lcd.print(char(223));
    lcd.print("F");
    
    delay(1000);
        
    lcd.clear();  //Reset the screen
}

