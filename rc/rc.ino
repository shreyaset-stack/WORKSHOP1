/*************************************************
 * ESP32 + L298N + Blynk RC Car
 *************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3b57Vs8Dt"
#define BLYNK_TEMPLATE_NAME "RCC Car"
#define BLYNK_AUTH_TOKEN "5t6HmgMyRJlK6pIzZ-nJc81UBAePVHnN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi Credentials
char ssid[] = "Moto";
char pass[] = "123456789K";

// L298N Pins
#define IN1 25
#define IN2 33
#define IN3 12
#define IN4 14

#define ENA 26
#define ENB 32

// PWM Configuration
#define PWM_CHANNEL_A 0
#define PWM_CHANNEL_B 1
#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define MOTOR_SPEED 200

//=============================
// Motor Functions
//=============================

void stopCar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//=============================
// Blynk Buttons
//=============================

// Forward
BLYNK_WRITE(V0)
{
  if (param.asInt())
    forward();
  else
    stopCar();
}

// Backward
BLYNK_WRITE(V1)
{
  if (param.asInt())
    backward();
  else
    stopCar();
}

// Left
BLYNK_WRITE(V2)
{
  if (param.asInt())
    left();
  else
    stopCar();
}

// Right
BLYNK_WRITE(V3)
{
  if (param.asInt())
    right();
  else
    stopCar();
}

//=============================
// Setup
//=============================

void setup()
{
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configure PWM
  ledcSetup(PWM_CHANNEL_A, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(ENA, PWM_CHANNEL_A);

  ledcSetup(PWM_CHANNEL_B, PWM_FREQ, PWM_RESOLUTION);
  ledcAttachPin(ENB, PWM_CHANNEL_B);

  // Set Speed
  ledcWrite(PWM_CHANNEL_A, MOTOR_SPEED);
  ledcWrite(PWM_CHANNEL_B, MOTOR_SPEED);

  stopCar();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Blynk Connected");
}

//=============================
// Main Loop
//=============================

void loop()
{
  Blynk.run();
}