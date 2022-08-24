#include <Stepper.h>
// this constant won't change:
const int  buttonPin = 12;    // the pin that the pushbutton is attached to
const int  buttonPinD = 13;
int mv=1;
int state = 0;

const int stepsPerRevolution = 90;
const int stepsPerRevolutionS = 200;
   
// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonPushCounterD = 0;   // counter for the number of button presses
int buttonStateD = 0;         // current state of the button
int lastButtonStateD = 0;     // previous state of the button

Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper2(stepsPerRevolutionS, 4, 5, 6, 7);

void setup()
{
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinD, INPUT);
  myStepper1.setSpeed(100);
  myStepper2.setSpeed(100);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() 
{
  while(mv==1)
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
  
  }
if (buttonState == LOW)
{mv++;
  }


while(mv==2)
 {                                                   // Second Limit Switch
  buttonStateD = digitalRead(buttonPinD);                  // read the pushbutton input pin:
      if (buttonStateD != lastButtonStateD)                // compare the buttonState to its previous state
        {
        if (buttonStateD == HIGH)                          // if the state has changed, increment the counter
          {
      
      buttonPushCounterD++;                                // if the current state is HIGH then the button went from off to on:
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } 
    else 
    {
      Serial.println("off");                              // if the current state is LOW then the button went from on to off:
    }
    
    delay(50);                                            // Delay a little bit to avoid bouncing
  }
  lastButtonStateD = buttonStateD;                          // save the current state as the last state, for next time through the loop
  if (buttonPushCounterD % 2 == 0) 
                {          
    Serial.println("clockwise");
    myStepper2.step(stepsPerRevolutionS); 
  } 
  else{
    (buttonStateD == LOW);
  myStepper2.step(LOW);
  }
 
}
}
