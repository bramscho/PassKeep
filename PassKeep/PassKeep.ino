/*
 * 
char* password[]={"passwordOne","passwordTwo","passwordThree","passwordFour","passwordFive"};

void setup(){
  Serial.begin(9600);
  }

  void loop(){
     Serial.print(password[0]);
      delay(250);
         Serial.println(password[1]);
    delay(250);
         Serial.println(password[2]);
      delay(250);
         Serial.println(password[3]);
      delay(250);
         Serial.println(password[4]);
      delay(250);
    }
 */


//Fingerprint Libraries
#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"`
#include <Wire.h>

//LCD Libraries
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

//LCD Definitions
#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

//IDK
//int n = 1;

//FingerState
bool fingerState = false;

//Passwords 
char* password[]={"pwOne","pwTwo","pwThree","pwFour","pwFive"};

//Password Associations
char* pwNames[]={"passwordOne","passwordTwo","passwordThree","passwordFour","passwordFive"};


void setup()
{
//Start serial at the baud rate of 9600
  Serial.begin(9600); //set up Arduino's hardware serial UART

//send serial command to initialize fps
  fps.Open();
  
//Setup fingerprint backlight
  fps.SetLED(true);  
  
//Start LCD at 16x2
lcd.begin (16,2); 

//Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
}


void loop()
{
 Serial.print(password[1]);
 
}



void checkFinger() {

  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
 
    if (id <200) //<- change id value depending model you are using
    {//if the fingerprint matches, provide the matching template ID
      lcd.setCursor(0,0);
      lcd.print("Verified ID:")
      lcd.setCursor(0,1);
      lcd.print("ID")
      fingerState = true;
      delay(1000);
      lcd.clear();
    }
    else
    {//if unable to recognize
      lcd.setCursor(0,0);
      lcd.print("Please Try Again")
      delay(2000);
      lcd.clear();
    }
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Please press finger")
    
  }
  delay(100);
  
  }


void selectPassword() {
  
  }



void timeOut() {
  
  }

void logOut() {

}


