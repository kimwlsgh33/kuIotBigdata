#include <iostream>
using namespace std;

//=========[TV]============
class TV {
  int size;

public:
  TV() { size = 20; }
  TV(int size) { this->size = size; }
  int getSize() { return size; }
};

//=========[WideTV]============
class WideTV : public TV {
  bool videoIn;

public:
  WideTV(int size, bool videoIn) : TV(size) { this->videoIn = videoIn; }
  bool getVideoIn() { return videoIn; }
};

//=========[SmartTV]============
class SmartTV : public WideTV {
  string ipAddr;

public:
  SmartTV(string ipAddr, int size) : WideTV(size, true) {
    this->ipAddr = ipAddr;
  }
  string getIpAddr() { return ipAddr; }
};

//=========[main()]============
int main() {
  SmartTV htv("192.0.0.1", 32);
  cout << "size=" << htv.getSize() << endl;
  cout << "videoIn=" << htv.getVideoIn() << endl;
  cout << "IP=" << htv.getIpAddr() << endl;
}
