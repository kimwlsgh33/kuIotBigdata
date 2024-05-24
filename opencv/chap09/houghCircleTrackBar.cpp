#include "../include/color.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "coins.png", IMREAD_GRAYSCALE);

  blur(src, src, Size(3, 3));

  int min_dist = 50;
  int param1 = 150;
  int param2 = 30;
  int min_radius = 1;
  int max_radius = 50;

  namedWindow("dst");
  createTrackbar("min_dst", "dst", &min_dist, 100);
  createTrackbar("param1", "dst", &param1, 200);
  createTrackbar("param2", "dst", &param2, 200);
  createTrackbar("min_radius", "dst", &min_radius, 100);
  createTrackbar("max_radius", "dst", &max_radius, 100);

  imshow("src", src);

  std::vector<Vec3f> circles;
  while (true) {
    // HoughCircles(src, circles, HOUGH_GRADIENT, 1, 50, 150, 30);
    HoughCircles(src, circles, HOUGH_GRADIENT, 1, min_dist, param1, param2,
                 min_radius, max_radius);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for (auto i : circles) {
      circle(dst, Point(cvRound(i[0]), cvRound(i[1])), cvRound(i[2]), red, 2);
    }

    imshow("dst", dst);

    if(waitKey(33) == 27) break;
  }
  destroyAllWindows();
}
