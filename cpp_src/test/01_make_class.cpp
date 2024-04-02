#include <iostream>
using namespace std;

// class definition
class TV {
public:
  // declare members
  bool on;
  int channel;
  int volume;
  void powerOn();
  void powerOff();
  void increaseChannel();
  void decreaseChannel();
  void increaseVolumn();
  void decreaseVolumn();

  // declare constructors - overloading (polymorphism)
  TV();
  TV(int chan);

private:
};

// define member functions
void TV::powerOn() { on = true; }
void TV::powerOff() { on = false; }
void TV::increaseChannel() { channel++; }
void TV::decreaseChannel() { channel--; }
void TV::increaseVolumn() { volume++; }
void TV::decreaseVolumn() { volume--; }

// define constructors
TV::TV() {
  on = false;
  channel = 0;
  volume = 0;
}
TV::TV(int chan) {
  on = false;
  channel = chan;
  volume = 0;
}

int main(void) {
  // create instance
  // TV samsung, LG;
  // LG.increaseChannel();
  // cout << LG.channel << endl;

  // LG 객체는, 생성시 채널을 10으로 설정
  // SAM 객체는, 생성시 채널을 100으로 설정
  TV LG(10), SAM(100);
  cout << SAM.volume << "\t" << SAM.channel << endl;
  cout << LG.volume << "\t" << LG.channel << endl;
}
