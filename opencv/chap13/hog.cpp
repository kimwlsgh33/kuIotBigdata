#include "../include/color.hpp"
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  VideoCapture cap(folder + "vtest.avi");

  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
  Mat frame;
  while (true) {
    cap >> frame;
    if (frame.empty())
      break;
    std::vector<Rect> detected;
    hog.detectMultiScale(frame, detected);
    for (Rect r : detected) {
      rectangle(frame, r, red, 3);
    }
    imshow("frame", frame);
    if (waitKey(30) == 27)
      break;
  }

  waitKey();
  destroyAllWindows();
}
