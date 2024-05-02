const int LED = 10;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int t_high = 0; t_high < 11; ++t_high) {
    analogWrite(LED, t_high * 25);
    delay(100);
  }
}
