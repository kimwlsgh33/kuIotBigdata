#include <chrono>
#include <iostream>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
using namespace std;
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Scalar white = Scalar(255, 255, 255);
  Scalar black = Scalar(0, 0, 0);
  Scalar red = Scalar(0, 0, 255);
  Scalar green = Scalar(0, 255, 0);
  Scalar blue = Scalar(255, 0, 0);
  Scalar yellow = Scalar(0, 255, 255);

  Mat img = imread(folder + "lenna.bmp", IMREAD_COLOR);

  imshow("img", img);

  int keycode;

  // use chrono for calculating time
  const float fps = 30.0;
  TickMeter tm, tm2;

  while (true) {
    tm.start();
    keycode = waitKey(33);
    cout << "keycode: " << keycode << endl;

    if (keycode == 27) {
      cout << "ESC key pressed. Terminating the program." << endl;
      break;
    } else if (keycode == 'i' || keycode == 'I') {
      img = ~img;
      imshow("img", img);
    }
    tm.stop();
		cout << "tm.getFPS(): " << tm.getFPS() << endl;
    if (tm.getAvgTimeMilli() < 1000.0 / fps) {
      this_thread::sleep_for(
          chrono::milliseconds((int)(1000.0 / fps - tm.getAvgTimeMilli())));
    }
    tm2.stop();
		cout << "tm2.getFPS(): " << tm2.getFPS() << endl;
  }

  destroyAllWindows();
}
