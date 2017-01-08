#include "Libfreenect2OpenCV.h"

#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    libfreenect2opencv::Libfreenect2OpenCV libfreenect2OpenCV;
    int key = 0;

    libfreenect2OpenCV.start();

    while (key <= 0) {
        cv::Mat img = libfreenect2OpenCV.getRgbMat();
        cv::Mat edges;

        cv::cvtColor(img, img, CV_BGR2GRAY);
        cv::Canny(img, edges, 120, 175);
        cv::imshow("edges 1.5", edges);
        cv::imshow("RgpMat", img);

        key = cv::waitKey(1);
    }

    libfreenect2OpenCV.stop();
}
