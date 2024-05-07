#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/freetype.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

String font = "/Users/skoler/Library/Fonts/Warhaven_OTF_Regular.otf";

int main() {
  Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255));
  Ptr<freetype::FreeType2> ft2 = freetype::createFreeType2();
  ft2->loadFontData(font, 0);
  String text = u8"utf-8 문자열 테스트";
  int fontHeight = 50;
  Size textSize = ft2->getTextSize(text, fontHeight, -1, 0);
  ft2->putText(img, text, Point(0, fontHeight), fontHeight, Scalar(0, 0, 0), -1,
               LINE_AA, true);
  imshow("img", img);
  waitKey(0);
  destroyAllWindows();
}
