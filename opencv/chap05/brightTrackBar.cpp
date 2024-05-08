#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

void on_brightness(int pos, void *userdata);

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";
int main() {
  Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
  int position = 256; // initial position
  namedWindow("img");
  // pos: 0 ~ 511
  createTrackbar("Brightness", "img", &position, 511, on_brightness,
                 (void *)&src);
  // imshow("src", src);
  on_brightness(position, (void *)&src);
  waitKey();
  destroyAllWindows();
}

void on_brightness(int pos, void *userdata) {
  Mat img = *(Mat *)userdata;
  Mat dst = img + pos - 255;
  imshow("img", dst);
}

