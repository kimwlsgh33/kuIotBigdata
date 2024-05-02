const unsigned int led_a = 2;
const unsigned int led_b = 3;
const unsigned int led_c = 4;
const unsigned int led_d = 5;
const unsigned int led_e = 6;
const unsigned int led_f = 7;
const unsigned int led_g = 8;

#define LED_SIZE 7
#define NUM_SIZE 10
const unsigned int leds[LED_SIZE] = {2, 3, 4, 5, 6, 7, 8};
const unsigned char nums[NUM_SIZE][LED_SIZE] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},   // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},   // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},   // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},   // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},   // 6
  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, LOW},      // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},   // 8
  {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH}   // 9
};

int i, j;
void setup() {
  // put your setup code here, to run once:
  // pinMode(led_a, OUTPUT);
  
  for (i = 0; i < LED_SIZE; ++i) {
    pinMode(leds[i], OUTPUT);
  }
  
  for (i = 0; i < LED_SIZE; ++i) {
    digitalWrite(leds[i], HIGH);
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // i: [0, 9]
  for (i = 0; i < NUM_SIZE; ++i) {
    // j: [0, 6]
    for (j = 0; j < LED_SIZE; ++j) {
      // leds[0] ~ leds[6], nums[0][0] ~ nums[0][6]
      digitalWrite(leds[j], nums[i][j]);
      // Serial.print(leds[j]);
      // Serial.print(" - ");
      // Serial.println(nums[i][j]);
      // delay(500);
    }
    delay(1000);
  }
}
