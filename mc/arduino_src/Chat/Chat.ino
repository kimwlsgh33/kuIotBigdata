#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11

// Set up a new SoftwareSerial object
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
String rx, tx;

void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(57600);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available() > 0) {
    rx = mySerial.readStringUntil('\n');
    rx = "OP : " + rx;
    Serial.println(rx);
  }

  if (Serial.available() > 0) {
    tx = Serial.readStringUntil('\n');
    mySerial.println(tx);

    Serial.println("ME : " + tx);
  }
} 
