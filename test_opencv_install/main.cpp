#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("D:/ex/vsprojects/test_opencv_install/test.jpg");
	if (src.empty())
	{
		printf("打不开文件...\n");
		return -1;
	}
	namedWindow("测试opencv安装情况", WINDOW_AUTOSIZE);
	imshow("测试opencv安装情况", src);

	waitKey(0);
	return 0;
}