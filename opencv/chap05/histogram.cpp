#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
  Mat histo;
  int channels[] = {0};         // Channel index for grayscale images
  int dims = 1;                 // Number of dimensions
  const int histSize[] = {256}; // Number of bins in the histogram
  float graylevel[] = {0, 256}; // Ranges of pixel values (0-255 for grayscale)
  const float *ranges[] = {graylevel}; // Pointer to the range array

  calcHist(&src, 1, channels, Mat(), histo, dims, histSize, ranges);
  imshow("src", src);
  // std::cout << histo << std::endl;

  Mat graph(100, 256, CV_8U, Scalar(255));
  normalize(histo, histo, 0, 100, NORM_MINMAX);
  for (int i = 0; i < 256; ++i) {
    line(graph, Point(i, 100), Point(i, 100 - cvRound(histo.at<float>(i))),
         Scalar(0));
  }
  imshow("graph", graph);

  waitKey();
  destroyAllWindows();
}
