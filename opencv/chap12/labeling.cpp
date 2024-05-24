#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  uchar data[] = {
      0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1,
      0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };

  Mat src = Mat(8, 8, CV_8UC1, data) * 255;
  // Mat src = Mat(8, 8, CV_8UC1, data);
  Mat label;

  int cnt = connectedComponents(src, label);
  std::cout << "number of labels: " << cnt << std::endl; // it contain background too
  std::cout << "label: \n" << label << std::endl;

  Mat label2, stats, centroids;
  connectedComponentsWithStats(src, label2, stats, centroids, 8);
  std::cout << "stats: \n" << stats << std::endl;
  imshow("src", src);
  waitKey();

  destroyAllWindows();
}
