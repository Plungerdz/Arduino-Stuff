#include <dht.h>
#include<LiquidCrystal.h>

LiquidCrystal LCD (12, 11, 5, 4, 3, 2);
dht DHT;

char txt[] = "ADSD";

void setup() {
  
LCD.begin(16,2);
LCD.print("ceva");

}

void loop() {
  int val = DHT.read11(7);
  delay(1000);
  //LCD.autoscroll();
  //LCD.setCursor(13,0);
  //for (int i=0; i<4; i++) {
  //  LCD.print(txt[i]);
  //  delay(500);
  //}
  LCD.noDisplay();
  LCD.setCursor(0,0); 
  LCD.print("Temp: ");
  LCD.print(DHT.temperature);
  LCD.print((char)223);
  LCD.print("C");
  LCD.setCursor(0,1);
  LCD.print("Humidity: ");
  LCD.print(DHT.humidity);
  LCD.print("%");  
  LCD.display();
  delay(500);
}
