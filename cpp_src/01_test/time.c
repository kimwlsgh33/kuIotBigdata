#include <stdio.h>
#include <math.h>
#define TIME 3.76

int main(void) {
  int hour, min, sec;
  double time = TIME;

  hour = time;  // hour <- 3
  time -= hour; // time == 0.76

  // 1 hour == 60 min
  time *= 60; // time == left.right
  min = time; // min <- left

  time -= min; // time == 0.right

  // 1 min == 60 sec
  time *= 60; // time == left.right
  sec = round(time); // sec <- left

  // 1 hour == 3600 sec
  printf("%.2f시간은 %d시간 %d분 %d초입니다\n", TIME, hour, min, sec);

  return 0;
}
