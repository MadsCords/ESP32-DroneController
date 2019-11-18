#include <Arduino.h>
#include "drone.h"
#include <joystick.h>
#include <Position.h>
#include <LCD.h>

Drone::Drone(String ssid, String password)
{
    this->ssid = ssid;
    this->password = password; 
    
    this->pinPushBtn = 33;
    pinMode(this->pinPushBtn, INPUT_PULLUP);
}

void Drone::connect()
{
    Serial.println("drone begin");
    //Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(this->ssid.c_str(), this->password.c_str());
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    if(udp.listen(udpPort)) {
        this->myIp = WiFi.localIP().toString();
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
      
        udp.onPacket(
            [this](AsyncUDPPacket packet) -> void
            {
                // make a string from the data
                String s((char*)packet.data());
                s = s.substring(0, packet.length()); 
                s.trim();
                // send string to method
                this->commandResponse(s);
            }
        );
        this->sendCommand("command");
        //Serial.println(this->commandResponse)
    }
}

void Drone::sendCommand(String command)
{
    udpSender.beginPacket(this->droneIp.c_str(), udpPort);
    udpSender.printf(command.c_str());
    udpSender.endPacket();    
}

void Drone::setIp(String ip)
{
    this->droneIp = ip;
}
        
void Drone::commandResponse(String response)
{
    Serial.print("got following response: ");
    Serial.println(response.c_str());
    Serial.print("message length: ");
    Serial.println(response.length());
    this->lastCommand = response;
}

void Drone::ButtonPressed()
{
    if (flying == false)
    {
        this->flying = true;
        Serial.println("takeoff");
        this->sendCommand("takeoff");
    }    
    else
    {
        Serial.println("land");
        this->sendCommand("land");
        this->flying = false;
    }
}

void Drone::BatteryButton(int pinPushBtn){
   
    
   /* if (digitalRead(pinPushBtn) == LOW) {
        Serial.println("Checking Battery level");
        //sendCommand("battery?");
        //delay(500);
        //lcd.BatteryLevel(this->lastCommand);
        lcd.testPrint();
    }*/

}

void Drone::loop()
{
    motion();

    if (digitalRead(pinPushBtn) == LOW) {
        Serial.println("Checking Battery level");
        //sendCommand("battery?");
        //delay(500);
        //lcd.BatteryLevel(this->lastCommand);

        lcd->testPrint();
    }
    // Using Position object to retrieve information
    
    /*Position joystickPosition = this->joystick->getPosition();
    
    if (joystickPosition.x != 0)
    {
        if (joystickPosition.y != 0)
        {
            Serial.print(joystickPosition.x);
            Serial.print(" ");
            Serial.println(joystickPosition.y);
        }

        if (joystickPosition.x == 2047)
        {
            this->sendCommand("right 100");
            Serial.println("right");
        }

        else if (joystickPosition.x == -2047)
        {
            this->sendCommand("up 100");       
        } 
   }

    
    
    
    
    /*Using joystick methods
   Serial.print(this->joystick->getX());
   Serial.print(" ");
   Serial.println(this->joystick->getY());


    //this->sendmessage("joystickPosition");*/
}


void Drone::motion(){

    Position joystickPosition = this->joystick->getPosition();

   // Joystick fremad
    if (joystickPosition.x >= 500)
    {
        if (joystickPosition.y == 0){
      //delay(5000);   
       //this->sendCommand("speed 100");
        delay(5000);   
       this->sendCommand("forward 50");
       Serial.println("forward");
       delay(5000);
       this->sendCommand("up 50");
       Serial.println("up");
       delay(5000);
       this->sendCommand("back 50");
       Serial.println("back");
       delay(5000);
       this->sendCommand("down 50");
       Serial.println("down");
       delay(2000);
       Serial.println("Sequence done");
        }
    }
    // Joystick tilbage
      if (joystickPosition.x <= -500)
    {
        if (joystickPosition.y == 0){
    
    delay(5000);
       this->sendCommand("up 50");
       Serial.println("up");
       delay(5000);
       this->sendCommand("flip l");
       Serial.println("flip left");
       delay(5000);
       this->sendCommand("flip r");
       Serial.println("flip right");
       delay(5000);
       this->sendCommand("down 50");
       Serial.println("down");
       delay(2000);
       Serial.println("Sequence done");
        }
    }
    // Joystick højre
 if (joystickPosition.x == 0)
    {
        if (joystickPosition.y >= 500)
        {
    
        delay(10000);   
       this->sendCommand("cw 360");
       Serial.println("clockwise");
       delay(10000);
       this->sendCommand("ccw 360");
       Serial.println("counterclockwise");
       delay(2000);
       Serial.println("Sequence done");
    
    }
    }
    // Joystick venstre
    if (joystickPosition.x == 0)
    {
        if (joystickPosition.y <= -500)
        {
       this->sendCommand("right 50");
       Serial.println("right");
       delay(5000);
       this->sendCommand("back 50");
       Serial.println("right");
       delay(5000);
       this->sendCommand("left 50");
       Serial.println("back");
       delay(5000);
       this->sendCommand("forward 50");
       Serial.println("left");
       delay(2000);
       //Serial.println("Sequence done");
    }

    }
}
