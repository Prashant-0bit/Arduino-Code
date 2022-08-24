

int IRSensor = 22; // connect ir sensor to arduino pin 7

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1){
   
    Serial.print("HIGH-   No Obstacle/Black Surface\n");
   
  }
  else
   {
    Serial.print("LOW-    Obstacle Detected/White Surface\n"); 
     
}
}
