// 利用opencv进行canny边缘检测。
// 载入图像，并将其转成灰度图，再用blur函数进行图像模糊以降噪，
// 然后用canny函数进行边缘检测，最后显示。

#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv; //包含CV命名空间

int main() 
{
	// load image
	Mat srcImage = imread("D:/ex/vsprojects/test_opencv_install/canny_bianyuanjiance/2.jpg");
	imshow("【原始图】canny边缘检测", srcImage);
	Mat dstImage, edge, grayImage; //声明参数，定义参数

	// 创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage.size(), srcImage.type());

	//将原始图转换为灰度图
	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

	//先使用3X3内核来降噪
	//blur(grayImage, edge, Size(10, 10));

	//运行canny算子
	Canny(edge, edge, 6, 20, 3);

	//显示效果
	imshow("【效果图】canny边缘检测", edge);
	waitKey(0);
	return 0;
}