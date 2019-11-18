#include <Arduino.h>
#include <unity.h>
#include <drone.h>
#include <Position.h>
#include <joystick.h>


bool flying = false;
void setUp(void){

}

void test_flying_true(void){
     if (flying == false)
    {
        flying = true;
        Serial.println("takeoff true");
        //this->sendCommand("takeoff");
        delay(500);
        TEST_ASSERT_EQUAL(flying, true);
    }    
}
void test_flying_false(void){
    if (flying == true)
    {
        flying = false;
        Serial.println("land true");
        //this->sendCommand("takeoff");
        delay(500);
        TEST_ASSERT_EQUAL(flying, false);
        }
}
void setup(){
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(test_flying_true);



    RUN_TEST(test_flying_false);

    UNITY_END();
}

void loop(){

}