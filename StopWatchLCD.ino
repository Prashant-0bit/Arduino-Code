//Jay Raut Jean Augustine Secondary
//January 13 2020
//625549@pdsb.net
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int LED2 = 6;
const int LED3 = 5;

void setup()
{
lcd.init();//initializes the LCD
lcd.backlight();//turns on backlight
pinMode(8, INPUT);//setting up Pins on arduino for output and input from leds and buttons
digitalWrite(8, HIGH);
pinMode(9, INPUT);
digitalWrite(9, HIGH);
pinMode(2, OUTPUT);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
pinMode(3, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}
double i = 0;//variables for recording time
double a = millis();
double c ;

void loop()
{
lcd.clear();
lcd.print("press the button");
digitalWrite(LED3, HIGH);
digitalWrite(LED2, HIGH);

 if(digitalRead(8) == LOW)//clears LCD when button is pressed
 {
    lcd.clear();
    a = millis();

   while(digitalRead(9) == HIGH)
   {
   c = millis();//function to start recording when the button was pressed to print on the LCD
   i = (c - a) / 1000;
   lcd.print(i);
   lcd.setCursor(7,0);
   lcd.print("Seconds");
   lcd.setCursor(0,0);
   digitalWrite(2, HIGH);//turns on green led
   digitalWrite(3, LOW);//turns off red led
   }
   if(digitalRead(9) == LOW)
   {
     while(digitalRead(8) == HIGH)//if other button is pressed then clear the LCD
     {
       lcd.setCursor(0,0);

       lcd.setCursor(11,0);
       lcd.print("");
       lcd.setCursor(0,0);
          digitalWrite(2, LOW);//turn off the green led
          digitalWrite(3, HIGH);//turn on the red led
     }
   }
 }
}
