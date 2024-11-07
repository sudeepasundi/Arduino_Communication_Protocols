#include <Wire.h>

String message1 = "";
String message2 = "";
int address = -1;
String addr = "";
int slaveAddress[] = {2, 8};
int slaveAddress1[10]; // Adjust as per your need
int numSlaves = sizeof(slaveAddress) / sizeof(slaveAddress[0]);

void setup() {
  Wire.begin(5);
  Wire.onReceive(receive);
  Serial.begin(9600);
  Serial.println("Enter the addresses you want to send the message to (enter 0 to broadcast):");
}

void loop() {
  message1 = "";
  int i = 0;

  if (Serial.available() > 0) {
    message2 = Serial.readStringUntil('\n');
    
    if (message2.length() > 0) {
      for (int j = 0; j < message2.length(); j++) {
        char c = message2[j];
        
        if (c != ' ') {
          addr += c;
        } else if (addr != "") {
          address = addr.toInt();
          slaveAddress1[i] = address;
          addr = "";
          i++;
        }
      }

      if (addr != "") {
        address = addr.toInt();
        slaveAddress1[i] = address;
        addr = "";
      }

      Serial.print("Selected slave addresses: ");
      for (int k = 0; k <= i; k++) {
        Serial.print(slaveAddress1[k]);
        Serial.print(" ");
      }
      Serial.println();

      Serial.println("Enter the message to send:");
      
      while (Serial.available() == 0);
      message2 = Serial.readStringUntil('\n');

      if (slaveAddress1[0] == 0) {
        for (int j = 0; j < numSlaves; j++) {
          Wire.beginTransmission(slaveAddress[j]);
          Wire.write(message2.c_str());
          Wire.endTransmission();
          Serial.print("Message broadcasted to slave ");
          Serial.println(slaveAddress[j]);
        }
      } else {
        for (int j = 0; j <= i; j++) {
          Wire.beginTransmission(slaveAddress1[j]);
          Wire.write(message2.c_str());
          Wire.endTransmission();
          Serial.print("Message sent to slave ");
          Serial.println(slaveAddress1[j]);
        }
      }

      message2 = "";  
      Serial.println("Enter new slave addresses (enter 0 to broadcast):");
    }
  }

  delay(100);
}

void receive(int numBytes) {
  message1 = "";

  while (Wire.available() > 0) {
    char c = Wire.read();
    message1 += c;
  }
  
  Serial.println("Received: " + message1);
}
