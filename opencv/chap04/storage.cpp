#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
String filename = "mydata.yaml";

int main() {
  String name = "Jinho";
  int age = 10;
  Point pt1(100, 200);
  vector<int> scores = {80, 90, 50};
  Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

  FileStorage fs(folder + filename, FileStorage::WRITE);

  if (!fs.isOpened()) {
    cerr << "File open failed!" << endl;
    return -1;
  }

  fs << "name" << name;
  fs << "age" << age;
  fs << "point" << pt1;
  fs << "scores" << scores;
  fs << "data" << mat1;

  fs.release();
}
