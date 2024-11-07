#include <Wire.h>
String message1 = "";
String message2 = "";
bool newMessage = false;

void setup(){
  Wire.begin(0);
  Wire.onReceive(receive);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0) {
    message2 = Serial.readStringUntil('\n');

    Wire.beginTransmission(8);
    Wire.write(message2.c_str());
    Wire.endTransmission();
    delay(100);
  }

  if (newMessage) {
    Serial.println(message1);
    newMessage = false;  // Reset flag after printing
  }
}

void receive(int bytes) {
  message1 = "";  
  while(Wire.available() > 0) {
    char c = Wire.read();
    message1 += c;
  }
  newMessage = true;  // Set flag to indicate a new message has been received
}
