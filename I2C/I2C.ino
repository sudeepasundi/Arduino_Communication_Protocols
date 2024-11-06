#include <Wire.h>
String message1="";
String message2="";
int i;
int slaveAddress[]={2,8};
int numSlaves = sizeof(slaveAddress) / sizeof(slaveAddress[0]);

void setup(){
  Wire.begin(5);
  Wire.onReceive(recieve);
  Serial.begin(9600);
}

void loop(){
  message1="";
  if(Serial.available()>0)
  {
    message2=Serial.readStringUntil('\n');
    char d=message2[0];
    i=(int)d-48;
    message2.remove(0,1);
    Serial.println(i);
    Wire.beginTransmission(i);
    Wire.write(message2.c_str());
    Wire.endTransmission();
     
  }  
 
  delay(100);

}

void recieve()
{ message1="";
  while(Wire.available()>0)
  {
    char c=Wire.read();
    
    message1+=c;
  }
   Serial.println(message1);
  }
