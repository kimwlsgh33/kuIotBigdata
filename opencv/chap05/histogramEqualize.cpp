#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

void histogramGraph(Mat &graph, const Mat &src);
String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "hawkes.bmp", IMREAD_GRAYSCALE);
  double gmin, gmax;
  minMaxLoc(src, &gmin, &gmax);

  // histogram equalization
  Mat dst;
  equalizeHist(src, dst);

  Mat graphSrc(100, 256, CV_8U, Scalar(255));
  Mat graphDst(100, 256, CV_8U, Scalar(255));

  histogramGraph(graphSrc, src);
  histogramGraph(graphDst, dst);

  // resize(src, src, Size(800, 800));
  // resize(dst, dst, Size(800, 800));
  imshow("src", src);
  imshow("dst", dst);
  imshow("graphSrc", graphSrc);
  imshow("graphDst", graphDst);
  // Mat graph(100, 256, CV_8U, Scalar(255));

  waitKey();
  destroyAllWindows();
}

void histogramGraph(Mat &graph, const Mat &src) {
  Mat histo;
  int channels[] = {0};         // Channel index for grayscale images
  int dims = 1;                 // Number of dimensions
  const int histSize[] = {256}; // Number of bins in the histogram
  float graylevel[] = {0, 256}; // Ranges of pixel values (0-255 for grayscale)
  const float *ranges[] = {graylevel}; // Pointer to the range array

  calcHist(&src, 1, channels, noArray(), histo, dims, histSize,
           ranges); // calculate histogram
  // std::cout << histo << std::endl;

  normalize(histo, histo, 0, 100, NORM_MINMAX);
  for (int i = 0; i < 256; ++i) {
    line(graph, Point(i, 100), Point(i, 100 - cvRound(histo.at<float>(i))),
         Scalar(0));
  }
  // imshow("graph", graph);
}
