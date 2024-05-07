#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
String filename = "mydata.json";

int main() {
  String name;
  int age;
  Point pt1;
  vector<int> scores;
  Mat mat1;

  FileStorage fs(folder + filename, FileStorage::READ);

  if (!fs.isOpened()) {
    cerr << "File open failed!" << endl;
    return -1;
  }

  fs["name"] >> name;
  fs["age"] >> age;
  fs["point"] >> pt1;
  fs["scores"] >> scores;
  fs["data"] >> mat1;

  fs.release();

  cout << "name: " << name << endl;
  cout << "age: " << age << endl;
  cout << "point: " << pt1 << endl;
  cout << "scores: {";
  // iterator
  for (auto score : scores) {
    cout << score << ", ";
  }
  cout << "}" << endl;
  cout << "data: " << mat1 << endl;
}
