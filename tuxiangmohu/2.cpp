//...............【头文件、命名空间包含部分】................
//           描述：包含程序所使用的头文件和命名空间
//-----------------------------------------------------------
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

//----------------【main()函数】-----------------------------
// 描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------
int main()
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/tuxiangmohu/cat.jpg");
	// show origin image
	imshow("均值滤波【原图】", srcImage);
	// do blur
	Mat dstImage;
	blur(srcImage, dstImage, Size(5, 5));
	// show result
	imshow("均值滤波【效果图】", dstImage);
	waitKey(0);
}