#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "coins.png", IMREAD_GRAYSCALE);

  blur(src, src, Size(3, 3));
  // bilateralFilter(src, src, 9, 75, 75);

  std::vector<Vec3f> circles;
  HoughCircles(src, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

  Mat dst;
  cvtColor(src, dst, COLOR_GRAY2BGR);

  for (auto i : circles) {
    circle(dst, Point(cvRound(i[0]), cvRound(i[1])), cvRound(i[2]), red, 2);
  }

  imshow("src", src);
  imshow("dst", dst);

  waitKey();
  destroyAllWindows();
}
