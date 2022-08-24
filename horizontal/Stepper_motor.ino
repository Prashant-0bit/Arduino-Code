#include <Stepper.h>
// this constant won't change:
const int  buttonPin = 12;   
const int stepsPerRevolution = 90;

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  myStepper1.setSpeed(100);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() 
{
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) 
  {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) 
    {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } 
    else 
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  if (buttonPushCounter % 2 == 0) 
  {
    Serial.println("clockwise");
    myStepper1.step(-stepsPerRevolution);
  } 
  else 
  {
    Serial.println("counterclockwise");
  }
}
