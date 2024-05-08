#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
int main() {
  // Mat img = imread(folder + "lenna.bmp", IMREAD_COLOR);
  Mat src = imread(folder + "lenna.bmp", IMREAD_COLOR);
  Mat gray, addGray, subGray, satGray, satGray2;

  cvtColor(src, gray, COLOR_BGR2GRAY);
  // add(gray, 50, addGray);
  addGray = gray + 50;
  satGray = gray + 200;
  // subtract(gray, 50, subGray);
  subGray = gray - 50;
  satGray2 = gray - 200;

  // imshow("src", src);
  // imshow("gray", gray);
  // imshow("addGray", addGray);
  // imshow("subGray", subGray);
  imshow("satGray", satGray);
  imshow("satGray2", satGray2);

  waitKey(0);
  destroyAllWindows();
}
