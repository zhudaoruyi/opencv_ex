#include <opencv2\opencv.hpp>
using namespace cv;

int main()
{
	// ����һ��ͼƬ
	Mat img = imread("D:/ex/vsprojects/test_opencv_install/test01.png");
	// �ڴ�������ʾ��ͼƬ
	imshow("������ͼƬ��By Randy��", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�
	waitKey(6000);
}