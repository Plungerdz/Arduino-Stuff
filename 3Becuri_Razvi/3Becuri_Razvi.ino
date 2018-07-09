#include <SoftwareSerial.h>

int loopCount=0;

void setup()
{
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  loopCount++;
  digitalWrite(10+loopCount%3, HIGH);
  delay(500);
  Serial.println("--------");
  Serial.println("loopCount:");
  Serial.println(loopCount);
  Serial.println("12:");
  Serial.println(digitalRead(12));
  Serial.println("11:");
  Serial.println(digitalRead(11));
  Serial.println("10:");
  Serial.println(digitalRead(10));
  Serial.println("--------");
  digitalWrite(10+loopCount%3, LOW);
  delay(500);
  Serial.println("--------");
  Serial.println("loopCount:");
  Serial.println(loopCount);
  Serial.println("12:");
  Serial.println(digitalRead(12));
  Serial.println("11:");
  Serial.println(digitalRead(11));
  Serial.println("10:");
  Serial.println(digitalRead(10));
  Serial.println("--------");
}
