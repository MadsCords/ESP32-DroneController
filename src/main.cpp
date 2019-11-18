#include <Arduino.h>
#include <string.h>
#include "drone.h"
#include <joystick.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

String ssid = "flexlab2"; //"TELLO-FE32CE"; //navnet på dronen ved batteriet
String password = "flexiwifi";

Drone drone(ssid, password);
Joystick joystick(15, 34, 35); // pins: btn, x, y

int lcdc = 16;
int lcdr = 2;

LCD myLED(lcdc, lcdr);

void setup()
{
  Serial.begin(9600);
  myLED.setupLCD();
  drone.joystick = &joystick; 
  drone.lcd =&myLED;

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
    delay(1000);
  }

  joystick.addButtonListener(&drone);
  
  drone.connect();
  drone.setIp ("192.168.10.1"); //drone ip adresse igen

  
}

void loop()
{
  joystick.loop();
  drone.loop();
  //myLED.BatteryLevel("");
  //myLED.testPrint();
} 