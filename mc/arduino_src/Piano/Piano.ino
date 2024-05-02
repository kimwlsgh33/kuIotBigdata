#include <TimerOne.h>
#include <string.h>

#define DO0 261.6256
#define RE0 293.6648
#define MI0 329.6279
#define PA0 349.2282
#define PA0S 369.9944
#define SOL0 391.9954
#define SOL0S 415.3047
#define LA0 440
#define SI0 493.8833
#define DO1 523.2511
#define RE1 587.3295
#define ME1 587.3295

void play(int note, int period);
void play_null(period);

const int BUZZER = 10;

const double melody[] = {
  DO0, RE0, MI0, PA0, SOL0, LA0, SI0, DO1
};

const double song[] = {
  RE0, RE0, RE1,
  LA0,
  SOL0S, SOL0, PA0,
  RE0, PA0, SOL0,
  // DO0, DO0, RE1
};

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);

  Timer1.setPwmDuty(BUZZER, 100);

  for (int note = 0; note < 10; ++note) {
    if (note < 2) {
      play(note, 200);
      play_null(50);
    } else if (note < 3) {
      play(note, 300);
      play_null(50);
    } else if (note < 4) {
      playnull(50);
      play(note, 300);
      play_null(50);
    } else if (note < 7) {
      play(note, 300);
      play_null(50);
    }
  }

  Timer1.setPwmDuty(BUZZER, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void play(int note, int period) {
  Timer1.setPeriod((unsigned long)(1000000 / song[note]));
  delay(period);
}

void play_null(period) {
  Timer1.setPeriod(0);
  delay(period);
}