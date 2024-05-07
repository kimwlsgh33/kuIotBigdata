#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

void mask_copyTo();

int main() { mask_copyTo(); }

void mask() {
  Scalar white = Scalar(255, 255, 255);
  Scalar black = Scalar(0, 0, 0);
  Scalar red = Scalar(0, 0, 255);
  Scalar green = Scalar(0, 255, 0);
  Scalar blue = Scalar(255, 0, 0);
  Scalar yellow = Scalar(0, 255, 255);

  Mat img = imread(folder + "lenna.bmp", IMREAD_COLOR);
  Mat mask = imread(folder + "mask_smile.bmp", IMREAD_GRAYSCALE);

  img.setTo(white, mask);
  imshow("img", img);
  waitKey(0);
  destroyAllWindows();
}

void mask_copyTo() {
  Mat src = imread(folder + "airplane.bmp", IMREAD_COLOR);
  Mat mask = imread(folder + "mask_plane.bmp", IMREAD_GRAYSCALE);
  Mat dst = imread(folder + "field.bmp", IMREAD_COLOR);

  if (src.empty() || mask.empty() || dst.empty()) {
    cerr << "Image load failed" << endl;
  }

  src.copyTo(dst, mask);

  imshow("dst", dst);
  waitKey();
  destroyAllWindows();
}
