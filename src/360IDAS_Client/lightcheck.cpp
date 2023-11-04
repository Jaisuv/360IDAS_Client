#include "lightcheck.h"

LightCheck::LightCheck()
{

}

int LightCheck::processImgR(Mat src)
{
    Mat tmp;

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    vector<Point> hull;

    CvPoint2D32f tempNode;
    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* pointSeq = cvCreateSeq(CV_32FC2, sizeof(CvSeq), sizeof(CvPoint2D32f), storage);

    Rect* trackBox;
    Rect* result;
    int resultNum = 0;

    int area = 0;
    src.copyTo(tmp);
    //提取轮廓
    findContours(tmp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0)
    {
        trackBox = new Rect[contours.size()];
        result = new Rect[contours.size()];

        //确定要跟踪的区域
        for (int i = 0; i < contours.size(); i++)
        {
            cvClearSeq(pointSeq);
            // 获取凸包的点集
            convexHull(Mat(contours[i]), hull, true);
            int hullcount = (int)hull.size();
            // 凸包的保存点
            for (int j = 0; j < hullcount - 1; j++)
            {
                tempNode.x = hull[j].x;
                tempNode.y = hull[j].y;
                cvSeqPush(pointSeq, &tempNode);
            }

            trackBox[i] = cvBoundingRect(pointSeq);
        }

        if (isFirstDetectedR)
        {
            lastTrackBoxR = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
                lastTrackBoxR[i] = trackBox[i];
            lastTrackNumR = contours.size();
            isFirstDetectedR = false;
        }
        else
        {
            for (int i = 0; i < contours.size(); i++)
            {
                for (int j = 0; j < lastTrackNumR; j++)
                {
                    if (isIntersected(trackBox[i], lastTrackBoxR[j]))
                    {
                        result[resultNum] = trackBox[i];
                        break;
                    }
                }
                resultNum++;
            }
            delete[] lastTrackBoxR;
            lastTrackBoxR = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
            {
                lastTrackBoxR[i] = trackBox[i];
            }
            lastTrackNumR = contours.size();
        }

        delete[] trackBox;
    }
    else
    {
        isFirstDetectedR = true;
        result = NULL;
    }
    cvReleaseMemStorage(&storage);

    if (result != NULL)
    {
        for (int i = 0; i < resultNum; i++)
        {
            area += result[i].area();
        }
    }
    delete[] result;

    return area;
}

