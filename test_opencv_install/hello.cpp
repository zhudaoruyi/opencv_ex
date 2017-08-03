#include <opencv2\opencv.hpp>
using namespace cv;

int main()
{
	// 读入一张图片
	Mat img = imread("D:/ex/vsprojects/test_opencv_install/test01.png");
	// 在窗口中显示该图片
	imshow("【测试图片，By Randy】", img);
	// 等待6000 ms后窗口自动关闭
	waitKey(6000);
}