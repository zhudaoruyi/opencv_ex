#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
int main(int argc, char** argv) {
	Mat src = imread("D:/ex/vsprojects/test_opencv_install/test.jpg");
	if (src.empty())
	{
		printf("�򲻿��ļ�...\n");
		return -1;
	}
	namedWindow("����opencv��װ���", WINDOW_AUTOSIZE);
	imshow("����opencv��װ���", src);

	waitKey(0);
	return 0;
}