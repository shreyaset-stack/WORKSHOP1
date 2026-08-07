const int led=26;// Initialize pin 13 for an LED
void setup() {
  pinMode(led, OUTPUT); 
}
void loop() {
  digitalWrite(led, HIGH); // Turn LED on
  delay(1000);            // Wait 1 second
  digitalWrite(led, LOW);  // Turn LED off
  delay(1000);            // Wait 1 second
}

