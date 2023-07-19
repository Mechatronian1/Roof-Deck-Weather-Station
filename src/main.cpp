#include <Arduino.h>
#include <WiFiNINA.h>
#include <Firebase_Arduino_WiFiNINA.h>
#include <credentials.h>
#include <RTCZero.h>

FirebaseData firebasedata;
RTCZero rtc;

const int GMT = 2;

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


  //Initialize RTC Clock
  rtc.begin();
  //rtc.setEpoch(1451606400);

}

//Print digits function for testing time display - likely to be removed later
void print2digits(int number) {
  if (number < 10) {
    Serial.print("0");
  }
  Serial.print(number);
}

void printTime()
{
  print2digits(rtc.getHours() + GMT);
  Serial.print(":");
  print2digits(rtc.getMinutes());
  Serial.print(":");
  print2digits(rtc.getSeconds());
  Serial.println();
}

void printDate()
{
  Serial.print(rtc.getDay());
  Serial.print("/");
  Serial.print(rtc.getMonth());
  Serial.print("/");
  Serial.print(rtc.getYear());
  Serial.print(" ");
}

void loop() {
    printDate();

  printTime();

  Serial.println();

  delay(1000);
/*   //Serial.println("Hello World");
    Serial.print("Unix time = ");
  Serial.println(rtc.getEpoch());

  Serial.print("Seconds since Jan 1 2000 = ");
  Serial.println(rtc.getY2kEpoch());

  // Print date...
  Serial.print(rtc.getDay());
  Serial.print("/");
  Serial.print(rtc.getMonth());
  Serial.print("/");
  Serial.print(rtc.getYear());
  Serial.print("\t");

  // ...and time
  print2digits(rtc.getHours());
  Serial.print(":");
  print2digits(rtc.getMinutes());
  Serial.print(":");
  print2digits(rtc.getSeconds());

  Serial.println();
  delay(1000); */
}


