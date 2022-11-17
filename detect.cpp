#include "detect.h"
#include "QDebug"
#include <ctime>
#include <iostream>
#include <stdlib.h>

using namespace cv;
using namespace std;
// 1280*960
const int RANGE_OF_CONV_HIST = 30;
const int DEFECT_OPTICAL_THRESHOLD = 45;

void filterDefectDetect(Mat &image, DetectResult &result, DetectCfg detectCfg, int count)
{
    //imwrite("C:\\Users\\HuntZou\\Documents\\Personal\\Projects\\filter_defect\\imgs\\real\\all\\"+std::to_string(std::time(0))+"_"+std::to_string(rand())+"_bad.jpg", image);
    clock_t startT, endT;
    startT = clock();

    image.convertTo(image, 5);

    GaussianBlur(image, image, Size(9, 9), 0);
    // 将图片灰度值标准化到 [0, 255]
    double minVal, maxVal;
    minMaxIdx(image, &minVal, &maxVal);
    image = abs((image - minVal) * 255 / (maxVal - minVal));

    // 寻找大圆边框
    image.convertTo(image, 0);
    vector<Vec3f> circles;

    std::string prefix = "D:\\Tmp\\";
    HoughCircles(image, circles, HOUGH_GRADIENT, 5, 1280, 35.0, 200.0, 685 / 2, 715 / 2);
    if (circles.size() != 1)
    {
//        imshow("img", image);
//        waitKey(0);
        qDebug() << "Unexpected circle size: " << circles.size();
        std::string name = prefix + "bad\\" + std::to_string(count) + "_bad.jpg";
//        imwrite(name, image);
        return;
    }

    Vec3f outline = circles[0];
    Point center(cvRound(outline[0]), cvRound(outline[1]));
    int radius = cvRound(outline[2]);

    // 有些圆虽然检测出来了，但它只有部分在图片中，不是一个整圆
    if (center.x + radius > image.cols || center.y + radius > image.rows || center.x < radius || center.y < radius)
    {
//        Mat outlineCircle = image.clone();
//        circle(outlineCircle, center, radius, 1, 5, 8, 0);
//        imwrite(prefix + "mid\\" + std::to_string(count) + "_org.jpg", image);
//        imwrite(prefix + "mid\\" + std::to_string(count) + "_mark.jpg", outlineCircle);
        return;
    }


//    Mat outlineCircle = image.clone();
//    circle(outlineCircle, center, radius, 1, 5, 8, 0);
//    imwrite(prefix + "good\\" + std::to_string(count) + "_org.jpg", image);
//    imwrite(prefix + "good\\" + std::to_string(count) + "_mark.jpg", outlineCircle);

    // 裁剪出轮廓
    image = image(Rect(center.x - radius, center.y - radius, radius * 2, radius * 2));
    resize(image, image, Size(detectCfg.getResize(), detectCfg.getResize()));
    // 创建大圆蒙版
    Mat outlineMask = Mat::zeros(Size(detectCfg.getResize(), detectCfg.getResize()), 0);
    circle(outlineMask, Point(detectCfg.getResize() / 2, detectCfg.getResize() / 2), detectCfg.getResize() / 2, 1, -1, 8, 0);
    // 裁剪轮廓
    image.copyTo(image, outlineMask);

    // TODO: 计算直方图，用于动态分离轮廓和内部图形，但考虑到速度，还是直接给一个定值就好
//    MatND hist;
//    int hsize = { 255 };
//    float hranges[] = { 1,256 };
//    const float* phranges = { hranges };
//    calcHist(&image, 1, 0, Mat(), hist, 1, &hsize, &phranges, true, false);

//    // 对直方图进行卷积，获取二值化的阈值
//    int histConvRes[255] = { 0 };

//    for (int i = 0; i < hist.rows - RANGE_OF_CONV_HIST; i++)
//    {
//        for (int j = 0; j < RANGE_OF_CONV_HIST; j++)
//        {
//            histConvRes[i] += hist.at<float>(i + j, 0);
//        }
//    }
    // --------------------------------end---------------------

    // 二值化图像用于提取内部图形
    Mat outlineThresholdImg;
    threshold(image, outlineThresholdImg, detectCfg.getOutlineGrayThreshold(), 255, THRESH_BINARY);
    // 形态学处理去掉内部的杂质便于获取内部图形
    Mat outlineThresholdImgWithoutDefect = outlineThresholdImg.clone();
    morphologyEx(outlineThresholdImgWithoutDefect, outlineThresholdImgWithoutDefect, MORPH_ERODE, getStructuringElement(MORPH_CROSS, Size(10, 10)));
    morphologyEx(outlineThresholdImgWithoutDefect, outlineThresholdImgWithoutDefect, MORPH_ERODE, getStructuringElement(MORPH_CROSS, Size(4, 4)));

    // 寻找轮廓，并找到第二大的即为内部图形轮廓（第一大的为外部轮廓）
    vector<vector<Point>> contoursQuery;
    findContours(outlineThresholdImgWithoutDefect, contoursQuery, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    if (contoursQuery.size() == 0)
    {
        std::string name = prefix + "other\\" + std::to_string(count) + "_nocontours.jpg";
        imwrite(name, image);
        qDebug() << "Unexpected contour size: " << circles.size();
        return;
    }
    double top2Area[2][2] = { {0., 0.}, {0., 0.} };
    for (int i = 0; i < contoursQuery.size(); i++)
    {
        if (contoursQuery[i].size() < 500) continue; // 减少计算量
        double area = contourArea(contoursQuery[i]);
        if (top2Area[0][0] < area)
        {
            top2Area[0][0] = area;
            top2Area[0][1] = i;
        }
        else if (top2Area[1][0] < area)
        {
            top2Area[1][0] = area;
            top2Area[1][1] = i;
        }
    }

    // 创建内部图形蒙版并提取内部二值化图形
    Mat shapeMask = Mat::zeros(Size(detectCfg.getResize(), detectCfg.getResize()), 0);
    drawContours(shapeMask, contoursQuery, top2Area[1][1], 1, -1);
    drawContours(image, contoursQuery, top2Area[1][1], 1, 3);
    // TODO: 这里应该对蒙版形状做稀释操作，先不做看看效果
    Mat shapeImg;
    image.copyTo(shapeImg, shapeMask);

    // 创建图形边界蒙版，上面得到的内部二值化图形减去边界就是杂质
    Mat shapeBorderMask = Mat::ones(Size(detectCfg.getResize(), detectCfg.getResize()), 0);
    drawContours(shapeBorderMask, contoursQuery, top2Area[1][1], 0, 45);

    // 提取杂质
    Mat defectImgY;
    Sobel(shapeImg, defectImgY, 0, 0, 1);
    Mat defectImgX;
    Sobel(shapeImg, defectImgX, 0, 1, 0);
    Mat defectImgWhthBorder = defectImgY + defectImgX;
    Mat defectImg;
    defectImgWhthBorder.copyTo(defectImg, shapeBorderMask);

    threshold(defectImg, defectImg, 50, 255, THRESH_BINARY);

//    minMaxIdx(defectImg, &minVal, &maxVal);

//    defectImg = abs((defectImg - minVal) * 255 / (maxVal - minVal));

//    threshold(defectImg, defectImg, DEFECT_OPTICAL_THRESHOLD, 255, THRESH_BINARY);
    morphologyEx(defectImg, defectImg, MORPH_ERODE, getStructuringElement(MORPH_RECT, Size(3, 3)));
    morphologyEx(defectImg, defectImg, MORPH_DILATE, getStructuringElement(MORPH_RECT, Size(4, 4)));
    // 方法二：直接使用二值化图像得到瑕疵
//    defectImg = outlineThresholdImg - (shapeBorderMask * 255);

    // 杂质面积
    vector<vector<Point>> defectAreaContours;
    findContours(defectImg, defectAreaContours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (auto defectAreaContoursIter = defectAreaContours.begin(); defectAreaContoursIter != defectAreaContours.end();)
    {
        auto areaTmp = contourArea(*defectAreaContoursIter);
        if (areaTmp > 200000 || areaTmp < 200)
        {
            defectAreaContoursIter = defectAreaContours.erase(defectAreaContoursIter);
        } else{
            ++defectAreaContoursIter;
        }
    }
    drawContours(image, defectAreaContours, -1, 0, -1);

    double defectAreas = 0;
    for (int i = 0; i < defectAreaContours.size(); i++)
    {
        defectAreas += contourArea(defectAreaContours[i]);
    }
    result.defectArea = defectAreas;
    // ********************************************特殊图形******************************************
    switch (detectCfg.getShape())
    {
    case Shape::CIRCLE:
    {
        // 圆心和半径
        Point2f circleCenter;
        float circleRadius = 0;
        minEnclosingCircle(contoursQuery[top2Area[1][1]], circleCenter, circleRadius);
        circle(image, circleCenter, circleRadius, CV_RGB(255, 0, 0), 1);
        result.extraDoubleData.push_back(circleRadius);
        result.extraDoubleData.push_back(sqrt(pow(circleCenter.x - (detectCfg.getResize()/2), 2) + pow(circleCenter.y - (detectCfg.getResize()/2), 2)));
        break;
    }
    case Shape::STAR:
    {
        // 最小凸包
        vector<Point> hulls;
        convexHull(contoursQuery[top2Area[1][1]], hulls);
        // 找到五角星的5个顶点
        //KMeans(hull, vertex);
        cv::Mat labels;
        std::vector<Point2f> vertex;
        vector<Point2f> hulls2f;
        std::transform(hulls.begin(), hulls.end(), std::back_inserter(hulls2f), [](const Point& p) { return (Point2f)p;});
        if (hulls2f.size() < 5)
        {
            qDebug() << "wrong hull size: " << hulls2f.size();
            return;
        }
        cv::kmeans(hulls2f, 5, labels, TermCriteria( TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0), 3, cv::KMEANS_PP_CENTERS, vertex);

        // 对顶点坐标排序，方便后续找对应的边
        sort(vertex.begin(), vertex.end(), starVertexCompare);

        for (int i = 0; i < vertex.size(); i++)
        {
            //circle(image, vertex[i], 10 + i * 10, 0, -1);
        }
        // 霍夫直线检测找到边
        Mat canny;
        Canny(shapeMask, canny, 1, 1);
        vector<Vec4i> lines;
        HoughLinesP(canny, lines, 1., acos(-1) / 180, 30, 60, 80);

        // 找到每条线对应的顶点
        vector<vector<int>> categoriedLineIdxs(5);
        for (int i = 0; i < lines.size(); i++)
        {
            //line(image, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), 0, 1);
            // 线的中点离哪个顶点最近就属于哪个顶点
            Point lineCenterPoint = Point((lines[i][0] + lines[i][2])/2, (lines[i][1] + lines[i][3])/2);

            double min = 99999;
            int belongVertexIdx;
            for (int j = 0; j < vertex.size(); j++)
            {
                double d = pow(vertex[j].x - lineCenterPoint.x, 2) + pow(vertex[j].y - lineCenterPoint.y, 2);
                if (d < min)
                {
                    min = d;
                    belongVertexIdx = j;
                }
            }
            categoriedLineIdxs[belongVertexIdx].push_back(i);
        }

        // 将顶点对应的线分为左右两部分，使用向量的叉乘判断位置，如果向量与中心线叉乘小于0，则该向量在中心线的右边
        float angles[5];
        for (int vertexIdx = 0; vertexIdx < categoriedLineIdxs.size(); vertexIdx++)
        {
            double centerVecX = (vertex[(vertexIdx + 1) % 5].x + vertex[(vertexIdx + 4) % 5].x) / 2;
            double centerVecY = (vertex[(vertexIdx + 1) % 5].y + vertex[(vertexIdx + 4) % 5].y) / 2;
            Point centerVec = Point(centerVecX - vertex[vertexIdx].x, centerVecY - vertex[vertexIdx].y);

            //line(image, centerVec, vertex[vertexIdx], 0, 3);
            float angleL = 0;
            float angleR = 0;
            int leftLineCount = 0;
            for (int i = 0; i < categoriedLineIdxs[vertexIdx].size(); i++)
            {
                int lineIdx = categoriedLineIdxs[vertexIdx][i];

                Point vec;
                if (pow(lines[lineIdx][0] - vertex[vertexIdx].x, 2) + pow(lines[lineIdx][1] - vertex[vertexIdx].y, 2) < pow(lines[lineIdx][2] - vertex[vertexIdx].x, 2) + pow(lines[lineIdx][3] - vertex[vertexIdx].y, 2))
                    vec = Point(lines[lineIdx][2] - lines[lineIdx][0], lines[lineIdx][3] - lines[lineIdx][1]);
                else
                    vec = Point(lines[lineIdx][0] - lines[lineIdx][2], lines[lineIdx][1] - lines[lineIdx][3]);

                float angle = (vec.x * centerVec.x + vec.y * centerVec.y) / (sqrt(pow(vec.x, 2) + pow(vec.y, 2)) * sqrt(pow(centerVec.x, 2) + pow(centerVec.y, 2)));
                // 根据叉乘判断位置
                if (vec.x * centerVec.y - vec.y * centerVec.x > 0)
                {
                    ++leftLineCount;
                    angleL += angle;
                }
                else
                    angleR += angle;
            }
            angles[vertexIdx] = (acos(angleL / leftLineCount) + acos(angleR / (categoriedLineIdxs[vertexIdx].size() - leftLineCount))) * 180/ 3.14;
            result.extraDoubleData.push_back(angles[vertexIdx]);

        }
        break;
    }
    case Shape::COIN:
    {
        Mat outsideBox;
        RotatedRect outsideRotatedRect = minAreaRect(contoursQuery[top2Area[1][1]]);
        boxPoints(outsideRotatedRect, outsideBox);
        std::vector<cv::Point> crossEndPoints = ministDistanceToLine(outsideBox, contoursQuery[top2Area[1][1]]);
        for (int i = 0; i < crossEndPoints.size(); i++)
            circle(image, Point(crossEndPoints[i]), 10, 0, -1);

        // 外四边形四条边长
        result.extraDoubleData.push_back(outsideRotatedRect.boundingRect().width);
        result.extraDoubleData.push_back(outsideRotatedRect.boundingRect().height);
        result.extraDoubleData.push_back(outsideRotatedRect.boundingRect().width);
        result.extraDoubleData.push_back(outsideRotatedRect.boundingRect().height);

        // 内四边形对边长度
        double insideRectLength[2];
        insideRectLength[0] = sqrt(pow(crossEndPoints[0].x - crossEndPoints[1].x, 2) + pow(crossEndPoints[0].y - crossEndPoints[1].y, 2));
        insideRectLength[1] = sqrt(pow(crossEndPoints[2].x - crossEndPoints[3].x, 2) + pow(crossEndPoints[2].y - crossEndPoints[3].y, 2));

        result.extraDoubleData.push_back(insideRectLength[0]);
        result.extraDoubleData.push_back(insideRectLength[1]);
        result.extraDoubleData.push_back(insideRectLength[0]);
        result.extraDoubleData.push_back(insideRectLength[1]);
        break;

    }
    default:
        break;
    }

    endT = clock();
    result.detected = true;
    result.cost = (endT - startT);
    return;
}

std::string shapeToString(Shape shape)
{
    switch(shape)
    {
    case Shape::HEART_SMALL: return "HEART_SMALL";
    case Shape::HEART_BIG: return "HEART_BIG";
    case Shape::COIN: return "COIN";
    case Shape::WINTERSWEET_SMALL: return "WINTERSWEET_SMALL";
    case Shape::WINTERSWEET_BIG: return "WINTERSWEET_BIG";
    case Shape::RAY: return "RAY";
    case Shape::STAR: return "STAR";
    case Shape::CIRCLE: return "CIRCLE";
    case Shape::PEACH: return "PEACH";
    default: return "UNKNOWN";
    }
}
