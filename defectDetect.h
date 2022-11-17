enum Shape { UNKNOWN, CIRCLE, COIN, STAR, HEART, MEIHUA, PEACH };

class DetectResult
{
public:
	DetectResult() {};

public:
	bool detected = false;  // Í¼Æ¬ÖÐÊÇ·ñ´æÔÚ¹ýÂË×ì
	unsigned char* originalPicData = 0;  // Ô­Ê¼Í¼Æ¬
	unsigned char* detectedPicData = 0;  // ¼ì²âºóÍ¼Æ¬
	bool status = false;  // ¼ì²â×´Ì¬
	double detectArea = 0;  // è¦´ÃÁ¿
	unsigned int cost = 0;  // ¼ì²âºÄÊ±
	Shape shape = Shape::UNKNOWN;  // ¼ì²âÍ¼ÐÎ
	unsigned int width = 0;  // Í¼Æ¬¿í¶È
	unsigned int height = 0;  // Í¼Æ¬¸ß¶È
};

void filterDefectDetect(DetectResult* result);