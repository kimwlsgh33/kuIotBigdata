#include <TimerOne.h>
const int LED = 10;
unsigned int period = 20000;

#define degree_0 1024.0 * (3.2 / 100) - 1
#define degree_180 1024.0 * (13.0 / 100) - 1
#define degree_90 ((degree_180 - degree_0)/2) + degree_0

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(LED, 0);
  Timer1.setPeriod(period);
  // Timer1.setPwmDuty(LED, 1023/2);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Timer1.setPwmDuty(LED, (unsigned int)degree_0);
  delay(1000);
  Timer1.setPwmDuty(LED, (unsigned int)degree_90);
  delay(1000);
  Timer1.setPwmDuty(LED, (unsigned int)degree_180);
  delay(1000);
  Timer1.setPwmDuty(LED, 1024.0 * (3.2 / 100) - 1);
  delay(1000);
}
