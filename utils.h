#ifndef UTILS_H
#define UTILS_H
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QImage>

void KMeans(std::vector<cv::Point> tuples, cv::Point* means);

QImage mat2QImage(cv::Mat &matImg, int count);

float distanceOfP2L(cv::Point line[2], cv::Point p);

std::vector<cv::Point> ministDistanceToLine(cv::Mat outsideBox, std::vector<cv::Point> contours, int threshold = 100);

float lineAngle(cv::Vec4i line);

cv::Point lineVector(cv::Vec4i line);

bool starVertexCompare(const cv::Point2f &a, const cv::Point2f &b);

#endif // UTILS_H
