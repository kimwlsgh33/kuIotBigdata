#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
  Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
  Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);
}
