#include "utils.h"
#include <iostream>
#include <QDebug>

//计算两个元组间的欧几里距离
float getDistXY(cv::Point t1, cv::Point t2)
{
    return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}

//根据质心，决定当前元组属于哪个簇
int clusterOfTuple(cv::Point means[], cv::Point tuple) {
    float dist = getDistXY(means[0], tuple);
    float tmp;
    int label = 0;//标示属于哪一个簇
    for (int i = 1; i < 5; i++) {
        tmp = getDistXY(means[i], tuple);
        if (tmp < dist) { dist = tmp; label = i; }
    }
    return label;
}
//获得给定簇集的平方误差
float getVar(std::vector<cv::Point> clusters[], cv::Point means[]) {
    float var = 0;
    for (int i = 0; i < 5; i++)
    {
        std::vector<cv::Point> t = clusters[i];
        for (int j = 0; j < t.size(); j++)
        {
            var += getDistXY(t[j], means[i]);
        }
    }
    //cout<<"sum:"<<sum<<endl;
    return var;

}
//获得当前簇的均值（质心）
cv::Point getMeans(std::vector<cv::Point> cluster) {

    int num = cluster.size();
    double meansX = 0, meansY = 0;
    cv::Point t;
    for (int i = 0; i < num; i++)
    {
        meansX += cluster[i].x;
        meansY += cluster[i].y;
    }
    t.x = meansX / num;
    t.y = meansY / num;
    return t;
    //cout<<"sum:"<<sum<<endl;


}
void KMeans(std::vector<cv::Point> tuples, cv::Point* means) {
    std::vector<cv::Point> clusters[5];
    //Point means[5];
    int i = 0;
    //默认一开始将前K个元组的值作为k个簇的质心（均值）
    for (i = 0; i < 5; i++) {
        means[i].x = tuples[i].x;
        means[i].y = tuples[i].y;
    }
    int lable = 0;
    //根据默认的质心给簇赋值
    for (i = 0; i != tuples.size(); ++i) {
        lable = clusterOfTuple(means, tuples[i]);
        clusters[lable].push_back(tuples[i]);
    }
    //输出刚开始的簇
    for (lable = 0; lable < 5; lable++) {
        std::cout << "第" << lable + 1 << "个簇：" << std::endl;
        std::vector<cv::Point> t = clusters[lable];
        for (i = 0; i < t.size(); i++)
        {
            std::cout << "(" << t[i].x << "," << t[i].y << ")" << "   ";
        }
        std::cout << std::endl;
    }
    float oldVar = -1;
    float newVar = getVar(clusters, means);
    while (abs(newVar - oldVar) >= 1) //当新旧函数值相差不到1即准则函数值不发生明显变化时，算法终止
    {

        for (i = 0; i < 5; i++) //更新每个簇的中心点
        {
            means[i] = getMeans(clusters[i]);
            //cout<<"means["<<i<<"]:"<<means[i].x<<"  "<<means[i].y<<endl;
        }
        oldVar = newVar;
        newVar = getVar(clusters, means); //计算新的准则函数值
        for (i = 0; i < 5; i++) //清空每个簇
        {
            clusters[i].clear();
        }
        //根据新的质心获得新的簇
        for (i = 0; i != tuples.size(); ++i) {
            lable = clusterOfTuple(means, tuples[i]);
            clusters[lable].push_back(tuples[i]);
        }
        //输出当前的簇
        for (lable = 0; lable < 5; lable++) {
            std::cout << "第" << lable + 1 << "个簇：" << std::endl;
            std::vector<cv::Point> t = clusters[lable];
            for (i = 0; i < t.size(); i++)
            {
                std::cout << "(" << t[i].x << "," << t[i].y << ")" << "   ";
            }
            std::cout << std::endl;
        }
    }

}
QImage mat2QImage(cv::Mat &matImg, int count)
{
    QImage img = QImage(matImg.data, matImg.cols, matImg.rows, matImg.cols * matImg.channels(), QImage::Format_Indexed8);
//    img.save(QString("C:\\Users\\HuntZou\\Documents\\Personal\\Temporary\\pics\\mat2QImage_%1.png").arg(count),"PNG", -1);
    return img;
}

