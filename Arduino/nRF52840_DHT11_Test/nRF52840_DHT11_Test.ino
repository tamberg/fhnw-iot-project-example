// Test code for Grove DHT11 humidity/temperature sensor on nRF52840

// https://github.com/tamberg/fhnw-iot/wiki/Grove-Sensors#temperature--humidity-sensor-dht11
// https://github.com/tamberg/fhnw-iot/wiki/Feather-nRF52840-Express
// https://github.com/tamberg/fhnw-iot/wiki/Grove-Adapters#pinout

// Based on example code written by ladyada, public domain

#include "DHT.h"

// D2 on Grove Adapter is nRF52850 pin D5
#define DHTPIN 5 // pin D5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 test");

  dht.begin();
}

void loop() {
  // Readings take about 250 ms, may be up to 2 s old
  float h = dht.readHumidity(); // %
  float t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT11 sensor");
  } else {
    Serial.print(h);
    Serial.print(" %, ");
    Serial.print(t);
    Serial.println(" *C");
  }

  delay(2000); // ms
}
