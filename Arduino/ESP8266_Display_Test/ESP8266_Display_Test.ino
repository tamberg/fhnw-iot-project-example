#include "TM1637.h"

#define CLK 5
#define DIO 4

TM1637 tm1637(CLK,DIO);

void setup() {
  tm1637.set();
  tm1637.init();
}

void displayBytes(int8_t *bytes) {
  tm1637.display(bytes);
  delay(500);
}

void loop() {
  int8_t b[] = { 0x00, 0x00, 0x00, 0x00 };
  for (int i = 0; i < 255; i++) {
    b[0] = i;
    b[1] = i % 1000 / 100;
    b[2] = i % 100 / 10;
    b[3] = i % 10;
    displayBytes(b);
  }
}
