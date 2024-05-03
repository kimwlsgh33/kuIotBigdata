#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>

std::string folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data";

int main() { 
  std::cout << "Hello, World!" << endl;
  cv::MAT img;
  img = cv::imread(folder + "lenna.bmp");
  cv::imshow("image", img);
  cv::waitKey(0);
  return 0;
}
