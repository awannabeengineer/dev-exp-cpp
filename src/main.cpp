#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  // Print OpenCV build information
  std::cout << cv::getBuildInformation() << std::endl;

  // Open the default camera
  cv::VideoCapture cap(0);

  if (!cap.isOpened()) {
    std::cerr << "Error: Could not open camera" << std::endl;
    return -1;
  }

  cv::Mat frame;
  while (true) {
    cap >> frame;
    if (frame.empty()) {
      std::cerr << "irror: Blank frame grabbed" << std::endl;
      break;
    }

    cv::imshow("Camera", frame);

    if (cv::waitKey(30) >= 0)
      break;
  }

  return 0;
}
