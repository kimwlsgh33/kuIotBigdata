#include <iostream>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
using namespace cv;
using namespace std;

String folder = "/Users/skoler/devs/projects/kuIotBigdata/opencv/data/";

int main() {
  // Declare matrices to hold frames
  Mat frame, doubleFrame, reshapedFrame;

  // Open a video file for reading
  VideoCapture cap(folder + "vtest.avi");

  // Check if the video file is opened successfully
  if (!cap.isOpened()) {
    cerr << "Video open failed.\n";
    return -1; // indicate failure
  }

  // Print frame width and height
  cout << "Frame width: " << cap.get(CAP_PROP_FRAME_WIDTH) << endl;
  cout << "Frame height: " << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;

  // Create a Size object to store frame size
  Size sz1(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));

  // Define a vector to store shape information for reshaping
  std::vector<int> shape = {sz1.width / 2, sz1.height * 2};

  // Get frames per second (fps) of the video
  double fps = cap.get(CAP_PROP_FPS);

  // Define the codec and creat VideoWriter object for output
  int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
  VideoWriter outputVideo(folder + "output1.avi", fourcc, fps, sz1 * 2);

  // Calculate delay(ms) between frames based on fps
  int delay = cvRound(1000 / fps);

  while (true) {
    // Read a frame from the video
    cap >> frame;

    // Resize the frame to double its size
    resize(frame, doubleFrame, sz1 * 2);

    // Reshape the frame using the shape vector
    reshapedFrame = frame.reshape(3, shape);

    // Display the original frame
    imshow("frame", frame);

    // Display the doubled frame
    imshow("doubleFrame", doubleFrame);

    // Write the doubled frame to the output video
    outputVideo << doubleFrame;

    // Display the reshaped frame
    imshow("reshapedFrame", reshapedFrame);

    // Wait for a key press for a specified delay time
    // If the pressed key is ESC (ASCII code 27), exit the loop
    if (waitKey(int(delay)) == 27)
      break;
  }

  // Close all OpenCV windows
  destroyAllWindows();
}
