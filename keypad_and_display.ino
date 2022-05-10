//Refer Circuit diagram for this code
//All components are display there with specifications or names
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Stepper.h>
#include <Servo.h>
#include <Arduino.h>

//*******************Keypad**********************//

const byte ROWS = 4;        
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {37, 39, 41, 43};
byte colPins[COLS] = {45, 47, 49, 51};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);


//*************Unipolar Stepper Motor**************//

const float STEPS_PER_REV = 32;                             // Number of steps per internal motor revolution 
const float GEAR_RED = 64;                                  // Amount of Gear Reduction
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;   // Number of steps per geared output rotation
int StepsRequired;                                          // Number of Steps Required
Stepper steppermotor(STEPS_PER_REV, 46, 48, 50, 52);

//****************Servo Motor*********************//

Servo myservo;
#define servoPin 3                                          // Define the servo pin:
int IRSensor = 2;                                           // connect ir sensor to arduino pin 2
int IRSensor1 = 22;                                         // connect ir sensor to arduino pin 22

//****************Stepper Motor*********************//

const int stepsPerRevolution = 90;                          // Define number of steps per revolution:
const int stepsPerRevolutionS = 200;  

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper2 = Stepper(stepsPerRevolutionS,4, 5, 6, 7);       //Vertical Motor
Stepper myStepper1 = Stepper(stepsPerRevolution,8, 9, 10, 11);     // Horizontal Motor


//****************Limit Switch*********************//
int LimitX = 12;
int LimitY = 13;
int mv=1;


void setup(){
   pinMode(LimitX, INPUT);
   pinMode(LimitY, INPUT);                                 // Limit Switch
  
  lcd.backlight();
  lcd.init();
  lcd.print(" Enter a Key! ");                             // Input Entry For Display
  lcd.setCursor(0, 0);
  
  myservo.attach(servoPin);                                // Attach the Servo variable to a pin:

  myStepper1.setSpeed(100);                                // Set the motor speed (RPMs):
  myStepper2.setSpeed(100);

  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (IRSensor1, INPUT);
}


