#include <ArduinoJson.h>

// Create a JSON object
StaticJsonDocument<200> jsonDoc;

void setup() {
  Serial.begin(9600); // Set baud rate to match the NodeMCU
}

void loop() {

  // Add data to the JSON object
  jsonDoc["sensorValue1"] = random(100);
  jsonDoc["sensorValue2"] = random(200);

  // Convert the JSON object to a string
  String jsonString;
  serializeJson(jsonDoc, jsonString);

  // Send the JSON string over serial
  Serial.println(jsonString);

  delay(1000);
  
}
