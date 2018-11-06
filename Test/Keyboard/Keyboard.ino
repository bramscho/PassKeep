#include <Keyboard.h>



/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kihellohellohelm spam spam spam spam spam spam spam spam spam spam spam spam lohellolohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public hellohellohellodomain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/


                // button push counter

void setup() {
  // make the pushButton pin an input:

  // initialize control over the keyboard:
Keyboard.begin();
}
void loop() {

    Keyboard.print(" spam ")
    delay(500);

  }

