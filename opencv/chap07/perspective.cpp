#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

Mat src;
Point2f srcQuad[4], dstQuad[4];

void on_mouse(int event, int x, int y, int flags, void *userdata);

int main() {
  src = imread(folder + "card.bmp");

  namedWindow("src");

  setMouseCallback("src", on_mouse);

  imshow("src", src);
  waitKey();
  destroyAllWindows();
}

void on_mouse(int event, int x, int y, int flags, void *userdata) {
  static int cnt = 0;

  if (event == EVENT_LBUTTONDOWN) {
    if (cnt < 4) {
      // add point
      srcQuad[cnt++] = Point2f(x, y);

      // draw dot to the current point
      circle(src, Point(x, y), 5, red, -1);
      imshow("src", src);

      if (cnt == 4) {
        int w = 200, h = 300;

        dstQuad[0] = Point2f(0, 0);
        dstQuad[1] = Point2f(w - 1, 0);
        dstQuad[2] = Point2f(w - 1, h - 1);
        dstQuad[3] = Point2f(0, h - 1);

        Mat pers = getPerspectiveTransform(srcQuad, dstQuad);

        Mat dst;
        warpPerspective(src, dst, pers, Size(w, h));

        imshow("dst", dst);
      }
    }
  }
}
