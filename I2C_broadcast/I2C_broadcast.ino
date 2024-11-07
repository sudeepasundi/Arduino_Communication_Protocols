#include <Wire.h>
String message1="";
String message2="";
int slaveAddress[]={0,2};
int numSlaves = sizeof(slaveAddress) / sizeof(slaveAddress[0]);

void setup(){
  Wire.begin(8);
  Wire.onReceive(recieve);
  Serial.begin(9600);
}

void loop(){
  message1="";
  if(Serial.available()>0)
  {
    message2=Serial.readStringUntil('\n');
    for(int i=0;i<numSlaves;i++){
    Wire.beginTransmission(slaveAddress[i]);
    Wire.write(message2.c_str());
    Wire.endTransmission();
    }
    
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
