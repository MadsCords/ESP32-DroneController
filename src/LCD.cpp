#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <string.h>
#include <wire.h>
//#include <LiquidCrystal.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <drone.h>
using namespace std;


LCD::LCD(int lcdc, int lcdr)

{
    this->lcdc = lcdc;
    this->lcdr = lcdr;
    
    int lcdColumns = 16;
    int lcdRows = 2;
}


int lcdColumns = 16;
int lcdRows = 2;
/*

void LCDscreen::setupLCD() {      //initialzing the LCD screen
int lcdColumns = 16;
int lcdRows = 2;
// set the LCD number of columns and rows

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
/*this->*/

LiquidCrystal_I2C lcd(0x3F, lcdColumns, lcdRows);  

void LCD::setupLCD() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

/*void LCD::loop() {
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(1000);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear(); 
  
}
*/

void LCD::BatteryLevel(String batLvl) {

  lcd.setCursor(0, 0);
  lcd.print(batLvl);
  //delay(1000);
  /*lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("70%");
  delay(1000);
  lcd.clear();*/ 
}

void LCD::testPrint(){
        lcd.setCursor(0, 0);
        lcd.print("heeyooo");
}






/*
    void liftOffText(String) 
    {
        


    }
void liftOffText();
    void missionPadOneText();
    void missionPadTwoText();
    void missionPadThreeText();
    void missionPadFourText();
*/