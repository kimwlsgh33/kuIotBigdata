#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "candies.png");

  std::vector<Mat> bgr, b_planes, g_planes, r_planes;
  // split the 3 channels
  split(src, bgr);

  Mat Empty(src.rows, src.cols, CV_8UC1, Scalar(0));
  b_planes = {bgr[0], Empty, Empty};
  g_planes = {Empty, bgr[1], Empty};
  r_planes = {Empty, Empty, bgr[2]};

  Mat bdst, gdst, rdst;
  // merge the 3 channels
  merge(b_planes, bdst);
  merge(g_planes, gdst);
  merge(r_planes, rdst);

  imshow("src", src);
  int i = 1;

  imshow("b", bdst);
  imshow("g", gdst);
  imshow("r", rdst);
  // for (auto channel : bgr) {
  //   imshow("channel" + std::to_string(i++), channel);
  // }

  waitKey();
  destroyAllWindows();
}
