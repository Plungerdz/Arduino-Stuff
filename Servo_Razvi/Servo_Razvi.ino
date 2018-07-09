
#include <Servo.h> 

int servoPin = 13; 
int sensorValue = 0;

Servo Servo1; 

void setup() { 
  
   Servo1.attach(servoPin);
   pinMode(A0,INPUT); 
}
void loop(){ 
   
   sensorValue = analogRead(A0);
   Servo1.write(sensorValue); 
   delay(1000);
}
