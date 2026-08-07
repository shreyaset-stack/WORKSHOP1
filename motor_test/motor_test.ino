//======================================
// ESP32 + L298N RC Car Test
//======================================

// Left Motor
const int ENA = 26;
const int IN1 = 25;
const int IN2 = 33;

// Right Motor
const int ENB = 14;
const int IN3 = 32;
const int IN4 = 13;

void setup()
{
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Full Speed
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  stopCar();

  Serial.println("RC Car Test Started");
}

void loop()
{
  Serial.println("FORWARD");
  forward();
  delay(2000);

  stopCar();
  delay(1000);

  Serial.println("BACKWARD");
  backward();
  delay(2000);

  stopCar();
  delay(1000);

  Serial.println("LEFT");
  left();
  delay(2000);

  stopCar();
  delay(1000);

  Serial.println("RIGHT");
  right();
  delay(2000);

  stopCar();
  delay(2000);
}

//==========================

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  // Left motor reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}