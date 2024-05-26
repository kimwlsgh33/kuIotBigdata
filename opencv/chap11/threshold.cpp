#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  // Mat src = imread(folder + "neutrophils.png", IMREAD_GRAYSCALE);
  Mat src;
  if (argc < 2) {
    src = imread(folder + "sudoku.jpg", IMREAD_GRAYSCALE);
  } else if (argc == 2) {
    src = imread(argv[1], IMREAD_GRAYSCALE);
  }
  // 엄밀 -> argument parser library

  if (src.empty()) {
    std::cerr << "Image load failed!" << std::endl;
    return -1;
  }

  int pos = 40;
  imshow("src", src);

  namedWindow("dst");
  createTrackbar("Hmin", "dst", &pos, 255);
  while (true) {
    Mat dst;
    threshold(src, dst, pos, 255, THRESH_BINARY);
    imshow("dst", dst);
    if (waitKey(33) == 27)
      break;
  }

  destroyAllWindows();
}
