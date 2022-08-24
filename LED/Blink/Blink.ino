#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int led = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
const int led5 = 8;
const int led6 = 9;
const int led7 = 10;
const int led8 = 11;

const int BUTTON = 2;
int BUTTONstate = 1;
const int BUTTON1 = 7;
int BUTTONstate1 = 1;

void setup() {
lcd.init();
lcd.clear();
lcd.backlight(); 
lcd.print("System Start");          // Input Entry For Display
lcd.setCursor(0,0); 
  
pinMode(BUTTON, INPUT);
pinMode(BUTTON1, INPUT);

pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
pinMode(led8, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  BUTTONstate = digitalRead(BUTTON);
  if (BUTTONstate == LOW)
  {
    lcd.setCursor(0, 0);
    lcd.print("Button-1 Pressed!");
    lcd.setCursor(0, 1);
    lcd.print(" LED Blinking ");
    
    digitalWrite(led, HIGH); // turn the LED on (HIGH is the voltage level)
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(100);
    
    digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(100);// wait for a second
}
lcd.clear();
 
  BUTTONstate1 = digitalRead(BUTTON1);
  if (BUTTONstate1 == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("Button-2 Pressed!");
    lcd.setCursor(0, 1);
    lcd.print(" LED Blinking ");
    
    digitalWrite(led5, HIGH); // turn the LED on (HIGH is the voltage level)
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    delay(100);
    
    digitalWrite(led5, LOW); // turn the LED off by making the voltage LOW
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    delay(100);// wait for a second
}

else{
digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW); // turn the LED off by making the voltage LOW
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);
digitalWrite(led8, LOW);
  }
}
