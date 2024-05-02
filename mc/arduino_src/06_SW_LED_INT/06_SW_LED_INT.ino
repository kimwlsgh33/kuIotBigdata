void toggleFlag();

const int SW0 = 2;
const int SW1 = 3;
const int LED = 8;

bool flag0 = false, flag1 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW0, INPUT);
  pinMode(SW1, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SW0), toggleFlag0, RISING);
  attachInterrupt(digitalPinToInterrupt(SW1), toggleFlag1, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag0 && flag1) digitalWrite(LED, HIGH); else digitalWrite(LED, LOW);
}

void toggleFlag0()
{
  flag0 = !flag0;
}

void toggleFlag1()
{
  flag1 = !flag1;
}