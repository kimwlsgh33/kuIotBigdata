#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "contours.bmp", IMREAD_GRAYSCALE);
  Mat dst;

  std::vector<std::vector<Point>> contours;
  std::vector<Vec4i> hier; // hierarchy

  findContours(src, contours, hier, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  cvtColor(src, dst, COLOR_GRAY2BGR);

  // n = srand(time(NULL));
  for (int i = 0; i < contours.size(); ++i) {
    Scalar color(rand() & 255, rand() & 255, rand() & 255);
    drawContours(dst, contours, i, color, 5, LINE_8, hier);
  }
  for (auto h : hier) {
    std::cout << h << std::endl;
  }

  imshow("src", src);
  imshow("dst", dst);
  waitKey();
  destroyAllWindows();
}

void print_contours(const std::vector<std::vector<Point>> &contours) {
  std::cout << contours.size() << std::endl;
  for (auto contour : contours) {
    std::cout << "size: " << contour.size() << std::endl;
    for (auto point : contour) {
      std::cout << point << ',';
    }
  }
}
