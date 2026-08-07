#include <WiFi.h>
#include <WebServer.h>

//=============== WiFi Credentials =================
const char* ssid = "Nothing2a";
const char* password = "123456789S";

//=============== Web Server =======================
WebServer server(80);

//=============== Motor Pins =======================
// Left Motor
const int ENA = 26;
const int IN1 = 25;
const int IN2 = 33;

// Right Motor
const int ENB = 14;
const int IN3 = 32;
const int IN4 = 13;

// PWM Channels
const int ch1 = 0;
const int ch2 = 1;

int speedValue = 200;

//==================================================
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  ledcWrite(ch1, 0);
  ledcWrite(ch2, 0);

  Serial.println("STOP");
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  ledcWrite(ch1, speedValue);
  ledcWrite(ch2, speedValue);

  Serial.println("FORWARD");
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  ledcWrite(ch1, speedValue);
  ledcWrite(ch2, speedValue);

  Serial.println("BACKWARD");
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  ledcWrite(ch1, speedValue);
  ledcWrite(ch2, speedValue);

  Serial.println("LEFT");
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  ledcWrite(ch1, speedValue);
  ledcWrite(ch2, speedValue);

  Serial.println("RIGHT");
}

//================ HTML PAGE =======================
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body{
font-family:Arial;
background:#222;
color:white;
text-align:center;
}
button{
width:120px;
height:70px;
font-size:22px;
margin:10px;
border-radius:10px;
background:#2196F3;
color:white;
border:none;
}
button:hover{
background:#1976D2;
}
.slider{
width:250px;
}
</style>
</head>

<body>

<h2>ESP32 RC CAR</h2>

<button onclick="send('forward')">Forward</button>
<br>
<button onclick="send('left')">Left</button>
<button onclick="send('stop')">Stop</button>
<button onclick="send('right')">Right</button>
<br>
<button onclick="send('backward')">Backward</button>

<h3>Speed</h3>

<input type="range"
min="0"
max="255"
value="200"
class="slider"
onchange="speed(this.value)">

<script>

function send(cmd){
fetch('/'+cmd);
}

function speed(val){
fetch('/speed?value='+val);
}

</script>

</body>
</html>
)rawliteral";

//==================================================
void handleRoot() {
  server.send(200, "text/html", webpage);
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP32 RC CAR STARTING...");
  Serial.println("==============================");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  ledcSetup(ch1, 5000, 8);
  ledcAttachPin(ENA, ch1);

  ledcSetup(ch2, 5000, 8);
  ledcAttachPin(ENB, ch2);

  stopCar();

  Serial.println("Creating WiFi Access Point...");

  WiFi.softAP(ssid, password);

  delay(1000);

  Serial.print("SSID : ");
  Serial.println(ssid);

  Serial.print("Password : ");
  Serial.println(password);

  Serial.print("IP Address : ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);

  server.on("/forward", []() {
    forward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/backward", []() {
    backward();
    server.send(200, "text/plain", "OK");
  });

  server.on("/left", []() {
    left();
    server.send(200, "text/plain", "OK");
  });

  server.on("/right", []() {
    right();
    server.send(200, "text/plain", "OK");
  });

  server.on("/stop", []() {
    stopCar();
    server.send(200, "text/plain", "OK");
  });

  server.on("/speed", []() {
    if (server.hasArg("value")) {
      speedValue = server.arg("value").toInt();
      Serial.print("Speed = ");
      Serial.println(speedValue);
    }
    server.send(200, "text/plain", "OK");
  });

  server.begin();

  Serial.println("Web Server Started");
  Serial.println("Open Browser:");
  Serial.println("http://192.168.4.1");
}

void loop() {
  server.handleClient();
}