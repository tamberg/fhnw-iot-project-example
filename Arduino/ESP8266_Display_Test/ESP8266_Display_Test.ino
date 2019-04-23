#include "TM1637.h"

#define CLK 5
#define DIO 4

TM1637 tm1637(CLK,DIO);

void setup() {
  tm1637.set();
  tm1637.init();
  int8_t displayBytes[] = { 0x01, 0x02, 0x03, 0x04 };
  tm1637.display(displayBytes);
}

void loop() {}
