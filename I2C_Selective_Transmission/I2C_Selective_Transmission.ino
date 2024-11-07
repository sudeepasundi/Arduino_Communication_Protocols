#include <Wire.h>
String message1="";
String message2="";
int address;
char first;

void setup(){
  Wire.begin(8);
  Wire.onReceive(recieve);
  Serial.begin(9600);
  Serial.println("Enter the message to be sent with the first character ");
  Serial.println("being the address to which it should be sent to:"); 
  Serial.println("For Example:5Hi, sends Hi to the arduino at address 5");
}

void loop(){
  message1="";
  if(Serial.available()>0)
  {
   message2=Serial.readStringUntil('\n');
    first=message2[0];
    address=(int)first-48;
    message2.remove(0,1);
    Serial.println(" "+message2+" sent to address: "+ String(address));
    Wire.beginTransmission(address);
    Wire.write(message2.c_str());
    Wire.endTransmission();
   
    
  }
     
  delay(100);

}

void recieve()
{ message2="";
  while(Wire.available()>0)
  {
    char c=Wire.read();
    message2+=c;
  }
   Serial.println(message2);
  }
