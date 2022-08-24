#include <Stepper.h>
// this constant won't change:
const int  buttonPin = 12;    // the pin that the pushbutton is attached to
const int stepsPerRevolution = 90; 
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int digitalPin = 2; // linear Hall magnetic sensor digital interface
int analogPin = A0; // linear Hall magnetic sensor analog interface
int digitalVal ; // digital readings
int analogVal; // analog readings

void setup ()
{ 
  pinMode (digitalPin, INPUT); 
   myStepper.setSpeed(100);
  // initialize serial communication:
  pinMode(analogPin, INPUT); 
  Serial.begin(9600);
}

void loop ()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin) ; 
  if (digitalVal == HIGH) // When magnetic field is present, Arduino LED is on
  {
    Serial.println("stop");
    myStepper.step(+1000);
    delay(500); 
    
  }
  else
  {
    Serial.println("run");
    myStepper.step(-1000);
    delay(500); 
   
  }
  
  // Read the analog interface
  analogVal = analogRead(analogPin);
  Serial.println(analogVal); // print analog value

  delay(100);
}
