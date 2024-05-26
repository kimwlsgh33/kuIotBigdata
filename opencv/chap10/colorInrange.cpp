#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "candies.png");
  int Hmin = 40;
  int Hmax = 80;
  int Smin = 50;
  imshow("src", src);
  cvtColor(src, src, COLOR_BGR2HSV);

  namedWindow("dst");
  createTrackbar("Hmin", "dst", &Hmin, 255);
  createTrackbar("Hmax", "dst", &Hmax, 255);
  createTrackbar("Smin", "dst", &Smin, 255);
  while (true) {
    Mat dst;
    // inRange(src, Scalar(Hmin, 0, 0), Scalar(Hmax, 255, 255), dst);
    // inRange(src, Scalar(Hmin, 100, 0), Scalar(Hmax, 255, 255), dst);
    inRange(src, Scalar(Hmin, Smin, 0), Scalar(Hmax, 255, 255), dst);
    imshow("dst", dst);
    if (waitKey(33) == 27)
      break;
  }

  destroyAllWindows();
}
