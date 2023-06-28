#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // Read the incoming data as a string
    String jsonString = Serial.readStringUntil('\n');

    // Parse the JSON string
    StaticJsonDocument<200> jsonDoc;
    DeserializationError error = deserializeJson(jsonDoc, jsonString);

    if (error) {
      Serial.print("Parsing failed: ");
      Serial.println(error.c_str());
      return;
    }

    // Access the data from the JSON object
    String sensorValue1 = jsonDoc["sensorValue1"];
    String sensorValue2 = jsonDoc["sensorValue2"];

    // Do something with the data
    Serial.print("sensorValue1: ");
    Serial.println(sensorValue1);
    Serial.print("sensorValue2: ");
    Serial.println(sensorValue2);
  }
}

