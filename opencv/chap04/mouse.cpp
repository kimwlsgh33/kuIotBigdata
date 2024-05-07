#include <iostream>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/freetype.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

static Mat img;
void onMouse(int event, int x, int y, int flags, void *);

int main() {
  img = imread(folder + "lenna.bmp", IMREAD_COLOR);
  namedWindow("img");
  setMouseCallback("img", onMouse);
  imshow("img", img);
  waitKey(0);
  destroyAllWindows();
}

// ex4-11 in p163
void onMouse(int event, int x, int y, int flags, void *) {
  switch (event) {
  case EVENT_LBUTTONDOWN:
    circle(img, Point(x, y), 20, Scalar(0, 0, 255), 2, LINE_AA); // red
    imshow("img", img);
    break;
  case EVENT_RBUTTONDOWN:
    circle(img, Point(x, y), 20, Scalar(0, 255, 0), 2, LINE_AA); // green
    imshow("img", img);
    break;
  case EVENT_MBUTTONDOWN:
    circle(img, Point(x, y), 20, Scalar(255, 0, 0), 2, LINE_AA); // blue
    imshow("img", img);
    break;
  case EVENT_MOUSEMOVE:
    if (flags & EVENT_FLAG_LBUTTON) {
      cout << "Left button of the mouse is clicked - position (" << x << ", "
           << y << ")" << endl;
    }
    if (flags & EVENT_FLAG_RBUTTON) {
      cout << "Right button of the mouse is clicked - position (" << x << ", "
           << y << ")" << endl;
    }
    if (flags & EVENT_FLAG_MBUTTON) {
      cout << "Middle button of the mouse is clicked - position (" << x << ", "
           << y << ")" << endl;
    }
    break;
  }
}
