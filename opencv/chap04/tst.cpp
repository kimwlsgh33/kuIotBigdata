#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Scalar white = Scalar(255, 255, 255);
Scalar black = Scalar(0, 0, 0);
Scalar red = Scalar(0, 0, 255);
Scalar green = Scalar(0, 255, 0);
Scalar blue = Scalar(255, 0, 0);
Scalar yellow = Scalar(0, 255, 255);

void onMouse(int event, int x, int y, int, void *param);
void drawCursor(Mat *img, int x, int y);

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat org = imread(folder + "lenna.bmp", IMREAD_COLOR);
  FileStorage fs(folder + "lenna.json", FileStorage::WRITE);
  imshow("lenna", org);
  setMouseCallback("lenna", onMouse, &org);

  waitKey();
  // 32 == SPACE
  if (waitKey(0) == 32) {
  }
  destroyAllWindows();
}

void onMouse(int event, int x, int y, int, void *param) {
  Mat *pImg = (Mat *)param;
  switch (event) {
  case EVENT_MOUSEMOVE:
    drawCursor(pImg, x, y);
    break;
  case EVENT_LBUTTONDOWN:
    static vector<Vec3b> mouseBGR;

    cout << "RGB: " << pImg->at<Vec3b>(y, x) << endl;
    mouseBGR.push_back(pImg->at<Vec3b>(y, x));
    cout << "BGR: ";
    for (auto v : mouseBGR) {
      cout << v << " ";
    }
    cout << endl;
    break;
  }
}

void drawCursor(Mat *pImg, int x, int y) {
  // NOTE: This is executed only once.
  static Mat cursor;

  cursor = pImg->clone();
  rectangle(cursor, Point(x - 25, y - 25), Point(x + 25, y + 25), green, 2,
            LINE_8);
  imshow("lenna", cursor);
}
