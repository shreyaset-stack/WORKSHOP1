#define LED 2
#define BUTTON 4

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {

  while (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED, HIGH);
  }

  digitalWrite(LED, LOW);
}