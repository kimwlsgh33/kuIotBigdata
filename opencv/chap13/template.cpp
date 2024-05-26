#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  Mat src = imread(folder + "circuit.bmp", IMREAD_COLOR);
  Mat temp1 = imread(folder + "crystal.bmp", IMREAD_COLOR);

  Mat res, resNorm;
  matchTemplate(src, temp1, res, TM_CCOEFF_NORMED);
  normalize(res, resNorm, 0, 255, NORM_MINMAX, CV_8U);

  imshow("resNorm", resNorm);
  double maxVal;
  Point maxLoc;

  minMaxLoc(resNorm, NULL, &maxVal, NULL, &maxLoc);
  std::cout << "maxVal: " << maxVal << std::endl;
  rectangle(src, Rect(maxLoc.x, maxLoc.y, temp1.cols, temp1.rows), red, 2);
  // rectangle(src, Rect(maxLoc, temp1.size()), red, 2);

  imshow("src", src);
  waitKey();

  destroyAllWindows();
}
