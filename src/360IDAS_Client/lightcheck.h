#ifndef LIGHTCHECK_H
#define LIGHTCHECK_H

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

class LightCheck
{
public:
    LightCheck();

    int processImgR(Mat src);
    int processImgG(Mat src);
    bool isIntersected(Rect r1, Rect r2);

    void LightCheckFunc(Mat &frame);

private:
    bool isFirstDetectedR = true;
    bool isFirstDetectedG = true;
    Rect* lastTrackBoxR;
    Rect* lastTrackBoxG;
    int lastTrackNumR;
    int lastTrackNumG;

};

#endif // LIGHTCHECK_H
