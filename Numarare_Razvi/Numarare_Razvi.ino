#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include "SevSeg.h"


SevSeg sevseg;
unsigned int val = 0;
//unsigned int num = 0;
unsigned int m = 8;
unsigned int s = 8;
unsigned int z = 8;
unsigned int u = 8;
unsigned int caret = 1;

const int RECV_PIN = 1;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  //  irrecv.blink13(true);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
//    if (results.value == 0xFFFFFF) {
//      results.value = val;
//    }
    Serial.println(results.value);
    switch (results.value) {
      //CH-
      case 0xFFA25D:
        if (caret - 1 >= 1) {
          caret--;
        }
        break;
      //CH+
      case 0xFF629D:
        if (caret + 1 <= 4) {
          caret++;
        }
        break;
      //+
      case 0xFFA857:
        switch (caret) {
          case 4:
            m += 1;
            m %= 10;
            break;
          case 3:
            s += 1;
            s %= 10;
            break;
          case 2:
            z += 1;
            z %= 10;
            break;
          case 1:
            u += 1;
            u %= 10;
            break;
        }
        break;
      //-
      case 0xFFE01F:
        switch (caret) {
          case 4:
            m -= 1;
            m %= 10;
            break;
          case 3:
            s -= 1;
            s %= 10;
            break;
          case 2:
            z -= 1;
            z %= 10;
            break;
          case 1:
            u -= 1;
            u %= 10;
            break;
        }
        break;
    }
  }

  sevseg.setNumber(m * 1000 + s * 100 + z * 10 + u, caret);
  sevseg.refreshDisplay();
}
