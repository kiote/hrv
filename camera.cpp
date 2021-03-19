#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;

Mat frame, cap_img;
VideoCapture cap;
int deviceID = 0;
int apiID = cv::CAP_ANY;
    
int main(int, char**) {
    cout << "OpenCV version : " << CV_VERSION << endl;
   
    cap.open("v4l2src device=/dev/video0 ! video/x-raw, format=YUY2, width=640, height=480, framerate=30/1 ! videoconvert ! video/x-raw, format=BGR ! appsink");
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    cout << "Start grabbing" << endl;
    while(true) {
        cap >> frame;
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        imshow("Live", frame);
        if (waitKey(1) >= 27)
            break;
    }
    return 0;
}  