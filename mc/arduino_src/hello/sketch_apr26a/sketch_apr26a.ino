void setup() {
  // put your setup code here, to run once:
  // the speed of serial communication (bps)
  Serial.begin(115200);

  Serial.println("setup()");
  Serial.println(78, DEC);
  Serial.println(78, HEX);
  Serial.println(78, BIN);

  Serial.println(1.23456, 0);
  Serial.println(1.23456, 2);
  Serial.println(1.23456, 4);
}

void loop() {
  
}
