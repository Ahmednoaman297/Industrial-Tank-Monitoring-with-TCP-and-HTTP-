#include <WiFi.h>


#define TRIG_PIN  4  // Define GPIO pin for TRIG
#define ECHO_PIN  5  // Define GPIO pin for ECHO
#define MAX_DISTANCE 400 // Maximum distance to measure (in cm)

const char* ssid = "WEF5EBDC";     //WE_4EA8C0
const char* password = "AasiM@#$1967";    //d0287d6e
const char* serverIP = "192.168.1.2"; // Replace with Raspberry Pi's IP
const uint16_t serverPort = 12345;


WiFiClient client;


void setup() {
  Serial.begin(115200);
  Serial.println("b7bk");
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  analogReadResolution(12);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    if (millis() - startAttemptTime > 20000) {
      Serial.println("\nFailed to connect to WiFi.");
      return;
    }
  }
  Serial.println("\nConnected to WiFi.");
  Serial.println(WiFi.localIP()); 

while(1)
{
  if (!client.connected()) 
  {
    Serial.println("Connecting to server...");


    if (client.connect(serverIP, serverPort)) 
    {
      Serial.println("Connected to server.");
      break;
    } 
    else 
    {
      Serial.println("Connection failed. Retrying...");
      //delay(100);
    }
  }

}
}

void loop() {

 //int distance = analogRead(2);
digitalWrite(TRIG_PIN,LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN,HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN,LOW);

long duration = pulseIn(ECHO_PIN,HIGH);
float distance = duration * 0.0344/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (!client.connected()) {
    Serial.println("Connecting to server...");
    if (client.connect(serverIP, serverPort)) {
      Serial.println("Connected to server.");
    } 
    else {
      Serial.println("Connection failed. Retrying...");
      delay(5000);
      return;
    }
  }
  if (distance>1000)
  {
  // Send data
  String data = "{\"tank_level\": " + String(distance) + ", \"status\": \"NOT_OK\"}";  // Format as JSON
  client.println(data);
  Serial.println("Data sent: " + data);


  }
  else
  {
      // Send data
  String data = "{\"tank_level\": " + String(distance) + ", \"status\": \"OK\"}";  // Format as JSON
  client.println(data);
  Serial.println("Data sent: " + data);

  }

  delay(1000);
}