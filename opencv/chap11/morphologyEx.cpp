#include "../include/color.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main(int argc, char *argv[]) {
  Mat src = imread(folder + "milkdrop.bmp", IMREAD_GRAYSCALE);
  Mat bin;
  threshold(src, bin, 128, 255, THRESH_BINARY);

  Mat dst1, dst2, dst3, dst4, dst5, dst6;
  morphologyEx(bin, dst1, MORPH_OPEN, Mat());
  morphologyEx(dst1, dst2, MORPH_CLOSE, Mat());
  morphologyEx(dst2, dst3, MORPH_GRADIENT, Mat());
  morphologyEx(bin, dst4, MORPH_TOPHAT, Mat());
  morphologyEx(bin, dst5, MORPH_HITMISS, Mat());
  morphologyEx(bin, dst6, MORPH_BLACKHAT, Mat());

  imshow("bin", bin);
  imshow("open", dst1);
  imshow("close", dst2);
  imshow("gradient", dst3);
  imshow("tophat", dst4);
  imshow("hitmiss", dst5);
  imshow("blackhat", dst6);
  imshow("src", src);
  waitKey();

  destroyAllWindows();
}