int LightCheck::processImgG(Mat src)
{
    Mat tmp;

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    vector< Point > hull;

    CvPoint2D32f tempNode;
    CvMemStorage* storage = cvCreateMemStorage();
    CvSeq* pointSeq = cvCreateSeq(CV_32FC2, sizeof(CvSeq), sizeof(CvPoint2D32f), storage);

    Rect* trackBox;
    Rect* result;
    int resultNum = 0;

    int area = 0;

    src.copyTo(tmp);
    // Extract the contour
    findContours(tmp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if (contours.size() > 0)
    {
        trackBox = new Rect[contours.size()];
        result = new Rect[contours.size()];

        // Determine the area to track
        for (int i = 0; i < contours.size(); i++)
        {
            cvClearSeq(pointSeq);
            // Get the point set of the convex hull
            convexHull(Mat(contours[i]), hull, true);
            int hullcount = (int)hull.size();
            // Save points of the convex hull
            for (int j = 0; j < hullcount - 1; j++)
            {
                //line(showImg, hull[j + 1], hull[j], Scalar(255, 0, 0), 2, CV_AA);
                tempNode.x = hull[j].x;
                tempNode.y = hull[j].y;
                cvSeqPush(pointSeq, &tempNode);
            }

            trackBox[i] = cvBoundingRect(pointSeq);
        }

        if (isFirstDetectedG)
        {
            lastTrackBoxG = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
                lastTrackBoxG[i] = trackBox[i];
            lastTrackNumG = contours.size();
            isFirstDetectedG = false;
        }
        else
        {
            for (int i = 0; i < contours.size(); i++)
            {
                for (int j = 0; j < lastTrackNumG; j++)
                {
                    if (isIntersected(trackBox[i], lastTrackBoxG[j]))
                    {
                        result[resultNum] = trackBox[i];
                        break;
                    }
                }
                resultNum++;
            }
            delete[] lastTrackBoxG;
            lastTrackBoxG = new Rect[contours.size()];
            for (int i = 0; i < contours.size(); i++)
            {
                lastTrackBoxG[i] = trackBox[i];
            }
            lastTrackNumG = contours.size();
        }

        delete[] trackBox;
    }
    else
    {
        isFirstDetectedG = true;
        result = NULL;
    }
    cvReleaseMemStorage(&storage);

    if (result != NULL)
    {
        for (int i = 0; i < resultNum; i++)
        {
            area += result[i].area();
        }
    }
    delete[] result;

    return area;
}

bool LightCheck::isIntersected(Rect r1, Rect r2)
{
    int minX = max(r1.x, r2.x);
    int minY = max(r1.y, r2.y);
    int maxX = min(r1.x + r1.width, r2.x + r2.width);
    int maxY = min(r1.y + r1.height, r2.y + r2.height);

    if (minX < maxX && minY < maxY)
        return true;
    else
        return false;
}

void LightCheck::LightCheckFunc(Mat &frame)
{
    int redCount = 0;
    int greenCount = 0;

    Mat img;
    Mat imgYCrCb;
    Mat imgGreen;
    Mat imgRed;

    // 亮度参数
    double a = 0.3; // gain, modify this only.
    double b = (1 - a) * 125; // bias
    //调整亮度
    frame.convertTo(img,img.type(),a,b);
    //转换为YCrCb颜色空间
    cvtColor(img, imgYCrCb, CV_BGR2YCrCb);

    imgRed.create(imgYCrCb.rows, imgYCrCb.cols, CV_8UC1);
    imgGreen.create(imgYCrCb.rows, imgYCrCb.cols, CV_8UC1);

    //分解YCrCb的三个成分
    vector<Mat> planes;
    split(imgYCrCb, planes);
    // 遍历以根据Cr分量拆分红色和绿色
    MatIterator_<uchar> it_Cr = planes[1].begin<uchar>(),
                        it_Cr_end = planes[1].end<uchar>();
    MatIterator_<uchar> it_Red = imgRed.begin<uchar>();
    MatIterator_<uchar> it_Green = imgGreen.begin<uchar>();

    for (; it_Cr != it_Cr_end; ++it_Cr, ++it_Red, ++it_Green)
    {
        // RED, 145<Cr<470
        if (*it_Cr > 145 && *it_Cr < 470)
            *it_Red = 255;
        else
            *it_Red = 0;

        // GREEN 95<Cr<110
        if (*it_Cr > 95 && *it_Cr < 110)
            *it_Green = 255;
        else
            *it_Green = 0;
    }
    //膨胀和腐蚀
    dilate(imgRed, imgRed, Mat(15, 15, CV_8UC1), Point(-1, -1));
    erode(imgRed, imgRed, Mat(1, 1, CV_8UC1), Point(-1, -1));
    dilate(imgGreen, imgGreen, Mat(15, 15, CV_8UC1), Point(-1, -1));
    erode(imgGreen, imgGreen, Mat(1, 1, CV_8UC1), Point(-1, -1));

    redCount = processImgR(imgRed);
    greenCount = processImgG(imgGreen);

    if(redCount == 0 && greenCount == 0)
    {
        cv::putText(frame, "NULL", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(255, 255, 255), 2, 8, 0);
    }else if(redCount > greenCount)
    {
        cv::putText(frame, "red", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 0, 255), 2, 8, 0);
    }else{
        cv::putText(frame, "green", Point(200, 150), cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 0), 2, 8, 0);
    }
}
