#include <Arduino.h>
#include <WiFiNINA.h>
#include <Firebase_Arduino_WiFiNINA.h>
#include <credentials.h>

FirebaseData firebasedata;

void setup() {
  //Initialize serial connection
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  //Begin wifi connection
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  //Connect to Firebase RTDB
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASS);

if (Firebase.setFloat(firebasedata, "/temperature/day_time", 123.456789)){

  //Success, then read the payload value return from server
  //This confirmed that your data was set to database as float number

  if (firebasedata.dataType() == "float")
    Serial.println(firebasedata.floatData());

} else {
  //Failed, then print out the error detail
    Serial.println(firebasedata.errorReason());
}

}

void loop() {
  //Serial.println("Hello World");
  delay(1000);
}
