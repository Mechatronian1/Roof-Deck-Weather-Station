#include <Arduino.h>
#include <WiFiNINA.h>
#include <Firebase_Arduino_WiFiNINA.h>
#include <credentials.h>

const char* ssid = "TP Link";
const char* password = "tryandguess";



void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to Wi-Fi");
}

void loop() {
  //Serial.println("Hello World");
  delay(1000);
}
