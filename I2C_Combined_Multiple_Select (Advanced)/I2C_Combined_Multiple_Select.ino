#include <Wire.h>
String message1="";
String message2="";
int address;
String addr="";
int slaveAddress[]={5,8}; //Enter all the address available
int slaveAddress1[10];
int numSlaves = sizeof(slaveAddress) / sizeof(slaveAddress[0]);

void setup(){
  Wire.begin(2); //Enter your address here
  Wire.onReceive(receive);
  Serial.begin(9600);
  Serial.println("Enter the addresses you want to send the message to with a ");
  Serial.println("whitespace in between the addresses (enter 0 to broadcast):");
}

void loop(){
  message1="";
  int i=0;
  if(Serial.available()>0)
  {
   message2 = Serial.readStringUntil('\n'); 
   
    if(message2.length()>0){
      for(int j=0;j<message2.length();j++){
        char c=message2[j];
        if(c==' ')
        {
         address=addr.toInt();
         slaveAddress1[i]=address;
         addr="";
         i++; 
        }
        else 
        {
         addr+=c;
        }
      }

      if (addr != "") {           //This condition is necessary to read the last character 
       address = addr.toInt();    //as there is no trailing space
       slaveAddress1[i] = address;
       addr = "";
      }

      Serial.println("Selected slave address:"+message2);
      Serial.println("Enter the message");
      while (Serial.available() == 0);           //Necessary to make the execution wait until the message 
      message2 = Serial.readStringUntil('\n');  // is entered by the master.
      
      
    if( slaveAddress1[0]==0)
    {
    for(int j=0;j<numSlaves;j++){
    Wire.beginTransmission(slaveAddress[j]);
    Wire.write(message2.c_str());
    Wire.endTransmission();
    Serial.print("Message broadcasted to slave ");
    Serial.println(slaveAddress[j]);
    }
    
    }
    else {
    for(int j=0;j<=i;j++){
    Wire.beginTransmission(slaveAddress1[j]);
    Wire.write(message2.c_str());
    Wire.endTransmission(); 
    Serial.print("Message sent to slave: ");
    Serial.println(slaveAddress1[j]);
    }
    }

     message2 = "";  // Reset for next input
     Serial.println("Enter new slave addresses :");
      
  }
  }
  delay(100);

}

void receive()
{ 
  message1="";
  while(Wire.available()>0)
  {
    char c=Wire.read();
    message1+=c;
  }
   Serial.println("Received: "+message1);
  }
