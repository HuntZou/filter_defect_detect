#ifndef DETECT_H
#define DETECT_H
#include "utils.h"

enum Shape { UNKNOWN, HEART_SMALL, HEART_BIG, COIN, WINTERSWEET_SMALL, WINTERSWEET_BIG, RAY, STAR, CIRCLE, PEACH };

class DetectResult
{
public:
    DetectResult() {};
public:
    bool detected = false;  // 图片中是否存在过滤嘴
    //cv::Mat detectedPic;  // 检测后图片
    bool status = false;  // 检测状态
    double defectArea = 0;  // 瑕疵量
    unsigned int cost = 0;  // 检测耗时
    unsigned int width = 0;  // 图片宽度
    unsigned int height = 0;  // 图片高度

    // 额外检测参数
    // 如果检测图形是铜币形，则该参数分别代表内外两个矩形的四条边长
    // 如果检测图形是五角星形，则该参数代表其五个角度
    std::vector<double> extraDoubleData;
};

class DetectCfg
{
public:
    DetectCfg(Shape shape = Shape::UNKNOWN, int outlineGrayThreshold=132, int resize=800): shape(shape), outlineGrayThreshold(outlineGrayThreshold), resize(resize){};
    Shape getShape() const {return shape;}
    int getOutlineGrayThreshold() const {return outlineGrayThreshold;};
    int getResize() const {return resize;}

private:
    Shape shape;
    int outlineGrayThreshold;
    int resize;
};

void filterDefectDetect(cv::Mat &image, DetectResult &result, DetectCfg detectCfg = DetectCfg(), int count=-1);
std::string shapeToString(Shape shape);


#endif // DETECT_H
