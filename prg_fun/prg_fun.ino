#define LED1 2
#define LED2 19

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);   // Start serial communication
}

void loop()
{
  Serial.println("Hi");
  blinkLED(LED1, 500);
  Serial.println("Hello World");
  blinkLED(LED2, 1000);

}

void blinkLED(int pin, int delay_value)
{
  digitalWrite(pin, HIGH);
  delay(delay_value);
  digitalWrite(pin, LOW);
  delay(delay_value);
}