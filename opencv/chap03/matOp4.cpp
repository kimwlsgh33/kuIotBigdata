#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
  Mat mat1 = Mat::zeros(3, 4, CV_8UC1);
  cout << "First mat0:" << mat1 << endl;

  for (int j = 0; j < mat1.rows; ++j) {
    for (int i = 0; i < mat1.cols; ++i) {
      mat1.at<uchar>(j, i)++;
    }
  }

  cout << "Second mat1:" << mat1 << endl;

  for (int j = 0; j < mat1.rows; ++j) {
    // The address of the first element of the j-th row
    uchar *p = mat1.ptr<uchar>(j);
    for (int i = 0; i < mat1.cols; ++i) {
      p[i]++;
    }
  }

  cout << "Third mat1:" << mat1 << endl;

  // begin: the address of the first element
  // end: the address of the element after the last element
  for (auto it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
    (*it)++;
  }

  cout << "Fourth mat1:" << mat1 << endl;
}
