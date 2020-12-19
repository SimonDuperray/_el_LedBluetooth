#include <SoftwareSerial.h>
SoftwareSerial BLTH(0, 1);
#define Rx 0
#define Tx 1
#define pinLed 6

void setup(){
  Serial.begin(9600);
  BLTH.begin(9600);
  pinMode(Rx, INPUT);
  pinMode(Tx, OUTPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);
}

void loop(){
  int recvChar;
  Serial.println('non connecte');
  delay(100);
  while(1){
    if(BLTH.available()){
      Serial.println('connecte');
      delay(100);
      recvChar = BLTH.read();
      Serial.println(recvChar);
      if(recvChar == 0){
        digitalWrite(pinLed, LOW);
      }
      if(recvChar == 1){
        digitalWrite(pinLed, HIGH);
      }
    }
  }
}
