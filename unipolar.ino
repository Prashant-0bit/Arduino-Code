
#include <Stepper.h>
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
// Number of Steps Required
int StepsRequired;

Stepper steppermotor(STEPS_PER_REV, 46, 48, 50, 52);

void setup()
{
// Nothing  (Stepper Library sets pins as outputs)
}

void loop()
{ 
  // Rotate CCW 1/2 turn Forward
  StepsRequired  =   STEPS_PER_OUT_REV / 2;   
  steppermotor.setSpeed(700);  
  steppermotor.step(StepsRequired);
  delay(2000);

}
