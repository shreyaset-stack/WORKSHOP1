// Define the pins
const int ledPin = 2;     // LED connected to GPIO 2
const int buttonPin = 4;  // Push button connected to GPIO 4

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Set the button pin as an input with an internal pull-up resistor
  // This keeps the pin HIGH by default and goes LOW when pressed
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the current state of the button
  int buttonState = digitalRead(buttonPin);

  // If condition to check button press
  // Using INPUT_PULLUP, LOW means the button is being pressed
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }
}






