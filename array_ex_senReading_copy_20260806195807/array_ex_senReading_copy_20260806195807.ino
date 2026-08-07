// ESP32 Analog IR Sensor Reading using Array

const int sensorPins[] = {19,21};   // Analog pins connected to IR sensors
const int numSensors = 2;

void setup() {
  Serial.begin(115200);

  // Set sensor pins as input
  for (int i = 0; i <=numSensors; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  int sensorValues[numSensors];

  // Read all sensor values
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = digitalRead(sensorPins[i]);
  }

  // Print sensor values
  Serial.print("IR1: ");
  Serial.print(sensorValues[0]);
  Serial.print("\tIR2: ");
  Serial.println(sensorValues[1]);

  delay(200);
}




