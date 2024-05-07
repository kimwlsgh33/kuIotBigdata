#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
int main() {
  Scalar white = Scalar(255, 255, 255);
  Scalar black = Scalar(0, 0, 0);
  Scalar red = Scalar(0, 0, 255);
  Scalar green = Scalar(0, 255, 0);
  Scalar blue = Scalar(255, 0, 0);
  Scalar yellow = Scalar(0, 255, 255);

  // Mat img = imread(folder + "lenna.bmp", IMREAD_COLOR);
  Mat img = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
  cout << "sum(R): " << int(sum(img)[2]) << endl;
  cout << "sum(B): " << int(sum(img)[0]) << endl;
  cout << "mean(G): " << int(mean(img)[1]) << endl;

  double minVal, maxVal;
  Point minLoc, maxLoc;

  // different with python
  minMaxLoc(img, &minVal, &maxVal, &minLoc, &maxLoc);

  cout << "minVal : " << minVal << endl;
  cout << "maxVal : " << maxVal << endl;
  cout << "minLoc : " << minLoc << endl;
  cout << "maxLoc : " << maxLoc << endl;

  Mat src = Mat_<float>({1, 5}, {1.5f, -1.f, 3.0f, 4.0f, 5.0f});
  Mat dst;

  cout << "src.size() : " << src.size() << endl;
  cout << "src.row() : " << src.rows << endl;
  cout << "src.col() : " << src.cols << endl;
  normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
  cout << "src : " << src << endl;
  cout << "dst : " << dst << endl;

  cout << "cvRound(2.5) : " << cvRound(2.5) << endl;
  cout << "cvRound(2.51) : " << cvRound(2.51) << endl;
  cout << "cvRound(2.49) : " << cvRound(2.49) << endl;

  circle(img, minLoc, 5, black, -1);
  circle(img, maxLoc, 5, white, -1);

  imshow("img", img);

  waitKey(0);
  destroyAllWindows();
}
