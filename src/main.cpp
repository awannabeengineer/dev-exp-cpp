#include <iostream>
// #include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

// wtf are files the issue here???
// #include <fstream>
// #include <string>

// using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  // Print OpenCV build information
  // std::cout << cv::getBuildInformation() << std::endl;

  if (argc < 2) {
    std::cerr << "give file name" << std::endl;
    return -1;
  }

  // Open the default camera
  cv::VideoCapture cap(argv[1]);

  if (!cap.isOpened()) {
    std::cerr << "Error: Could not open video file" << std::endl;
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
  cap.release();
  cv::destroyAllWindows();

  // open image
  // Mat img = imread(argv[1], IMREAD_COLOR);
  // if(img.empty()) {
  //   std::cout << "could not open image" << std::endl;
  //   return -1;
  // }
  // imshow("title", img);
  // cv::waitKey(0);

  // just read a fucking file
  // std::ifstream file(argv[1]);
  // std::string str;
  // while (std::getline(file, str)) {
  //   std::cout << str << std::endl;
  // }

  return 0;
}
