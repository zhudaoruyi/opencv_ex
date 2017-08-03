#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;

int main()
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/tuxiangfushi/cat.jpg");
	// show origin image 
	imshow("��ԭͼ����ʴ����", srcImage);
	// ����ʴ��������
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	// show result
	imshow("��Ч��ͼ����ʴ����", dstImage);
	waitKey(0);
	return 0;
}