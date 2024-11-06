String sendMessage;
String receivedMessage;

void setup() {
  Serial.begin(9600);    
  Serial1.begin(9600);   
}

void loop() {
  while (Serial1.available() > 0) {
    char receivedChar = Serial1.read();
    if (receivedChar == '\n') {
      Serial.println(receivedMessage);  
      receivedMessage = "";  
    } else {
      receivedMessage += receivedChar;  
    }
  }

  if (Serial.available() > 0) {
    char inputChar = Serial.read();
    if (inputChar == '\n') {
      Serial1.println(sendMessage);  
      sendMessage = "";  
    } else {
      sendMessage += inputChar;
    }
  }
}
