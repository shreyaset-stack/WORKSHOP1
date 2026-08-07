#define BLYNK_TEMPLATE_ID "TMPL3KAQpCfxq"
#define BLYNK_TEMPLATE_NAME "espb"
#define BLYNK_AUTH_TOKEN "ztLofLPZtArb42fD04XqBSLAOZ58HptZ"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// Your WiFi credentials
char ssid[] = "";
char pass[] = "";

const int ledPin = 2; // Pin for the built-in LED on most ESP32 boards

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
}

// This function is triggered whenever the V0 datastream changes state in the app/web
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // Get the value from the virtual pin (0 or 1)
  
  if (pinValue == 1) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    Serial.println("Light turned ON");
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED off
    Serial.println("Light turned OFF");
  }
}