void coinRectDetect(std::vector<cv::Point> shapeContour)
{
    // 外四边形拟合
    std::vector<cv::Point> outsideRectContour;
    approxPolyDP(shapeContour, outsideRectContour, 100, true);
    std::vector<std::vector<cv::Point>> outsideRectContours {outsideRectContour};
    //drawContours(image, outsideRectContours, 0, 0, 5);
    // 内四边形拟合
    double maxDis[4][3] = { {0} };
    int currentLineIdx = 0;
    for (int i = 10; i < shapeContour.size(); i++)
    {
        if (shapeContour[i].x == outsideRectContour[currentLineIdx].x && shapeContour[i].y == outsideRectContour[currentLineIdx].y)
        {
            currentLineIdx = (currentLineIdx + 1) % 4;
            continue;
        }
        int x1 = outsideRectContour[currentLineIdx].x;
        int y1 = outsideRectContour[currentLineIdx].y;
        int x2 = outsideRectContour[(currentLineIdx + 1) % 4].x;
        int y2 = outsideRectContour[(currentLineIdx + 1) % 4].y;
        int A = y2 - y1;
        int B = x1 - x2;
        int C = x2 * y1 - x1 * y2;
        //qDebug() << "currentLineIdx: " << currentLineIdx;
        //qDebug() << "A: " << A << ", B: " << B << ", C: " << C << ", x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << ", x: " << contoursQuery[top2Area[1][1]][i].x << ", y: " << contoursQuery[top2Area[1][1]][i].y;
        double d = abs((shapeContour[i].x * A + B * shapeContour[i].y + C)) / sqrt(pow(A,2) + pow(B, 2));
        //qDebug() << d;

    //qDebug() << "A: " << (maxDis[currentLineIdx][0] < d) << ", B: " << (pointPolygonTest(outsideRectContour, contoursQuery[top2Area[1][1]][i], false) > 0);

        if (maxDis[currentLineIdx][0] < d && pointPolygonTest(outsideRectContour, shapeContour[i], false) > 0)
        {
            //qDebug() << "currentLineIdx: " << currentLineIdx;
            maxDis[currentLineIdx][0] = d;
            maxDis[currentLineIdx][1] = shapeContour[i].x;
            maxDis[currentLineIdx][2] = shapeContour[i].y;
        }
    }

    // 计算内四边形四条边的方程
    double params[4][2] = { {0} };
    for (int i = 0; i < 4; i++)
    {
        params[i][0] = (outsideRectContour[i].y - outsideRectContour[(i + 1) % 4].y) / (outsideRectContour[i].x - outsideRectContour[(i + 1) % 4].x);
        params[i][1] = maxDis[i][2] - params[i][0] * maxDis[i][1];
    }
    std::vector<cv::Point> insideRectPoints;
    // 计算四条边的各个交点
    for (int i = 0; i < 4; i++)
    {
        double x = (params[(i + 1) % 4][1] - params[i][1]) / (params[(i + 1) % 4][0] - params[i][0]);
        double y = params[i][0] * x + params[i][1];
        insideRectPoints.push_back(cv::Point(x, y));
    }


    for (int i = 0; i < insideRectPoints.size(); i++)
    {
        //qDebug() << insideRectPoints[i].x << ", " << insideRectPoints[i].y;
        //line(image, insideRectPoints[i], insideRectPoints[(i+1)%4], 0, 50);
    }

    // 外四边形平均边长
    double avgLenOutside = 0;
    for (int i = 0; i < outsideRectContour.size(); i++)
    {
        avgLenOutside += (sqrt(pow(outsideRectContour[(i + 1) % 4].y - outsideRectContour[i].y, 2) + pow(outsideRectContour[(i + 1) % 4].x - outsideRectContour[i].x,2)) / 4);
    }

    // 内四边形平均边长
    double avgLenInside = 0;
    for (int i = 0; i < insideRectPoints.size(); i++)
    {
        avgLenInside += (sqrt(pow(insideRectPoints[(i + 1) % 4].y - insideRectPoints[i].y, 2) + pow(insideRectPoints[(i + 1) % 4].x - insideRectPoints[i].x,2)) / 4);
    }
}

