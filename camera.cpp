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
    cap.open(deviceID, apiID);
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