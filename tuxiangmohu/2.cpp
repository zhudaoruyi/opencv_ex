//...............��ͷ�ļ��������ռ�������֡�................
//           ����������������ʹ�õ�ͷ�ļ��������ռ�
//-----------------------------------------------------------
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

//----------------��main()������-----------------------------
// ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------
int main()
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/tuxiangmohu/cat.jpg");
	// show origin image
	imshow("��ֵ�˲���ԭͼ��", srcImage);
	// do blur
	Mat dstImage;
	blur(srcImage, dstImage, Size(5, 5));
	// show result
	imshow("��ֵ�˲���Ч��ͼ��", dstImage);
	waitKey(0);
}