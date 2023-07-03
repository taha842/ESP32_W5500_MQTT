#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Ethernet settings
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // MAC address of W5500 module
IPAddress ip(192, 168, 0, 10); // IP address of ESP32
EthernetClient tahaClient;

// MQTT settings
const char* mqttServer = "192.168.0.125"; // MQTT broker IP address or hostname
const int mqttPort = 1883; // MQTT broker port
const char* clientId = "Taha842"; // Unique identifier for the ESP32 client
const char* subscribeTopic = "sensor/data"; // MQTT topic to subscribe to
const char* publishTopic = "actuator/control"; // MQTT topic to publish to
const char* mqttUsername = "Taha842"; // MQTT broker username (if required)
const char* mqttPassword = "123456"; // MQTT broker password (if required)

// Initialize Ethernet and MQTT client objects
EthernetClient tahaClient;
PubSubClient mqttClient(tahaClient);

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming MQTT messages here
  Serial.println("Message received:");
  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (mqttClient.connect(clientId, mqttUsername, mqttPassword)) {
      Serial.println("Connected to MQTT broker");
      mqttClient.subscribe(subscribeTopic);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize Ethernet connection
  Ethernet.begin(mac, ip);

  // Initialize MQTT client
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(callback);
}

void loop() {
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();

  // Publish a test message every 5 seconds
  static unsigned long lastPublishTime = 0;
  if (millis() - lastPublishTime > 5000) {
    lastPublishTime = millis();
    mqttClient.publish(publishTopic, "Hello from Taha842!");
  }
}