void loop(){
  //char customKey = customKeypad.getKey();                 // Custom Key Entry
  //if (customKey){
    //lcd.clear();
    //lcd.setCursor(0,0); 
    //lcd.print(customKey);
  //}
  
 //************************************************************  1st Position  **********************************************************//
    if (customKey == '1')                                 
    {
       myStepper1.step(5500);                              // Go To Position 1
       delay(1000);
  
       myStepper2.step(-3400);  
      delay(1000);
      
    int statusSensor = digitalRead (IRSensor);                // Sensor Checking
      if (statusSensor == 0){
        //lcd.clear();
        //Serial.print("HIGH-   No Obstacle/Black Surface\n");
        //lcd.print(" Continue! ");
        //lcd.setCursor(0, 0); 
      
    
        myservo.write(180);                                  // Turn Servo Right to 180 degrees
        delay(1000);
  
        
        StepsRequired  =  (3*- STEPS_PER_OUT_REV)/2;         // Rotate CCW 1/2 turn Forward
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
        delay(1000);
  
        myservo.write(125);                                  // Turn Servo Right to 155 degrees
        delay(1000);                                         
  
        myStepper2.step(-70);                                // Upward
        delay(1000);
        
        
        StepsRequired  =  (3*STEPS_PER_OUT_REV)/2;           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
        
      
      while(digitalRead(LimitX) == HIGH)  {
      Serial.println("clockwise");
      myStepper1.step(-stepsPerRevolution);
      }
      delay(1000);
      while(digitalRead (LimitY) == HIGH){
      myStepper2.step(stepsPerRevolutionS); 
    }

        StepsRequired  =  (2*-STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
        
        myservo.write(180);                                 // Turn Servo Right to 180 degrees
        delay(1000);
        
        StepsRequired  =  (2*STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
      }
      
      else{
        Serial.print("LOW-    Obstacle Detected/White Surface\n"); 
        lcd.clear();
        lcd.print(" Empty! ");
        lcd.setCursor(0, 0);

        while(digitalRead(LimitX) == HIGH)  {
      Serial.println("clockwise");
      myStepper1.step(-stepsPerRevolution);
      }
      delay(1000);
      while(digitalRead (LimitY) == HIGH){
      myStepper2.step(stepsPerRevolutionS); 
    }
          }
    
  lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter a Number!");
  mv++;  
}


 //************************************************************  2nd Position  **********************************************************//
 
if (customKey == '2')                                      
    {
       myStepper1.step(3500);                              // Go To Position 2
       delay(1000);
  
       myStepper2.step(-3400);  
       delay(1000);

       int statusSensor = digitalRead (IRSensor);                // Sensor Checking
       if (statusSensor == 0){
        lcd.clear();
        Serial.print("HIGH-   No Obstacle/Black Surface\n");
        lcd.print(" Continue! ");
        lcd.setCursor(0, 0); 
   
    
       myservo.write(180);                                 // Turn Servo Right to 180 degrees
       delay(1000);

      
      StepsRequired  =  (3*- STEPS_PER_OUT_REV)/2;              // Rotate CCW 1/2 turn Forward
      steppermotor.setSpeed(700);  
      steppermotor.step(StepsRequired);
      delay(1000);

      myservo.write(125);                                 // Turn Servo Right to 155 degrees
      delay(1000);                                         

      myStepper2.step(-70);                               // Upward
      delay(1000);
      
      
      StepsRequired  =  (3*STEPS_PER_OUT_REV)/2;          // Rotate CW 1/2 turn Backward 
      steppermotor.setSpeed(700);   
      steppermotor.step(StepsRequired);
      delay(1000);

          
       while(digitalRead(LimitX) == HIGH)  {
       Serial.println("clockwise");
       myStepper1.step(-stepsPerRevolution);
  }
      while(digitalRead (LimitY) == HIGH){
      myStepper2.step(stepsPerRevolutionS); 
  }

        StepsRequired  =  (2*-STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
        
        myservo.write(180);                                 // Turn Servo Right to 180 degrees
        delay(1000);
        
        StepsRequired  =  (2*STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
       }
       
       else{
        Serial.print("LOW-    Obstacle Detected/White Surface\n"); 
        lcd.clear();
        lcd.print(" Empty! ");
        lcd.setCursor(0, 0);

         while(digitalRead(LimitX) == HIGH)  {
       Serial.println("clockwise");
       myStepper1.step(-stepsPerRevolution);
  }
      while(digitalRead (LimitY) == HIGH){
      myStepper2.step(stepsPerRevolutionS); 
  }
}
        
  lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter a Number!");
  mv++;  
}

//************************************************************  3rd Position  **********************************************************//
    if (customKey == '3')                                 
    {
       myStepper1.step(5500);                              // Go To Position 3
       delay(1000);
  
       myStepper2.step(-700);  
      delay(1000);
      
      int statusSensor = digitalRead (IRSensor);                // Sensor Checking
      if (statusSensor == 0){
        lcd.clear();
        Serial.print("HIGH-   No Obstacle/Black Surface\n");
        lcd.print(" Continue! ");
        lcd.setCursor(0, 0); 
      
    
        myservo.write(180);                                 // Turn Servo Right to 180 degrees
        delay(1000);
  
        
        StepsRequired  =  (3*- STEPS_PER_OUT_REV)/2;              // Rotate CCW 1/2 turn Forward
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
        delay(1000);
  
        myservo.write(125);                                 // Turn Servo Right to 155 degrees
        delay(1000);                                         
  
        myStepper2.step(-70);                                // Upward
        delay(1000);
        
        
        StepsRequired  =  (3*STEPS_PER_OUT_REV)/2;           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);

          
        while(digitalRead(LimitX) == HIGH)  {
        Serial.println("clockwise");
        myStepper1.step(-stepsPerRevolution);
        }
        while(digitalRead (LimitY) == HIGH){
        myStepper2.step(stepsPerRevolutionS); 
  }
        StepsRequired  =  (2*- STEPS_PER_OUT_REV);              // Rotate CCW 1/2 turn Forward
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
        delay(1000);

        myservo.write(180);                                    // Turn Servo Right to 180 degrees
        delay(1000);

        StepsRequired  =  (2*STEPS_PER_OUT_REV);               // Rotate CCW 1/2 turn Forward
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
        delay(1000);
    }

        else{
        Serial.print("LOW-    Obstacle Detected/White Surface\n"); 
        lcd.clear();
        lcd.print(" Empty! ");
        lcd.setCursor(0, 0);

         while(digitalRead(LimitX) == HIGH)  {
         Serial.println("clockwise");
         myStepper1.step(-stepsPerRevolution);
  }
        while(digitalRead (LimitY) == HIGH){
        myStepper2.step(stepsPerRevolutionS); 
  }
}
  
  lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter a Number!");
  mv++;  
}


//************************************************************  4th Position  **********************************************************//
    if (customKey == '4')                                 
    {
      int statusSensor = digitalRead (IRSensor1);                // Sensor Checking
      if (statusSensor == 1){
        Serial.print("Empty!");
        lcd.clear();
        lcd.print("Empty!");
      }
      else
      {
        lcd.clear();
        lcd.print("Product!");
       myStepper1.step(3500);                                   // Go To Position 4
       delay(1000);
  
       myStepper2.step(-700);  
        delay(1000);
      
      int statusSensor = digitalRead (IRSensor);                // Sensor Checking
      if (statusSensor == 0){
        lcd.clear();
        Serial.print("HIGH-   No Obstacle/Black Surface\n");
        lcd.print(" Continue! ");
        lcd.setCursor(0, 0); 
      
    
        myservo.write(180);                                 // Turn Servo Right to 180 degrees
        delay(1000);
  
        
        StepsRequired  =  (3*- STEPS_PER_OUT_REV)/2;              // Rotate CCW 1/2 turn Forward
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
        delay(1000);
  
        myservo.write(125);                                 // Turn Servo Right to 155 degrees
        delay(1000);                                         
  
        myStepper2.step(-70);                                // Upward
        delay(1000);
        
        
        StepsRequired  =  (3*STEPS_PER_OUT_REV)/2;           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
  
          
        while(digitalRead(LimitX) == HIGH)  {
        Serial.println("clockwise");
        myStepper1.step(-stepsPerRevolution);
        }
        while(digitalRead (LimitY) == HIGH){
        myStepper2.step(stepsPerRevolutionS); 
  }

        StepsRequired  =  (2*-STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
        
        myservo.write(180);                                 // Turn Servo Right to 180 degrees
        delay(1000);
        
        StepsRequired  =  (2*STEPS_PER_OUT_REV);           // Rotate CW 1/2 turn Backward 
        steppermotor.setSpeed(700);   
        steppermotor.step(StepsRequired);
        delay(1000);
      }

      else{
        Serial.print("LOW-    Obstacle Detected/White Surface\n"); 
        lcd.clear();
        lcd.print(" Empty! ");
        lcd.setCursor(0, 0);

         while(digitalRead(LimitX) == HIGH)  {             // Homing
         Serial.println("clockwise");
         myStepper1.step(-stepsPerRevolution);
  }
        while(digitalRead (LimitY) == HIGH){
        myStepper2.step(stepsPerRevolutionS); 
  }
          }
  
  lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter a Number!");
  mv++;  
}
}

 //************************************************************  Home Position  **********************************************************//
 
if (customKey == 'C')                                  
    { 
      while(digitalRead(LimitX) == HIGH)  {
  Serial.println("clockwise");
  myStepper1.step(-stepsPerRevolution);
  }
while(digitalRead (LimitY) == HIGH){
   myStepper2.step(stepsPerRevolutionS); 
  }
lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("Enter a Number!");
    mv++;
}
}
