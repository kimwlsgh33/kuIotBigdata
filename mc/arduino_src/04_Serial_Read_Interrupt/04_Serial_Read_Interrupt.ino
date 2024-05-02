const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void serialEvent() {
  String buf = Serial.readStringUntil('\n');

  if (buf == "LED_ON")
    digitalWrite(LED, HIGH);
  if (buf == "LED_OFF")
    digitalWrite(LED, LOW);
}