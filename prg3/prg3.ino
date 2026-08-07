// Define the ESP32 pin connected to the IR sensor
const int irSensorPin = 14; 

void setup() {
  // Initialize serial communication at 115200 baud rate
  Serial.begin(115200);
  
  // Configure the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
  
  delay(1000); 
}

void loop() {
  // Read the digital value from the sensor
  int sensorValue = digitalRead(irSensorPin);
  
  // Print only the raw value (0 or 1) to a new line
  Serial.println(sensorValue);
  
  // Delay to slow down the data stream slightly
  delay(100);
}