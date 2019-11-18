#ifndef B64D26BE_62C0_4E3C_A258_164FC60AA43E
#define B64D26BE_62C0_4E3C_A258_164FC60AA43E
#include<string>
using namespace std;

class LCD
{
   public:
    LCD(int lcdc, int lcdr);
    void setupLCD();
    void setup();
    void loop();
    void liftOffText();
    void BatteryLevel(String batLvl);
    void testPrint();
    int lcdr;
    int lcdc;

   //LiquidCrystal_I2C lcd;
    

};
#endif /* B64D26BE_62C0_4E3C_A258_164FC60AA43E */