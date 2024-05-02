const int LED = 8;

#define LED_SIZE 4
const int LEDS[LED_SIZE] = {8, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  // pinMode(LED, OUTPUT);
  for (int i = 0; i < LED_SIZE; ++i) {
    pinMode(LEDS[i], OUTPUT);
  }

  // PORTB |= 1 << 5;
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (int t_high = 0; t_high < 1500; ++t_high) {
    for (i = 0; i < LED_SIZE; ++i) {
      digitalWrite(LEDS[i], HIGH);
    }
    // delay(t_high);
    delayMicroseconds(t_high);

    for (i = 0; i < LED_SIZE; ++i) {
      digitalWrite(LEDS[i], LOW);
    }
    // delay(10 - t_high);
    delayMicroseconds(1500 - t_high);
  }

  // PORTB |= 1 << 5;
  // delay(500);
  // PORTB &= ~(1 << 5);
  // delay(500);
}
