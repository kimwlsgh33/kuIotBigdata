#include <opencv2/opencv.hpp>

using namespace cv;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

// Callback function for mouse events
void onMouse(int event, int x, int y, int flags, void *userdata) {
  if (event == EVENT_MOUSEMOVE) {
    // Get the image pointer
    Mat *image = static_cast<Mat *>(userdata);
    *image = imread(folder + "lenna.bmp", IMREAD_COLOR);
    imshow("Image with Cursor", *image);
    // Draw a circle representing the mouse cursor on the image
    circle(*image, Point(x, y), 5, Scalar(0, 255, 0),
           -1); // Green circle with radius 5
    imshow("Image with Cursor", *image);
  }
}

int main() {
  // Read an image
  Mat image = imread(folder + "lenna.bmp", IMREAD_COLOR);

  if (image.empty()) {
    std::cerr << "Error: Couldn't load the image." << std::endl;
    return -1;
  }

  // Create a window and display the image
  namedWindow("Image with Cursor");
  imshow("Image with Cursor", image);

  // Set the mouse callback function
  setMouseCallback("Image with Cursor", onMouse, &image);

  // Wait for a key press
  waitKey(0);

  return 0;
}
