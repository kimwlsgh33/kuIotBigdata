#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "butterfly.jpg");

  for (int i = 0; i < 100; ++i) {
    // Vec3b &pixel = src.at<Vec3b>(0, 0);
    Vec3b &pixel = src.at<Vec3b>(i, 0);
    uchar b1 = pixel[0];
    uchar g1 = pixel[1];
    uchar r1 = pixel[2];

    // std::cout << "bgr: (" << b1 << ", " << g1 << ", " << r1 << ")" << std::endl;
    std::cout << pixel << std::endl;

    pixel[0] = 0;
    pixel[1] = 0;
    pixel[2] = 255;

    // std::cout << "bgr: (" << b1 << ", " << g1 << ", " << r1 << ")" << std::endl;
    std::cout << pixel << std::endl;
  }

  imshow("src", src);

  waitKey();
  destroyAllWindows();
}
