#include <opencv2/core/hal/interface.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data";

int main() {
  Mat img1;
  img1 = Scalar(10, 0, 0);
  // 8bit, unsigned, 1 channel
  Mat img2(400, 640, CV_8UC1);
  Mat img3(400, 640, CV_8UC3);
  Mat img4(Size(640, 400), CV_8UC3);
  Mat img5(400, 640, CV_8UC1, Scalar(0));
  Mat img6(400, 640, CV_8UC1, Scalar(255));

  imshow("img2", img2);
  imshow("img3", img3);
  imshow("img4", img4);
  imshow("img5", img5);
  imshow("img6", img6);
  waitKey(0);
}
