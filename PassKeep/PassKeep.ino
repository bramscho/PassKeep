//LCD

#include <LiquidCrystal.h> //LCD Library
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //LCD Pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Array to store LCD Pins


//Button
int joyPin1 = 0; //VRx - X value pin connected to AO
int joyPin2 = 1; //VRy - Y value pin connected to A1
int swButton = 7; //Joystick Button
int buttonState = 0; //Joystick Button State


void setup() {

  pinMode(swButton, INPUT); //Joystick button pin set to INPUT
  Serial.begin(9600); //Begin serial at a baud rate of 9600 bps
  lcd.begin(16, 2); //LCD Format

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(swButton);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.println("high");
    delay(250);
  }
  else {
    // turn LED off:
    Serial.print("low");
  }
}
