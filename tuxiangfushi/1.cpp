#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;

int main()
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/tuxiangfushi/cat.jpg");
	// show origin image 
	imshow("【原图】腐蚀操作", srcImage);
	// 做腐蚀操作命令
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	// show result
	imshow("【效果图】腐蚀操作", dstImage);
	waitKey(0);
	return 0;
}