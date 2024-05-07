// #include <iostream>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

// ex4-6 in p146
int main() {
  Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

  vector<Point> pts;
  pts.push_back(Point(250, 250));
  pts.push_back(Point(300, 250));
  polylines(img, pts, true, Scalar(0, 0, 0), 3);
  imshow("img", img);
  waitKey(0);
  destroyAllWindows();
}
