enum Shape { UNKNOWN, CIRCLE, COIN, STAR, HEART, MEIHUA, PEACH };

class DetectResult
{
public:
	DetectResult() {};

public:
	bool detected = false;  // ͼƬ���Ƿ���ڹ�����
	unsigned char* originalPicData = 0;  // ԭʼͼƬ
	unsigned char* detectedPicData = 0;  // ����ͼƬ
	bool status = false;  // ���״̬
	double detectArea = 0;  // 覴���
	unsigned int cost = 0;  // ����ʱ
	Shape shape = Shape::UNKNOWN;  // ���ͼ��
	unsigned int width = 0;  // ͼƬ���
	unsigned int height = 0;  // ͼƬ�߶�
};

void filterDefectDetect(DetectResult* result);