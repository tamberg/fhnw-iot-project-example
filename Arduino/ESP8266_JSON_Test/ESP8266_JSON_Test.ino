#include <Arduino_JSON.h>

void setup() {
  Serial.begin(115200);
  char * json = 
    "{"
      "\"channel_id\":0,"
      "\"created_at\":\"2019-04-22T15:44:18Z\","
      "\"entry_id\":2706,"
      "\"field1\":\"23\","
      "\"field2\":\"36\","
      "\"latitude\":null,"
      "\"longitude\":null,"
      "\"elevation\":null,"
      "\"status\":null"
    "}";
  Serial.println(json);
  JSONVar obj = JSON.parse(json);
  Serial.println(JSON.typeof(obj));
  const char *field1 = obj["field1"];
  Serial.println(field1);
  double temp = atof(field1);
  Serial.println(temp);
  const char *field2 = obj["field2"];
  Serial.println(field2);
  double humi = atof(field2);
  Serial.println(humi);
}

void loop() {}
