#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  Mat src = imread(folder + "neutrophils.png", IMREAD_GRAYSCALE);
  Mat bin;
  threshold(src, bin, 128, 255, THRESH_BINARY);

  Mat erodeMat, dilateMat;
  erode(bin, erodeMat, Mat());
  dilate(bin, dilateMat, Mat());

  imshow("bin", bin);
  imshow("erode", erodeMat);
  imshow("dilate", dilateMat);
  imshow("src", src);
  waitKey();

  destroyAllWindows();
}