/**
 * 获取直线向量
 * @brief lineVector
 * @param line
 */
cv::Point lineVector(cv::Vec4i line)
{
    return pow(line[0], 2) + pow(line[1], 2) > pow(line[2], 2) + pow(line[3], 2) ? cv::Point(line[0] - line[2], line[1] - line[3]) : cv::Point(line[2] - line[0], line[3] - line[1]);
}

/**
 * @brief lineAngle
 * @param line
 * @return 直线与x轴正方向的夹角
 */
float lineAngle(cv::Vec4i line)
{
    cv::Point vec;
    if (pow(line[0], 2) + pow(line[1], 2) > pow(line[2], 2) + pow(line[3], 2))
        vec = cv::Point(line[0] - line[2], line[1] - line[3]);
    else
        vec = cv::Point(line[2] - line[0], line[3] - line[1]);
    float angle = atan2(vec.y, vec.x);
    return (angle < 0 ? angle + (2 * 3.1415926) : angle) * 180 / 3.1415;
}


bool starVertexCompare(const cv::Point2f &a, const cv::Point2f &b) {
    float angleA = atan2(a.y - 500, a.x - 500);
    float angleB = atan2(b.y - 500, b.x - 500);
    return (angleA < 0 ? angleA + (2 * 3.1415926) : angleA) < (angleB < 0 ? angleB + (2 * 3.1415926) : angleB);
}

float distanceOfP2L(cv::Point line[2], cv::Point p)
{
    long x1 = line[0].x;
    long y1 = line[0].y;
    long x2 = line[1].x;
    long y2 = line[1].y;
    long A = y2 - y1;
    long B = x1 - x2;
    long C = x2 * y1 - x1 * y2;
    double d = abs((p.x * A + B * p.y + C)) / sqrt(pow(A, 2) + pow(B, 2));
    return d;
}


// 获取内部矩形
std::vector<cv::Point> ministDistanceToLine(cv::Mat outsideBox, std::vector<cv::Point> contours, int threshold)
{
    std::vector<cv::Point> crossEndPoints;
    for (int i = 0; i < 2; i++)
    {
        cv::Point line1[2] = {cv::Point(outsideBox.at<float>(i, 0), outsideBox.at<float>(i, 1)), cv::Point(outsideBox.at<float>(i + 1, 0), outsideBox.at<float>(i + 1, 1))};
        cv::Point line2[2] = {cv::Point(outsideBox.at<float>(i + 2, 0), outsideBox.at<float>(i + 2, 1)), cv::Point(outsideBox.at<float>((i + 3)%4, 0), outsideBox.at<float>((i + 3)%4, 1))};
        cv::Point center1 = cv::Point((line1[0].x + line1[1].x) / 2, (line1[0].y + line1[1].y) / 2);
        cv::Point center2 = cv::Point((line2[0].x + line2[1].x) / 2, (line2[0].y + line2[1].y) / 2);

        std::vector<std::vector<cv::Point>> dividedPoints(2);
        for (int j = 0; j < contours.size(); j++)
        {
            cv::Point line[2] = {center1, center2};
            if (distanceOfP2L(line, contours[j]) < threshold)
            {
                if (dividedPoints[0].empty())
                {
                    dividedPoints[0].push_back(contours[j]);
                    continue;
                }
                cv::Point delegateOfList1 = dividedPoints[0][0];
                if (pow(delegateOfList1.x - contours[j].x,2) + pow(delegateOfList1.y - contours[j].y,2) < pow(2 * threshold, 2))
                    dividedPoints[0].push_back(contours[j]);
                else
                    dividedPoints[1].push_back(contours[j]);
            }
        }

        for (int i = 0; i < dividedPoints.size(); i++)
        {
            double x = 0;
            double y = 0;
            for (int j = 0; j < dividedPoints[i].size(); j++)
            {
                x += dividedPoints[i][j].x;
                y += dividedPoints[i][j].y;
            }
            crossEndPoints.push_back(cv::Point(x/dividedPoints[i].size(), y/dividedPoints[i].size()));
        }
    }

    return crossEndPoints;

}
