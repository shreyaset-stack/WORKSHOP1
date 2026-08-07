#define LED1 2
#define LED2 19

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop()
{
  blinkLED();
}

void blinkLED()
{
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);
  delay(1000);
  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);
  delay(1000);
}