//ADD IN KEYBOARD PRINTING AND FIGNERPRINT - ORDER FINGERPRINT SENSOR

//LCD

#include <LiquidCrystal.h> //LCD Library
const int rs = 8, en = 9, d4 = 10, d5 = 16, d6 = 14, d7 = 15; //LCD Pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Array to store LCD Pins


//Button
int joyPin1 = 0; //VRx - X value pin connected to AO
int joyPin2 = 1; //VRy - Y value pin connected to A1
int swButton = 7; //Joystick Button
int buttonState = 0; //Joystick Button State

int yValue = 0;
int xValue = 0;

//Password - For now, passwords are added through code - FUTURE IMPROVEMENT: edit password array through UI


char* password[] = {"Password Zero", "Password One", "Password Two", "Password Three"};

char* passwordName[] = {"name zero", "name one", "name two", "name three"};


int i = 1;


void setup() {

  pinMode(swButton, INPUT); //Joystick button pin set to INPUT
  Serial.begin(9600); //Begin serial at a baud rate of 9600 bps
  lcd.begin(16, 2); //LCD Format
}





void loop() {
  // read the state of the pushbutton value:



  yValue = analogRead(joyPin2);
  xValue = analogRead(joyPin1);


  scrollPW();
  selectPW();
  


}


void scrollPW() {


  lcd.setCursor(0, 0);
  lcd.print(passwordName[i]);

  lcd.setCursor(0, 1);
  lcd.print(passwordName[i + 1]);


  if (yValue > 600) { //DOWN
    i = i++;
    lcd.setCursor(0, 0);
    lcd.print(passwordName[i]);

    lcd.setCursor(0, 1);
    lcd.print(passwordName[i + 1]);

  }
  if (yValue < 400) { //UP
    i = i--;
    lcd.setCursor(0, 0);
    lcd.print(passwordName[i]);

    lcd.setCursor(0, 1);
    lcd.print(passwordName[i + 1]);

  }
}

void selectPW() {
  
  buttonState = digitalRead(swButton);
  if(buttonState == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print(passwordName[i]);

        if(buttonState == HIGH) {

          //PRINT PASSWORD
        }
        }
    }
    
  

