#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

std::string folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data";

using namespace cv;
using namespace std;

int main() {
  // cout << sz1 << sz2 << sz1.area() << sz1.aspectRatio() << endl;
  Rect rc1;
  Rect rc2(10, 20, 20, 20);
  Point pt1(40, 40);
  Size sz1(100, 100);
  Rect rc3(pt1, sz1);

  cout << rc1 << endl;
  cout << rc2 << endl;
  cout << rc3 << endl;

  RotatedRect rr1(pt1, sz1, 30);
  Point2f pts[4];
  rr1.points(pts);
  cout << pts[0] << endl;
  cout << pts[1] << endl;
  cout << pts[2] << endl;
  cout << pts[3] << endl;
}
