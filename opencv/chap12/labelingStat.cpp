#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  Mat src = imread(folder + "keyboard.bmp", IMREAD_GRAYSCALE);

  Mat bin;
  // otsu binarization - find the best threshold
  threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

  morphologyEx(bin, bin, MORPH_CLOSE, Mat(), Point(-1, -1), 3);
  // morphologyEx(bin, bin, MORPH_OPEN, Mat(), Point(-1, -1), 3);

  Mat label2, stats, centroids;
  int cnt = connectedComponentsWithStats(bin, label2, stats, centroids, 8);

  Mat dst;
  cvtColor(bin, dst, COLOR_GRAY2BGR);

  std::cout << "number of labels: " << cnt
            << std::endl; // it contain background too
  for (int i = 1; i < cnt; ++i) {
    int *p = stats.ptr<int>(i);
    if (p[4] < 20)
      continue;
    rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 0, 255));
    putText(dst, format("idsx: %d centrois(%d, %d)", i, p[0], p[1]),
            Point(p[0], p[1]), FONT_HERSHEY_SIMPLEX, 0.4, blue);
  }

  imshow("bin", bin);
  imshow("src", src);
  imshow("dst", dst);

  waitKey();

  destroyAllWindows();
}
