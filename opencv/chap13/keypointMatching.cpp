#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src1 = imread(folder + "box.png", IMREAD_GRAYSCALE);
  Mat src2 = imread(folder + "box_in_scene.png", IMREAD_GRAYSCALE);

  imshow("src1", src1);
  imshow("src2", src2);

  //================================================
  // Feature detection and Description
  // - Detect keypoint and compute descriptors
  // - By using ORB feature detector
  //================================================
  Ptr<Feature2D> orb = ORB::create();
  std::vector<KeyPoint> key1, key2;
  Mat desc1, desc2;
  orb->detectAndCompute(src1, Mat(), key1, desc1);
  orb->detectAndCompute(src2, Mat(), key2, desc2);
  //================================================

  std::cout << "desc1.size() = " << desc1.size() << std::endl;
  std::cout << "desc2.size() = " << desc2.size() << std::endl;

  Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
  std::vector<DMatch> matches;
  matcher->match(desc1, desc2, matches);

  std::sort(matches.begin(), matches.end());
  std::vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);

  std::vector<Point2f> pts1, pts2;
  int i = 0;
  for (auto pt : good_matches) {
    pts1.push_back(key1[pt.queryIdx].pt);
    pts2.push_back(key2[pt.trainIdx].pt);
    ++i;
  }
  Mat M = findHomography(pts1, pts2, RANSAC);

  std::vector<Point2f> corner1, corner2;
  corner1.push_back(Point2f(0, 0));
  corner1.push_back(Point2f(src1.cols - 1, 0));
  corner1.push_back(Point2f(src1.cols - 1, src1.rows - 1));
  corner1.push_back(Point2f(0, src1.rows - 1));
  perspectiveTransform(corner1, corner2, M);
  std::vector<Point> corner2_int;
  for (auto pt : corner2) {
    corner2_int.push_back(Point(cvRound(pt.x), cvRound(pt.y)));
  }

  polylines(src2, corner2_int, true, green, 2);
  imshow("src1", src1);
  imshow("src2", src2);

  Mat dst;
  // drawMatches(src1, key1, src2, key2, matches, dst);
  drawMatches(src1, key1, src2, key2, good_matches, dst);

  imshow("dst", dst);

  waitKey();
  destroyAllWindows();
}
