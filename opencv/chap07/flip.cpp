#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
int main() {
  Mat src = imread(folder + "eastsea.bmp");

  std::vector<Mat> dsts;

  for (int i = 0; i < 3; ++i) {
    Mat dst;
    flip(src, dst, i - 1);
    dsts.push_back(dst);
  }

  imshow("src", src);
  int i = 0;

  for (auto dst : dsts) {
    imshow("dst" + std::to_string(i + 1), dst);
    i++;
  }
  waitKey();
  destroyAllWindows();
}
