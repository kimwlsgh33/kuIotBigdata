#include <string.h>
// #define BUF_SIZE 1024
int recv_cnt = 0;
// char buf[BUF_SIZE];

const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(recv_cnt = Serial.available()) {
    
    // char userInput = Serial.readBytes(buf, recv_cnt);
    // userInput = Serial.readStringUntil('\n');
    // Serial.print(userInput);

    String userInput = Serial.readString();
    Serial.print(userInput);
    
    // switch(userInput) {
    //   case led_on:
    //     digitalWrite(LED, HIGH);
    //   case led_off:
    //     digitalWrite(LED, LOW);
    // }

    if (userInput == "LED_ON\r")
      digitalWrite(LED, HIGH);
    if (userInput == "LED_OFF\r")
      digitalWrite(LED, LOW);

    // buf[0] = 0;
  }
}