#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial ESP01(15,14);
void setup() {
  Serial.begin(9600);
  ESP01.begin(115200);
  // put your setup code here, to run once:
}

void loop() {
  while(ESP01.available()){
    ESP01.readString();
  }
  // put your main code here, to run repeatedly:
}