//joystick values

int yAxis = A5;
int xAxis = A4;
int yValue = 0;
int xValue = 0;




 
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

//Joystick Variables
 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1


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
 
 void checkFinger();
 if(fingerState = true) {
  
   void homeScreen();
   void selectPassword();
  
  }
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
      lcd.print("Please press finger")
      delay(2000);
      fingerState = false;
      lcd.clear();
    }
  delay(100);
  
  }



void homeScreen() {

lcd.setCursor(0,0);
lcd.print("Please Select Password")
  
//void homeScreen 
}




void selectPassword() {

  yValue = analogRead(yAxis);
  xValue = analogRead(xAxis); 

}




void pwOne(){
//Password 1 - row 1
lcd.setCursor(0,0);
lcd.print(pwNames[0]);
lcd.print(": ");
lcd.print(password[0]);
}

void pwTwo(){
//Password 2 - row 2
lcd.setCursor(0,1);
lcd.print(pwNames[1]);
lcd.print(": ");
lcd.print(password[1]);
}

void pwThree(){
//Password 2 - row 1
lcd.setCursor(0,0);
lcd.print(pwNames[1]);
lcd.print(": ");
lcd.print(password[1]);
}

void pwFour(){
//Password 3 - row 2
lcd.setCursor(0,1);
lcd.print(pwNames[2]);
lcd.print(": ");
lcd.print(password[2]);
}

void pwFive(){
//Password 3 - row 1
lcd.setCursor(0,0);
lcd.print(pwNames[2]);
lcd.print(": ");
lcd.print(password[2]);
}

void pwSix(){
//Password 4 - row 2
lcd.setCursor(0,1);
lcd.print(pwNames[3]);
lcd.print(": ");
lcd.print(password[3]);
}

void pwSeven(){
//Password 4 - row 1
lcd.setCursor(0,0);
lcd.print(pwNames[3]);
lcd.print(": ");
lcd.print(password[3]);
}

void pwEight(){
//Password 5 - row 2
lcd.setCursor(0,1);
lcd.print(pwNames[4]);
lcd.print(": ");
lcd.print(password[4]);
}

void pwNine(){
//Password 5 - row 1
lcd.setCursor(0,0);
lcd.print(pwNames[4]);
lcd.print(": ");
lcd.print(password[4]);
}






void timeOut() {
  
  }

void logOut() {

}






/*
  if (yValue > 600) { //down

    
  }
  if (yValue < 400) { //up

  }
  if (xValue > 600) { //right

  }
  if (xValue < 400) { //left

  }
  */
  
 */

