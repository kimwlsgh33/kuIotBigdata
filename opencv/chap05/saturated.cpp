#include <opencv2/opencv.hpp>

using namespace cv;
String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
  Mat brightSrc, saturateSrc;
  brightSrc = src.clone();
  saturateSrc = src.clone();

  for (auto it = brightSrc.begin<uchar>(); it != brightSrc.end<uchar>(); it++) {
    *it = *it + 100;
  }

  for (auto it = saturateSrc.begin<uchar>(); it != saturateSrc.end<uchar>();
       it++) {
    *it = saturate_cast<uchar>(*it + 100);
  }
  imshow("src", src);
  imshow("brightSrc", brightSrc);
  imshow("saturateSrc", saturateSrc);
  waitKey();
  destroyAllWindows();
  return 0;
}
