#ifndef C8C7268F_7308_4565_BA1F_FDBA5EBBD88F
#define C8C7268F_7308_4565_BA1F_FDBA5EBBD88F

#include <Arduino.h>
#include <string.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <ButtonListener.h>
#include <joystick.h>
#include <LCD.h>

using namespace std;

class Drone : public ButtonListener
{
    public:
        Drone(String ssid , String password);
        void BatteryButton(int pinPushBtn);
        void connect();
        void sendCommand(String commmand);
        void setIp(String ip);
        bool connected;
        String myIp;
        void ButtonPressed();
        void loop();
        Joystick *joystick;
        void motion();
        String lastCommand = "";
        LCD *lcd;
    private:
        void commandResponse(String response);
        int pinPushBtn;
        String ssid;
        String password;
        AsyncUDP udp;
        WiFiUDP udpSender;
        const int udpPort = 8889; 
        String droneIp = "192.168.10.1";
        bool flying = false;
};

#endif /* C8C7268F_7308_4565_BA1F_FDBA5EBBD88F */