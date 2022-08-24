/* Example sketch to control a stepper motor with L298N motor driver, Arduino UNO and Stepper.h library. More info: https://www.makerguides.com */

// Include the Stepper library:
#include <Stepper.h>

// Define number of steps per revolution:
const int stepsPerRevolution = 90;
const int button1 = 12;
int state = 0;
int mv=1;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0; // previous state of the button

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper1 = Stepper(stepsPerRevolution,8, 9, 10, 11);

void setup() {
  // Set the motor speed (RPMs):
  myStepper1.setSpeed(150);
  pinMode(button1, INPUT_PULLUP);
}

void loop() {
  
  while(mv==1){
    buttonState=digitalRead(button1);
    if (buttonState!=lastButtonState){
      if (buttonState==HIGH){
  buttonPushCounter++;
  Serial.println("on");
  Serial.print("number of button pushes:");
  Serial.println(buttonPushCounter);
 }
 else
 {
  Serial.println("off");
 }
}

 lastButtonState=buttonState;
 if (buttonPushCounter%2==0)
 {
  Serial.println("motor D Forward");
  mv=1;
  myStepper1.step(9000);
 }
 mv++;
}
}
