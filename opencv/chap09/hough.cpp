#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "building.jpg", IMREAD_GRAYSCALE);
  Mat dst1, dst2;

  Mat edge;
  Canny(src, edge, 50, 150);

  std::vector<Vec2f> lines;
  // lines.push_back(Vec2f(1, 20));
  HoughLines(edge, lines, 1, CV_PI / 180, 200);
  // rho: pixel unit - resolution
  // theta: radian - 몇도 간격으로 검출할래?

  Point pt1, pt2;
  // 전체 개수
  for (size_t i = 0; i < lines.size(); ++i) {
    // float rho = lines[0][0], theta = lines[0][1];
    float rho = lines[i][0], theta = lines[i][1];
    float x0 = rho * cos(theta), y0 = rho * sin(theta);
    float x1000 = x0 + 1000 * cos(theta);
    float y1000 = y0 + 1000 * sin(theta);
    // pt1.x = cvRound(x0);
    // pt1.y = cvRound(y0);
    // pt2.x = cvRound(x1000);
    // pt2.y = cvRound(y1000);
    pt1.x = cvRound(x0 - x1000);
    pt1.y = cvRound(y0 - y1000);
    pt2.x = cvRound(x0 + x1000);
    pt2.y = cvRound(y0 + y1000);
    line(src, pt1, pt2, white, 2);
  }

  imshow("edge", edge);
  imshow("src", src);

  waitKey();
  destroyAllWindows();
}
