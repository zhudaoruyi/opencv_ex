#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
using namespace cv;

int main()
{
	// ͼ����������ʾ
	Mat girl = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/3.png");
	namedWindow("��1������ͼ");
	imshow("��1������ͼ", girl);

	// ����ͼ���ϣ�����ͼƬ
	Mat image = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/1.png");
	Mat logo = imread("D:/ex/vsprojects/test_opencv_install/tuxiangzairuxianshishuchu/2.png");
	// �������ʾ
	namedWindow("��2��ԭͼƬ");
	imshow("��2��ԭͼƬ", image);

	namedWindow("��3��logoͼ");
	imshow("��3��logoͼ", logo);

	// ����һ��Mat���ͣ����ڴ��ͼ���ROI
	Mat imageROI;
	// ����һ
	imageROI = image(Rect(12, 100, logo.cols, logo.rows));
	// ������
	//imageROI = image(Range(100, 100 + logo.rows), Range(80, 80 + logo.cols));

	// ��logo�ӵ�ԭͼ��
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);

	// ��ʾ���
	namedWindow("��4��ԭ��+logoͼ");
	imshow("��4��ԭ��+logoͼ", image);

	// ͼ������
	imwrite("��imwrite����ͼƬ.jpg", image);
	waitKey();
	return 0;
}