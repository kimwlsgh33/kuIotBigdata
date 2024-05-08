#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat origin = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
  Mat src1 = origin.clone();
  Mat src2 = origin.clone();
  src1 = src1 * 2.f;
  src2 = src2 + (src2 - 180) * 1.f;

  std::cout << "origin mean: "  << mean(origin) << std::endl;

  imshow("origin", origin);
  imshow("src1", src1);
  imshow("src2", src2);

  waitKey(0);
  destroyAllWindows();
}
