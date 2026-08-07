void setup() {
  Serial.begin(9600); // Start communication at 9600 baud rate
}

void loop() {
  Serial.print("Hello world!"); 
  delay(500);
}
