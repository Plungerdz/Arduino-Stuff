#include <SoftwareSerial.h>

int sensorValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue>=200) 
    digitalWrite(13, LOW);
  else
    digitalWrite(13, HIGH);
  delay(100);
}
