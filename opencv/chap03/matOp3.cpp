#include <opencv2/opencv.hpp>
#include <string>

using namespace cv;
using namespace std;
String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  // Mat img1 = imread(folder + "dog.bmp");
  Mat img1 = imread(folder + "cat.bmp");

  // region of interrest
  Rect roi(200, 120, 200, 200);

  Mat img2 = img1(roi).clone();
  Mat img3 = img1(roi).clone();

  img2 = ~img2;

  imshow("img1", img1);
  imshow("img2", img2);
  imshow("img3", img3);

  waitKey();
  destroyAllWindows();
}
