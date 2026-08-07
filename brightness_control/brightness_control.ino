// ESP32 LED Brightness Control using PWM

const int ledPin = 26;

// PWM Configuration
const int freq = 5000;
const int channel = 0;
const int resolution = 8;   // 8-bit (0-255)

void setup() {
  ledcAttach(ledPin, freq, resolution);
}

void loop() {

  // Increase brightness
  for (int brightness = 0; brightness <= 255; brightness++) {
    ledcWrite(ledPin, brightness);
    delay(10);
  }

}

