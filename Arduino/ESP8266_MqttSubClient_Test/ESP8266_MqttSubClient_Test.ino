#include <ESP8266WiFi.h> // v2.4.2
#include <ESP8266MQTTClient.h> // v1.0.4

const char *ssid = "MY_SSID"; // TODO
const char *password = "MY_PASSWORD"; // TODO
const char *mqttBrokerHost = "mqtt.thingspeak.com:1883";
const char *mqttUser = "esp8266"; // TODO
const char *mqttPassword = "TS_MQTT_API_KEY"; // TODO
const char *channelId = "TS_CHANNEL_ID"; // TODO
const char *readApiKey = "TS_READ_API_KEY"; // TODO

char mqttBrokerUri[64];
char topic[64];
MQTTClient client;

void handleConnected() {
  Serial.println("Connected to broker");
  sprintf(topic, "channels/%s/subscribe/json/%s", channelId, readApiKey);
  Serial.print("Subscribing to ");
  Serial.println(topic);
  client.subscribe(topic);
}

void handleSubscribed(int topicId) {
  Serial.println("Subscribed");
}

void handleDataReceived(String topic, String data, bool b) {
  Serial.print("Received topic: ");
  Serial.print(topic);
  Serial.print(", data: ");
  Serial.println(data);
}

void setup() {
  Serial.begin(115200);
  Serial.print("\nConnecting to network ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100); // keeps watchdog happy
  }
  Serial.print("Connected to network, local IP = "); 
  Serial.println(WiFi.localIP());

  client.onConnect(handleConnected);
  client.onSubscribe(handleSubscribed);
  client.onData(handleDataReceived);
  sprintf(mqttBrokerUri, "mqtt://%s:%s@%s/", mqttUser, mqttPassword, mqttBrokerHost);
  Serial.print("Connecting to ");
  Serial.println(mqttBrokerUri);
  client.begin(mqttBrokerUri);
}

void loop() {
  client.handle();
}
