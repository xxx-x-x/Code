#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    // imread to read picture
    Mat img = imread("1.png");
    // nameWindow create a windows
    namedWindow("pictures");
    // wait a key
    imshow("pictures",img);
    int rKey = waitKey(0);
    if(rKey == 32)
    {
        return 0;
    }
    return 0;
}
//g++ main.cpp -o main $(pkg-config --cflags --libs opencv4)