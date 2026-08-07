const int pin = 26;
void setup() {
Serial.begin(9600);
pinMode(pin, INPUT);// Start serial communication
}
void loop() {
int sen_val = digitalRead(pin);
Serial.print("Value: ");
Serial.println(sen_val);
delay(500);
}