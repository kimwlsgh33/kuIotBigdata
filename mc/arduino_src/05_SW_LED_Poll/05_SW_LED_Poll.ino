const int SW0 = 2;
const int LED = 8;

bool flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW0, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SW0_Val = digitalRead(SW0);
  Serial.println(SW0_Val);

  if (SW0_Val == HIGH) flag = !flag; delay(150);

  if (flag) digitalWrite(LED, HIGH); else digitalWrite(LED, LOW);
}
