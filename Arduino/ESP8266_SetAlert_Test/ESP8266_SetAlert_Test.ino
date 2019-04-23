#include "TM1637.h"

#define DISPLAY_CLK 5
#define DISPLAY_DIO 4
#define BUZZER_PIN 2
#define BUTTON_PIN 0
#define ENCODER_PIN A0

#define SHOW_TEMP_STATE 0
#define SHOW_HUMI_STATE 1
#define SET_TEMP_STATE 2
#define SET_HUMI_STATE 3

TM1637 tm1637(DISPLAY_CLK, DISPLAY_DIO);
int state = 0;
int temp = 0;
int humi = 0;

void setup() {
  Serial.begin(115200);
  tm1637.set();
  tm1637.init();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int rawValue = analogRead(ENCODER_PIN);
  int value = map(rawValue, 0, 1024, 0, 99);
  int pressed = digitalRead(BUTTON_PIN);
  Serial.print("rawValue = ");
  Serial.print(rawValue);
  Serial.print(", value = ");
  Serial.print(value);
  Serial.print(", pressed = ");
  Serial.print(pressed);
  Serial.print(", state = ");
  Serial.println(state);
  if (state == SHOW_TEMP_STATE) {
    if (pressed) {
        state = SET_TEMP_STATE;
    } else {
        int8_t b[] = { 0x0c, 0x7F, 0x00, 0x00 };
        b[2] = temp % 100 / 10;
        b[3] = temp % 10;
        tm1637.display(b);
        delay(1000);
        state = SHOW_HUMI_STATE;
    }
  } else if (state == SHOW_HUMI_STATE) {
    if (pressed) {
        state = SET_HUMI_STATE;
    } else {
        int8_t b[] = { 0x7F, 0x7F, 0x00, 0x00 };
        b[2] = humi % 100 / 10;
        b[3] = humi % 10;
        tm1637.display(b);
        delay(1000);
        state = SHOW_TEMP_STATE;        
    }
  } else if (state == SET_TEMP_STATE) {
    if (pressed) {
      temp = value;
      int8_t b[] = { 0x0c, 0x7F, 0x00, 0x00 };
      b[2] = temp % 100 / 10;
      b[3] = temp % 10;
      tm1637.display(b);
      delay(100);
    } else {
      state = SHOW_TEMP_STATE;
    }
  } else if (state == SET_HUMI_STATE) {
    if (pressed) {
      humi = value;
      int8_t b[] = { 0x7F, 0x7F, 0x00, 0x00 };
      b[2] = humi % 100 / 10;
      b[3] = humi % 10;
      tm1637.display(b);
      delay(100);
    } else {
      state = SHOW_HUMI_STATE;
    }
  }
  Serial.print("temp = ");
  Serial.print(temp);
  Serial.print(", humi = ");
  Serial.println(humi);
}
